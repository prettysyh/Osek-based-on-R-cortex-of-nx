/*
 * MY_Task.c
 *
 *  Created on: Jul 16, 2019
 *      Author: Jerry
 */


/******************** Task body *******************/
#include "Platform_Lib.h"
#include "Os_Task.h"
#include "aaa_print.h"

/* 低优先级任务，保留*/
TASK(OsTask_0)
{
    int count = 0;
    while (1)
    {
        count++;
        print_char("task0...\r\n");
        if(count == 10) break;
    }
    
    DEFINECRITICAL();
//    PKG_Print(_TRACE, "task 0 start\r\n");
//    PKG_Print(_TRACE, "task 1 end\r\n");
    (void) TerminateTask();
}

/* 低优先级任务，传感器数据读取 */
TASK(OsTask_1)
{
    DEFINECRITICAL();
    print_char("task1...\r\n");
   (void) TerminateTask();
}

/* 安全处理处理底盘时间，优先级较高 */
TASK(OsTask_2)
{
    

    DEFINECRITICAL();
    print_char("task2...\r\n");
    (void) TerminateTask();
}


/* 车辆控制，优先级最高 */
TASK(OsTask_3)
{
    DEFINECRITICAL();
    print_char("task3...\r\n");
   (void) TerminateTask();
}

/* 通信管理 */
TASK(OsTask_4)
{

    DEFINECRITICAL();
    print_char("task4...\r\n");
    (void) TerminateTask();
}

/* 车辆配置*/
TASK(OsTask_5)
{

    DEFINECRITICAL();
    print_char("task5...\r\n");
    (void) TerminateTask();
}

TASK(OsTask_6)
{

    DEFINECRITICAL();
    print_char("task6...\r\n");
    (void) TerminateTask();
}

