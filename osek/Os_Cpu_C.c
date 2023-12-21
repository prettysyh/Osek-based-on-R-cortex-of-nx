/*
*********************************************************************************
* Copyright (c) 2011,Embedded System Engineering Center of  Zhejiang University
* All rights reserved.
*
* FILE NAME: Os_Cpu_C.c
* DESCRIPTION: Stack Init, DEC Init
* UPDATE HISTORY
* REV      AUTHOR            DATE       DESCRIPTION OF CHANGE                         
* 1.0      xiwen.guo         07/MAR/05   Initial version.   
*
*********************************************************************************
*/
#include "Os.h"
#include "aaa_print.h"
#include "stdio.h"

extern  TaskType  OSTCBOld;
extern  OsTask    OSTaskCfgTbl[];
extern  uint8     ReadyList0[];
extern  uint32    MaxCrossTime;
/**********************************************************************
* Function Prototype: void  OSTaskInit()
* Service ID: 
* Sync/Asyn: 
* Re-Entrancy: 
* Parameters description
*    (in): None
*    (out): None
* Return Value: None
* Caller: StartOS
* Call Function: 
* Description: Initialize OsTask module
* Author: Jiang Li
* Time: 2005.7.5
***************************************************************************
*/
void OSTaskInit()
{
    TaskType Tcb; 
    uint8 index = 1U ,*ReadyListPtr;
    PriorityType tmp_OrigPrio;
    uint16 pos;
#if (OS_APPLICATION_MODULE == STD_ON )
    uint16 AppID;
#endif
           
#if (OS_TASK_NUM > 0U)
    OsTask *TcbCfg = OSTaskCfgTbl;
#endif /*OS_TASK_NUM>0*/

    INIT_RDY_TBL(); /*ready list initialization*/

    /*creat idle task*/
    Tcb = &OSTCBTbl[0];
    SET_TASK_PROPERTY(Tcb, FULL_SCHED | AUTO_START);
    SET_TASK_ENTRY(Tcb, OSTaskIdle);

    SET_TASK_STK(Tcb, &OSTaskIdleStk[OS_TASK_IDLE_STK_SIZE - 2U], OSTaskIdleStk);  

    SET_TASK_ID(Tcb, 0U);
    INIT_IDLE_READY_LIST(0U);
    SET_PRIO_MASK(ReadyListCBTbl,0U);    

    IDLE_READY(Tcb); 
    
#if (OS_TASK_NUM > 0U)
    /*initialization of ReadyListCB*/
    for(; index <= OS_MAX_TASK_PRIO; index++)
    {
        INIT_READY_LIST(index);
        SET_PRIO_MASK(&ReadyListCBTbl[index],index);
    }
         
    for (index = 1U; index < OS_NUM_SYS_TASK; index++)      
    {/*set the task information of all tasks*/
        tmp_OrigPrio = TcbCfg->OsTaskPriority;
    
        Tcb = OSTCBTbl + index;     
       
        SET_TASK_ID(Tcb, index);
        SET_TASK_PROPERTY(Tcb, 0U);
        SET_TASK_ORIGINAL_PRIO(Tcb,tmp_OrigPrio);
#if (OS_RESOURCE_MODULE == STD_ON)
#if (OS_RES_INTERNAL == STD_ON)
        if(TcbCfg->RunPrio != INVALID_RESOURCE_PRIO)
        {
            Tcb->InfoBit |=HOLD_INT_RES;
            SET_TASK_RUNNING_PRIO(Tcb,TcbCfg->RunPrio);
        }
        else
        {  
            SET_TASK_RUNNING_PRIO(Tcb,tmp_OrigPrio);
        }
#else
        SET_TASK_RUNNING_PRIO(Tcb,tmp_OrigPrio);
#endif
#endif 
    
        SET_TASK_ENTRY(Tcb, TcbCfg->PTask);
        CLEAR_TASK_EVENT(Tcb);
          
        SET_TASK_STK(Tcb, TcbCfg->PStkHigh, TcbCfg->PStkLow);
        
        SET_TASK_MAX_ACT(Tcb,TcbCfg->OsTaskActivation);
        SET_TASK_CUR_ACT(Tcb,0U);
  
        if(FULL_SCHED==TcbCfg->TaskSchedule)
        {
            Tcb->InfoBit|=FULL_SCHED;         
        }
        
        if(TcbCfg->OsTaskEventRef!=0U)
        {
            Tcb->InfoBit|=EXTENDED;         
        }
        
#if (OS_PROTECTION_HOOK == STD_ON)
        Tcb->InfoBit2=0;
#endif
        
        SET_TASK_EVENT_LIST(Tcb,TcbCfg->OsTaskEventRef);
        SET_TASK_RESOURCE_LIST(Tcb,TcbCfg->OsTaskResourceRef);
        
#if (OS_APPLICATION_MODULE == STD_ON )
        Tcb->OsTaskAccessingApplication = TcbCfg->OsTaskAccessingApplication;
        AppID = OSCheckObjectOwnership(OBJECT_TASK,index);
        Tcb->OsTaskOwnershipApp = AppID;  
#endif     /*timing protection*/
       
#if ( OS_TIMING_PROTECTION_MODULE ==  STD_ON)
#if (OS_APPLICATION_MODULE == STD_ON )
        if(FALSE == ApplicationCB[AppID].OsTrusted || TRUE == ApplicationCB[AppID].TimingProtection) 
        {               
            Tcb->OsTaskExecutionBudget = (TcbCfg->TaskTimingProtection.OsTaskExecutionBudget) * OS_TICKS_PER_SEC ;  /*TODO,when trusted APP is enable, it should have timing protection module*/
            Tcb->RemainingExecutionBudget = Tcb->OsTaskExecutionBudget; /*TODO*/
            Tcb->OsTaskTimeFrame = (TcbCfg->TaskTimingProtection.OsTaskTimeFrame) * OS_TICKS_PER_SEC; /*TODO*/
            Tcb->TimeFrameStart = 0U;/*TODO*/
            Tcb->CrossNum = MaxCrossTime;                 
            Tcb->OsTaskResourceLock =TcbCfg->TaskTimingProtection.OsTaskResourceLock;  /*Resource Lock*/
        }
#endif
#endif 
       
        if (((TcbCfg->Autostart) ==TRUE)&&((TcbCfg->TaskAutostartMode.OsTaskAppModeRef & (ActiveAppMode))!=0U))
        {/*AUTOSTART TASK*/           
         /*increase the activation time */
            INC_TASK_CUR_ACT(Tcb);
            SET_TASK_READY(tmp_OrigPrio, Tcb);
            INSERT_READY_LIST_REAR(index, tmp_OrigPrio);
#if ( OS_TIMING_PROTECTION_MODULE ==  STD_ON)
            Tcb->InfoBit |= TASKHAVERUN;
#endif
        }
        else
        {
            SET_TASK_STATUS(Tcb, SUSPENDED);
        }
        TcbCfg++;
        // printf("tcbid:%d tcbadd:%p\r\n",Tcb->OSTCBId,Tcb->PTask);

    }
#endif /*OS_TASK_NUM>0*/
}
/**********************************************************************
* Function Prototype: OSSTK *OSTaskStkInit (void (*task)(void), OSSTK *ptos)
* Service ID: 
* Sync/Asyn: Asyn
* Re-Entrancy: YES
* Parameters description
*    (in): task: the task that needs to init stack; ptos: the stack pointer of the task
*    (out): 
* Return Value: 
* Caller: SET_TASK_READY
* Call Function: 
* Description: Init the stack of the Corresponding task
* Author: Hao Jie Chen
* Time: 07/MAR/11
***************************************************************************
*/
__attribute__( ( always_inline ) ) static inline unsigned long _get_CPSR(void)
{
unsigned long result;

	__asm volatile ("MRS %0, cpsr" : "=r" (result) );
	return(result);
}

OSSTK *OSTaskStkInit(void(*task)(void), OSSTK *ptos)
{
	OSSTK *stk;
    stk = ptos;                                           /* Load stack pointer                                 */

    print_char("ptos is ::");
    print_reg((unsigned long )ptos);
    print_char("task is ::");
    print_reg((unsigned long )task);

    *(stk) = (uint32)task + 0x04;                           /* return address (has a offset of 4B)                                  */
    *(--stk) = (uint32)ptos-60;									/* Entry Point R14 (LR)?                                               */
    *(--stk) = (uint32)ptos;                                /* Stack used when task starts goes in R13                     */

    *(--stk) = (uint32)0x12121212u; 							/* R12                                                    */
    *(--stk)  = (uint32)0x11111111u;          	 /* R11                                                */
    *(--stk)  = (uint32)0x10101010u;            /* R10                                                */
    *(--stk)  = (uint32)0x09090909u;            /* R9                                                 */
    *(--stk)  = (uint32)0x08080808u;            /* R8                                                 */
    *(--stk)  = (uint32)0x07070707u;            /* R7                                                 */
    *(--stk)  = (uint32)0x06060606u;            /* R6                                                 */
    *(--stk)  = (uint32)0x05050505u;            /* R5                                                 */
    *(--stk)  = (uint32)0x04040404u;            /* R4                                                 */
    *(--stk) = (uint32)0x03030303u; 							/* R3                                                     */
    *(--stk) = (uint32)0x02020202u;								/* R2                                                     */
    *(--stk) = (uint32)0x01010101u; 							/* R1                                                     */
    *(--stk) = (uint32)0x12345678u; 							/* R0 : argument                                          */

    // *(--stk) = (uint32)0x01000000u;								/* xPSR                                                   */
	
    *(--stk) = ( uint32_t ) ( ( _get_CPSR() & ~0xFF ) | ( ( uint32_t ) 0x1f ) );

    print_char("finish is :");
    print_reg((unsigned long )stk);  

    return (stk);
}