#include "aaa_semphr.h"
// #include "aaa_type.h"
#include "aaa_queue.h"
#include "Os.h"

void InitSem(SemHandle s)
{
    s->count = 0;
    s->WaitIndex.head = 0;
    s->WaitIndex.tail = 0;
}

bool GiveSem(SemHandle s){
    TaskType curTcb = NULL,ptcb = NULL;
    uint8 *ReadyListPtr;
    uint16 pos,AppID;
    TaskIdType taskid;
    int waitnum =0;

    if (s->count == 0) return false;

    ENTER_CRITICAL();

    if (WAIT_JUDGE(s))
    {
        pop(&(s->WaitIndex),&taskid,sizeof(TaskIdType));

        ptcb = &OSTCBTbl[taskid];
        SET_TASK_STATUS(ptcb, RUN_READY); /*if the event set is the event the task waiting for,change the state of the task to READY*/
        OS_TASK_TO_READY(GET_TASK_ORIGINAL_PRIO(ptcb), ptcb);
        INSERT_READY_LIST_REAR(GET_TASK_ID(ptcb), GET_TASK_ORIGINAL_PRIO(ptcb));

    }

    s->count--;

    EXIT_CRITICAL();
    return true;

}

bool TakeSem(SemHandle s){
    TaskType curTCB = NULL,ptcb = NULL;
    uint8 *ReadyListPtr,highestPrio;
    uint16 pos;
    uint8 CurPrio;

    s->count++;


    ENTER_CRITICAL();

    curTCB = OSTCBCur;
    if (WAIT_JUDGE(s))
    {
        push(&(s->WaitIndex), (void*)(&curTCB->OSTCBId), sizeof(uint8));

        /*if the wait event is not set, start a schedule*/
        RELEASE_INT_RES(curTCB); /*Release the Resource,not take timing protection into consideration*/        
        OSPostTaskHook();
        CurPrio = GET_TASK_ORIGINAL_PRIO(curTCB);
        /*delete the tcb from the head of ready list*/
        REMOVE_READY_LIST_HEAD(CurPrio);
        
          
        /*Set the ready status table*/
        SET_TASK_UNREADY(GET_TASK_ORIGINAL_PRIO(curTCB), curTCB, WAITING); /*Change the status of the task to WAITING*/ 
        #if (OS_TIMING_PROTECTION_MODULE ==  STD_ON) 
           curTCB->RemainingExecutionBudget = curTCB->OsTaskExecutionBudget;//Reset the time of RemainingExecutionBudget
        #endif
        SET_TASK_OLD(curTCB);
        /*find the task with the highest priority, start a schedule*/
        
        highestPrio = OS_FIND_HIGHEST_TASK();                                  /*find the task with the highest priority among the tasks in Ready status*/
        ReadyListPtr=ReadyListCBTbl[highestPrio].head    ; /*Point to the Readylist with highest priority*/
     
        OSTCBCur=ptcb=&OSTCBTbl[*(ReadyListPtr+ReadyListCBTbl[highestPrio].start)];/*Update OSTCBCur*/
        GET_INT_RES(ptcb); /*Get internal resource*/
        
        OSPreTaskHook(); /*Call PreTaskHook*/
        OSStackMonitoring(curTCB);
        if (RUN_READY != GET_TASK_STATUS(ptcb))
        {
             /*If the task hasn't ever run once*/
            SET_TASK_STATUS(ptcb, RUN_READY); /*Set the status*/
            OSTaskSaveRun(curTCB, ptcb);
        }
        else
        {
            OSTaskSaveLoadRun(curTCB, ptcb);
        }
      
    }

    EXIT_CRITICAL();

    return true;
}