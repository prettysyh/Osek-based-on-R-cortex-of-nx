/*
 *********************************************************************************
 * Copyright (c) 2011,Embedded System Engineering Center of  Zhejiang University
 * All rights reserved.
 *
 * FILE NAME: IntHandler.c
 * DESCRIPTION:
 * UPDATE HISTORY
 * REV      AUTHOR      DATE       DESCRIPTION OF CHANGE
 * 1.0       ESE       07/MAR/11   Initial version.
 *
 *********************************************************************************
 */

#include "IntHandle.h"
#include "aaa_print.h"
#include "stdio.h"

#if (OS_INTERRUPT_MODULE == STD_ON)

extern bool yield_required;

void OSIntExit(void)
{
    // print_char("get in exit\r\n");
    TaskType ptcb = NULL;
    TaskType oldRunning = NULL;
    uint8 *ReadyListPtr;
    uint8 highestPrio;
    if (--IntNesting == 0)
    {
#if (OS_SCHEDULE_POLICY != OS_SCHEDULE_FULL)
#if (OS_SCHEDULE_POLICY == OS_SCHEDULE_MIX)
        if (FULL_SCHED != GET_TASK_SCHED(OSTCBCur))
        {
            // print_char("return1\r\n");
            //need change chen add
            return; /*Task not support SCHED_METHOD*/
        }
#else
        if (0 != GET_TASK_ORIGINAL_PRIO(OSTCBCur))
        { /*if TASK is idle task, it needs schedule new task.*/
            print_char("return2\r\n");
            return; /*Task not support SCHED_METHOD*/
        }
#endif /*#ifdef OS_MIX_SCHEDULE*/
#endif /*#ifndef OS_FULL_SCHEDULE*/
        // print_char("finding..\r\n");
        oldRunning = OSTCBCur;
        highestPrio = OS_FIND_HIGHEST_TASK(); /*Find the highest Priority task who is ready to run*/
        ReadyListPtr = ReadyListCBTbl[highestPrio].head; /*Find the task TCB*/
        ptcb = &OSTCBTbl[*(ReadyListPtr + ReadyListCBTbl[highestPrio].start)];/*update OSTCBCur*/
        // printf("highestPrio_taskid:%d\r\n",*(ReadyListPtr+ReadyListCBTbl[highestPrio].start));
        // printf("current_taskid:%d\r\n",OSTCBCur->OSTCBId);

        //print_char("testing highestprio and ptr :");


        //print_reg(highestPrio);
        if (ptcb != oldRunning)
        {
            print_char("find new task!!\r\n");
            printf("current_taskid:%d\r\n",ptcb->OSTCBId);
            // needchange=0;
            /*
            /*preempt by the higher Priority task*/
            // RELEASE_INT_RES(oldRunning); //OS223:Points of rescheduling
            OS_TASK_SWITCH(oldRunning); OSPostTaskHook(); /*when task is preempted ��call PostTaskHook*/
            OSTCBCur = ptcb;
            
            yield_required = true;

            OSPreTaskHook(); /*call PreTaskHook*/
            OSStackMonitoring(oldRunning);
            
           if (RUN_READY != GET_TASK_STATUS(ptcb)) {
                SET_TASK_STATUS(ptcb, RUN_READY); /*set task to ready who is the first time to run*/
                SET_TASK_STK_INIT(ptcb);
           }

//#if (OS_EVENT_MODULE == STD_ON)
//            if (RUN_READY != GET_TASK_STATUS(ptcb))
//#endif /*#ifdef  OS_EVENT_EN*/
 //           {
 //               print_char("running new task!!\r\n");
  //              SET_TASK_STATUS(ptcb, RUN_READY); /*set task to ready who is the first time to run*/
  //              OSTaskSaveRun(oldRunning, ptcb);
  //          }
//#if (OS_EVENT_MODULE == STD_ON)
   //         else
   //         {
   //             OSTaskLoadRun(ptcb);
  //          }
//#endif /*#ifdef  OS_EVENT_EN*/
        }
        else {
            // print_char("NF\r\n");

        }

    }
    // print_char("EX\r\n");
}

void ChangingOsFromEl0(void)
{
     TaskType ptcb = NULL;
    TaskType oldRunning = NULL;
    uint8 *ReadyListPtr;
    uint8 highestPrio;

        oldRunning = OSTCBCur;
        highestPrio = OS_FIND_HIGHEST_TASK(); /*Find the highest Priority task who is ready to run*/
        ReadyListPtr = ReadyListCBTbl[highestPrio].head; /*Find the task TCB*/
        ptcb = &OSTCBTbl[*(ReadyListPtr + ReadyListCBTbl[highestPrio].start)];/*update OSTCBCur*/
            /*preempt by the higher Priority task*/
            // RELEASE_INT_RES(oldRunning); //OS223:Points of rescheduling
        OSTCBCur = ptcb;

#if (OS_EVENT_MODULE == STD_ON)
            if (RUN_READY != GET_TASK_STATUS(ptcb))
#endif /*#ifdef  OS_EVENT_EN*/
            {
                SET_TASK_STATUS(ptcb, RUN_READY); /*set task to ready who is the first time to run*/
                OSTaskSaveRun(oldRunning, ptcb);
            }
#if (OS_EVENT_MODULE == STD_ON)
            else
            {
                OSTaskLoadRun(ptcb);
            }
#endif /*#ifdef  OS_EVENT_EN*/
        
}

#endif /* #if (OS_INTERRUPT_MODULE == STD_ON) */

