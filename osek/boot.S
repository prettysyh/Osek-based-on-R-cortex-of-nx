#include "address_map_new.h"
#include "arclk_rst.h"

.extern main
.extern _Undefined_Instruction_Handler
.extern _Data_Abort_Handler
.extern _Prefetch_Abort_Handler
.extern vPortYieldProcessor
.extern cache_enable

.extern _svcstack
.extern _fiqstack
.extern _irqstack
.extern _abtstack
.extern _undstack

.section .vectors
    B   _reset_handler                 
    B   _Undefined_Instruction_Handler 
    B   vPortYieldProcessor            
    B   _Prefetch_Abort_Handler        
    B   _Data_Abort_Handler            
    B   _dummy_handler                 
    B   _irq_handler                   
    B   _irq_handler      	       

.section .text

_irq_handler:
    B  _irq_handler

_dummy_handler:
    B  _dummy_handler

_reset_handler:
@==================================================================
@ Disable MPU and cache in case it was left enabled from an earlier run
@ This does not need to be done from a cold reset
@==================================================================

    MRC     p15, 0, r0, c1, c0, 0       @ Read CP15 Control Register
    BIC     r0, r0, #0x05               @ Disable MPU (M bit) and data cache (C bit)
    BIC     r0, r0, #0x1000             @ Disable instruction cache (I bit)
    DSB                                 @ Ensure all previous loads/stores have completed
    MCR     p15, 0, r0, c1, c0, 0       @ Write CP15 Control Register
    ISB                                 @ Ensure subsequent insts execute wrt new MPU settings

@==================================================================
@ Init Stack pointer
@==================================================================
    MSR     cpsr_c, #0xD1       @FIQ
    LDR     sp, =_fiqstack
    MSR     cpsr_c, #0xD2       @IRQ
    LDR     sp, =_irqstack
    MSR     cpsr_c, #0xD7       @ABT
    LDR     sp, =_abtstack
    MSR     cpsr_c, #0xDB       @UND
    LDR     sp, =_undstack
    MSR     cpsr_c, #0xD3       @SVC
    LDR     sp, =_svcstack

@==================================================================
@ Setup Frame Pointers. Zero out ARM and Thumb frame pointers.
@==================================================================
    MOV     a2, #0
    MOV     fp, a2
    MOV     r7, a2

@==================================================================
@ Enable Branch prediction
@==================================================================

    MRC     p15, 0, r0, c1, c0, 1       @ Read ACTLR
    BIC     r0, r0, #(0x1 << 17)        @ Clear RSDIS bit 17 to enable return stack
    BIC     r0, r0, #(0x1 << 16)        @ Clear BP bit 15 and BP bit 16:
    BIC     r0, r0, #(0x1 << 15)        @ Normal operation, BP is taken from the global history table.
    MCR     p15, 0, r0, c1, c0, 1       @ Write ACTLR

@==================================================================
@ Enable VFP
@==================================================================

    MRC     p15, 0, r0, c1, c0, 2
    ORR     r0, r0, #(0xF << 20)
    MCR     p15, 0, r0, c1, c0, 2
    ISB
    MOV     r0, #0x40000000
    VMSR    FPEXC, r0

@==================================================================
@ Configure VIC to provide handler addr for IRQ
@==================================================================
    MRC     p15, 0, r0, c1, c0, 0       @ read CP15 register 1
    ORR     r0, r0, #(0x1 << 24)        @ Configure VIC to provide handler addr for IRQ
    MCR     p15, 0, r0, c1, c0, 0       @ write CP15 register 1

@==================================================================
@ Enable asynchronous aborts
@==================================================================
    CPSIE A

@==================================================================
@ Enable Caches
@==================================================================
    BL      cache_enable

@==================================================================
@ Clear BSS
@==================================================================
    LDR	    R1, _sbss_val
    LDR	    R2, _ebss_val
    SUBS    R2, R2, R1 /* END-START = LENGTH */
    BEQ	    _clear_bss_end
    MOV	    R0, #0
_clear_bss_loop:
    STR	    R0, [R1], #4
    SUBS    R2, R2, #4
    BGT	    _clear_bss_loop
_clear_bss_end:

@==================================================================
@ Jump to Reset Handler
@==================================================================
    BLX     main

_loop:
   B	    _loop

_sbss_val:
	.word	_sbss
_ebss_val:
	.word	_ebss

