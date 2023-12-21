 .global OSTCBCur
 .global OSTCBOld

 .global FirstTaskRun
 .global TaskSaveLoadRun
 .global TaskSaveRun
 .global TaskLoadRun
 .global TaskRun
 .global PendSV_Handler
 .global CPU_SR_Save
 .global CPU_SR_Restore
 .global irq_end
 .type PendSV_Handler, %function
 .type CPU_SR_Save, %function
 .type CPU_SR_Restore, %function

 .global vPortYieldProcessor

 .extern OSTCBStkCur
 .extern SystemSTKTopPtr
 .extern OSTCBCur
 .extern print_all
 .extern print_stk
 .extern print_reg
 .extern vTaskSwitch

.macro print
    b 0xfffffffc
.endm

.macro portSAVE_CONTEXT
    @print
    STMDB   SP!, {R0}

    /* Set R0 to point to the task stack pointer.*/
    STMDB   SP,{SP}^
    SUB     SP, SP, #4
    
    LDMIA   SP!,{R0}

    /* Push the return address onto the stack. */
    STMDB   R0!, {LR}

    /* Now LR has been saved, it can be used instead of R0.*/
    MOV     LR, R0

    /* Pop R0 so it can be saved onto the task stack.*/
    LDMIA   SP!, {R0}

    /* Push all the system mode registers onto the task stack.*/
    STMDB   LR,{R0-LR}^
    SUB     LR, LR, #60

    /* Push the SPSR onto the task stack.*/
    MRS     R0, SPSR
    STMDB   LR!, {R0}

    /* Store the new top of stack for the task.*/
    LDR     R0, =OSTCBOld
    LDR     R0, [R0]
    STR     LR, [R0]
.endm

.macro mode_change
    MRS R10, CPSR          @将 CPSR 寄存器的值读取到 R0
    BIC R10, R10, #0x1F     @清除 CPSR 的低5位（模式位）
    ORR R10, R10, #0x13     @设置为 SVC 模式的值（0x13）
    MSR CPSR_c, R10       @更新 CPSR 寄存器
.endm

vPortYieldProcessor:
    ADD     LR, LR, #4
    STMFD SP!, {R0-R12, LR} 
    LDR R4, [LR, #-8]
    BIC R4, R4, #0xFF000000 
    CMP R4, #1
    BNE 1f

    LDMIA     SP!, {R0-R12, LR} 
    portSAVE_CONTEXT
1:
    B portRESTORE_CONTEXT



portRESTORE_CONTEXT:
FirstTaskRun:
    LDR     R0, =OSTCBCur
    LDR     R0, [R0]
    LDR     LR, [R0]

    /* Get the SPSR from the stack.*/
    LDMFD   LR!, {R0}

    MSR     spsr_csxf, R0

    /* Restore all system mode registers for the task.*/
    LDMFD   LR, {R0-R14}^

    /*  Restore the return address.*/
    LDR     LR, [LR, #+60]

    /* And return - correcting the offset in the LR to obtain the*/
    /* correct address. */

    SUBS    PC, LR, #4

OSStartHang:
    B       OSStartHang

CPU_SR_Save:
    cpsid i
    BX LR

CPU_SR_Restore:
    cpsie i
    BX LR

irq_end:
    LDR     R1, =yield_required
    LDR     R0, [R1]
    CMP     R0, #0
    BNE     irq_end_with_context_switch
    POP     { R0-R3, IP, LR }

    SUBS    PC, LR, #4

irq_end_with_context_switch:
    /* Clear context swtich pending flag. */
    MOV     R0, #0
    STR     R0, [R1]
    POP     { R0-R3, IP, LR }
    

    /* Save the context of the old task.*/
    portSAVE_CONTEXT

    b   portRESTORE_CONTEXT