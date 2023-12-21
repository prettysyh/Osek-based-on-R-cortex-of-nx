/*
 * Copyright (c) 2014-2019, NVIDIA CORPORATION. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <FreeRTOS.h>
#include <semphr.h>

#include <address_map_new.h>
#include <arm-vic.h>
#include <arclk_rst.h>
#include <araopm.h>
#include <clk-tegra.h>
#include <cache.h>
#include <delay.h>
#include <err-hook.h>
#include <irqs.h>
#include <irqs-hw.h>
#include <macros.h>
#include <nvrm_drf.h>
#include <reg-access.h>
#include <spe-pm.h>
#include <spe-vic.h>
#include <stdio.h>
#include <task.h>
#include <timers.h>
#include <tke-tegra.h>
#include <tke-tegra-hw.h>
#include "mbox-aon.h"
#include <bpmp-ipc.h>
#include <hsp-tegra.h>
#include <hsp-tegra-hw.h>
#include <ivc-channels.h>
#include "debug_init.h"
#include <uart-tegra-hw.h>
#include "combined-uart-priv.h"
#include "combined-uart.h"
#include "config.h"
#include "init_padctrl.h"
#include "Os_Core.h"

#define NUM_BYTES_FIELD_BIT	24
#define NUM_BYTES(reg_val)	((reg_val >> NUM_BYTES_FIELD_BIT) & 0x3)

int bpmp_sem = 0;

void vApplicationStackOverflowHook(TimerHandle_t pxTask, signed char *pcTaskName);
// static void bpmp_irq(void *param, uint32_t data);
extern struct ext_client_id ext_client_ids[COMBINED_UART_NUM_EXT_CLIENTS];

#define MB1_DB_IRQ (NV_AON_INTERRUPT_VIC1_BASE + NV_AON_INTERRUPT_TOP0_HSP_DB)
extern struct tegra_uart_conf combined_uart_conf;
extern struct tegra_uart_id *combined_uart_id ;
extern int is_check;


static void late_init(void)
{

	combined_uart_init(&tegra_uart_id_uartc);
	printf("init uartc for combined uart\r\n");
}

static void late_init_db_irq(void *data)
{
	// BaseType_t yield;
	(void)data;

	// if (xSemaphoreGiveFromISR(late_init_sem, &yield) != pdTRUE)
	// 	error_hook("Couldn't give semaphore.");

	irq_disable(MB1_DB_IRQ);
	irq_set_handler(MB1_DB_IRQ, NULL, NULL);
	printf("late_init_db_irq..\r\n");
	is_check++;
	// late_init();
	// for(;;)
	// ;
	// portYIELD_FROM_ISR(yield);
}



int main(void)
{
	// int count =0;

	spe_vic_init();//hardware

	/* select FIQ interrupt */
	arm_vic_write_intselect(NV_ADDRESS_MAP_AON_VIC_0_BASE, BIT(NV_AON_INTERRUPT_WDTFIQ));

	// // init_padctrl();

	tegra_tsc_init();//hardware

	tegra_clk_init();//hardware

	// debug_early_init();//spe_queuecreate

	// spe_pm_init();//powermanager

	tegra_hsp_init(&tegra_hsp_id_aon);//hardware
	/*
	 * Late init task initialization for communicating with BPMP
	 * and then initializing IVC with CCPLEX
	 */
#if(1)
	irq_set_handler(MB1_DB_IRQ, late_init_db_irq, NULL);
	irq_enable(MB1_DB_IRQ);
#endif

	late_init();

	
	// combined_uart_raw_print("abcdefg\n",9);
	// for(int i=0;i<1234559999;i++)
	// {	
	// 	count++;

	// }
	// late_init_sem = xSemaphoreCreateBinary();//创建信号量
	// if (!late_init_sem) {
	// 	error_hook("Couldn't create semaphore!");
	// 	goto skip_late_init;
	// }
	// if (xTaskCreate(late_init_task, "late_init", 256, NULL, 3, NULL) != pdPASS) {
	// 	error_hook("Couldn't create late_init_task");
	// } else {
	// 	irq_set_handler(MB1_DB_IRQ, late_init_db_irq, NULL);
	// 	irq_enable(MB1_DB_IRQ);
	// }

// skip_late_init:
// 	if (bpmp_ipc_init())
// 		printf("bpmp_ipc_init() failed\r\n");
	// if(0){    bpmp_queue();
	// }


	StartOS(1);


	// for(;;)
	// 	;

	// vTaskStartScheduler();

	/* Start the tasks and timer running. */
	for(;;)
		;

	return 0;
}

// /* Referenced from FreeRTOSConfig.h */
void setup_timer_interrupt(void)
{
	tegra_tke_set_up_tick(&tegra_tke_id_timer0,
				TIMER_CLK_SRC,
				configCPU_CLOCK_HZ / configTICK_RATE_HZ);
}

// // /* Referenced from freertos */
void vApplicationStackOverflowHook(TimerHandle_t pxTask, signed char *pcTaskName)
{
	(void)pcTaskName;
	(void)pxTask;

	printf("Stack Overflow");
	taskDISABLE_INTERRUPTS();
	for( ;; )

		;
}
