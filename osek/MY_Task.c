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
#include "Os_Evt.h"
#include "Os_Core.h"
#include "Os.h"
#include "aaa_semphr.h"
#include "aaa_queue.h"
#include "combined-uart.h"
#include "combined-uart-priv.h"
#include "combined-uart-tegra.h"
#include "hsp-tegra.h"
#include "stdio.h"
extern char spe_msg_buf[SPE_NUM_MSGS][SPE_MSG_SIZE];
extern unsigned int spe_msg_buf_read_idx, spe_msg_buf_write_idx;
extern struct tegra_uart_id *combined_uart_id;
extern struct ext_client_id spe_id;
extern struct ext_client_id ext_client_ids[COMBINED_UART_NUM_EXT_CLIENTS];
extern struct ext_client_id *last_id;
extern Sem tx_mutex, tx_sem;
extern const struct tegra_hsp_id tegra_hsp_id_aon;
extern bool yield_required;
int is_check = 0;
int tick = 0;
/* 低优先级任务，保留*/
TASK(OsTask_0)
{
    for (;;)
    {

    }
    
    DEFINECRITICAL();

    (void) TerminateTask();
}

TASK(OsTask_1)
{
    DEFINECRITICAL();
	print_char("task1...\r\n");
    // while(is_check == 0);
	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_BPMP];
	id->tx_TaskID = OSTCBCur;
	uint32_t msg;
	bool flag=false;

	for (int i=0;1;i++) {
        // printf("trun:%d\r\n",i);
		do {
			flag = pop(id->tx_queue, &msg, 4);
			if (!flag ) {
				// 阻塞
				WaitEvent(id->tx_event);
			}

		} while (!flag);
		flag = false;
		combined_uart_process_tx_queue(id, msg);
		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
			/*
			 * Entering this block implies that the mbox IRQ is disabled.
			 * Therefore, synchronization is not necessary.
			 */
			id->tx_queue_full = false;
			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
		}

	}
   (void) TerminateTask();
}
TASK(OsTask_2)
{
    DEFINECRITICAL();
	print_char("task2...\r\n");
    // while(is_check == 0);
	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_CCPLEX];
	id->tx_TaskID = OSTCBCur;
	uint32_t msg;
	bool flag=false;

	for (int i=0;1;i++) {

		do {
			flag = pop(id->tx_queue, &msg, 4);

			if (!flag ) {
				// 阻塞
				WaitEvent(id->tx_event);
			}

		} while (!flag);
		flag = false;
        printf(" ");
		combined_uart_process_tx_queue(id, msg);
		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
			/*
			 * Entering this block implies that the mbox IRQ is disabled.
			 * Therefore, synchronization is not necessary.
			 */
			id->tx_queue_full = false;
			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
		}

	}
   (void) TerminateTask();
}

/* combined_uart_tx_task-bpmp，优先级第三高 */
// TASK(OsTask_1)
// {
//     DEFINECRITICAL();
// 	print_char("task7...\r\n");
//     // while(is_check == 0);
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_BPMP];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
//                 print_all();

// 				print_char("task7 before wait\r\n");
// 				WaitEvent(id->tx_event);

// 				print_char("task7 after wait\r\n");

// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}
// //    (void) TerminateTask();
// }

// /* combined_uart_tx_task_spe，优先级第二高 */
// TASK(OsTask_1)
// {
//     DEFINECRITICAL();
    
//     struct ext_client_id *id = &spe_id;
// 	id->tx_TaskID = OSTCBCur;
// 	id->rx_TaskID = NULL;
// 	uint32_t len;

// 	tegra_uart_flush_tx_hw_fifo(combined_uart_id);
// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &len, portMAX_DELAY);
//         bool flag;
//         do {
//             flag = pop(id->tx_queue, (void*)&len, 4);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->tx_event);
// 			}
//         } while (!flag);
// 		// xSemaphoreTake(tx_mutex, portMAX_DELAY);
// 		print_msg(id, spe_msg_buf[spe_msg_buf_read_idx], len);
// 		spe_msg_buf_read_idx = (spe_msg_buf_read_idx + 1) % SPE_NUM_MSGS;
// 		// xSemaphoreGive(tx_mutex);
// 	}
    
// //    (void) TerminateTask();
// }

/* combined_uart_rx_task_spe，优先级第一高 */
// TASK(OsTask_2)
// {
//     DEFINECRITICAL();
    
// 	struct ext_client_id *dest_id = &ext_client_ids[COMBINED_UART_CCPLEX];
// 	bool in_escape = false;
// 	char c;
// 	int i;
// 	combined_uart_id->rx_TaskID = OSTCBCur;
// 	for(;;) {
// 		if (!tegra_uart_read(combined_uart_id, &c, 1))
// 			continue;

// 		if (!in_escape) {
// 			if (c == TAG_ESCAPE_CHAR)
// 				in_escape = true;
// 			else if (dest_id->rx_queue != NULL)
// 				push(dest_id->rx_queue, (void*)&c, 1);
// 			continue;
// 		}

// 		in_escape = false;

// 		/* Handle escape character */
// 		if (c == TAG_ESCAPE_CHAR) {
// 			if (dest_id->rx_queue != NULL)
// 				push(dest_id->rx_queue, (void*)&c, 1);
// 			continue;
// 		}

// 		if (c == TAG_RESET) {
// 			TakeSem(&tx_mutex);
// 			last_id = NULL;
// 			GiveSem(&tx_mutex);
// 			continue;
// 		}

// 		/* void the input */
// 		if (c == spe_id.tag)
// 			dest_id = &spe_id;

// 		for (i = 0; i < COMBINED_UART_NUM_EXT_CLIENTS; i++) {
// 			if (c == ext_client_ids[i].tag) {
// 				dest_id = &ext_client_ids[i];
// 				break;
// 			}
// 		}
// 	}

//     // (void) TerminateTask();
// }


// /* combined_uart_rx_task-ccplex，优先级最低 */
// TASK(OsTask_3)
// {
//     DEFINECRITICAL();
    
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_CCPLEX];
// 	id->rx_TaskID = OSTCBCur;
// 	unsigned char chs[3];
// 	unsigned char c;
// 	int len;

// 	for(;;) {
// 		len = 0;
// 		// xQueueReceive(id->rx_queue, &c, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->rx_queue, &c, 1);
// 			if (!flag) {
// 				/* 阻塞 */
// 				WaitEvent(id->rx_event);
// 			}
// 		} while (!flag);
// 		chs[len++] = c;
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		if (id->rx_enabled)
// 			send_rx_chars(id, chs, len);
// 	}

//    (void) TerminateTask();
// }

/* combined_uart_rx_task-bpmp，优先级最低 */
// TASK(OsTask_4)
// {

//     DEFINECRITICAL();
    
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_BPMP];
// 	id->rx_TaskID = OSTCBCur;
// 	unsigned char chs[3];
// 	unsigned char c;
// 	int len;

// 	for(;;) {
// 		len = 0;
// 		// xQueueReceive(id->rx_queue, &c, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->rx_queue, &c, 1);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->rx_event);
// 			}
// 		} while (!flag);
// 		chs[len++] = c;
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		if (id->rx_enabled)
// 			send_rx_chars(id, chs, len);
// 	}

//     // (void) TerminateTask();
// }

// /* combined_uart_rx_task-sce，优先级最低 */
// TASK(OsTask_5)
// {

//     DEFINECRITICAL();
    
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_SCE];
// 	id->rx_TaskID = OSTCBCur;
// 	unsigned char chs[3];
// 	unsigned char c;
// 	int len;

// 	for(;;) {
// 		len = 0;
// 		// xQueueReceive(id->rx_queue, &c, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->rx_queue, &c, 1);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->rx_event);
// 			}
// 		} while (!flag);
// 		chs[len++] = c;
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		// if (xQueueReceive(id->rx_queue, &c, 0) == pdTRUE)
// 		if (pop(id->rx_queue, &c, 1)) {
// 			chs[len++] = c;
// 		}
// 		if (id->rx_enabled)
// 			send_rx_chars(id, chs, len);
// 	}


//     // (void) TerminateTask();
// }

/* combined_uart_tx_task-ccplex，优先级第三高 */
// TASK(OsTask_6)
// {

//     DEFINECRITICAL();
//     print_char("task6...\r\n");

// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_CCPLEX];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
// 				print_char("task6 before wait\r\n");
// 				WaitEvent(id->tx_event);
// 				print_char("task6 after wait\r\n");
// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}

//     // (void) TerminateTask();
// }

/* combined_uart_tx_task-bpmp，优先级第三高 */
// TASK(OsTask_7)
// {
//     DEFINECRITICAL();
// 	print_char("task7...\r\n");

// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_BPMP];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
// 				print_char("task7 before wait\r\n");
// 				WaitEvent(id->tx_event);
// 				print_char("task7 after wait\r\n");

// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}

// //    (void) TerminateTask();
// }

// /* combined_uart_tx_task-sce，优先级第三高 */
// TASK(OsTask_8)
// {

//     DEFINECRITICAL();
	
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_SCE];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->tx_event);
// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}

//     // (void) TerminateTask();
// }

// /* combined_uart_tx_task-tz，优先级第三高 */
// TASK(OsTask_9)
// {2

//     DEFINECRITICAL();
	
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_TZ];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->tx_event);
// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}

//     // (void) TerminateTask();
// }

// /* combined_uart_tx_task-rce，优先级第三高 */
// TASK(OsTask_10)
// {

//     DEFINECRITICAL();
	
// 	struct ext_client_id *id = &ext_client_ids[COMBINED_UART_RCE];
// 	id->tx_TaskID = OSTCBCur;
// 	uint32_t msg;

// 	for (;;) {
// 		// xQueueReceive(id->tx_queue, &msg, portMAX_DELAY);
// 		bool flag;
// 		do {
// 			flag = pop(id->tx_queue, &msg, 4);
// 			if (!flag) {
// 				// 阻塞
// 				WaitEvent(id->tx_event);
// 			}
// 		} while (!flag);
// 		combined_uart_process_tx_queue(id, msg);
// 		if ((id->tx_queue_full && !is_full(id->tx_queue)) || msg_needs_deferred_ack(msg)) {
// 			/*
// 			 * Entering this block implies that the mbox IRQ is disabled.
// 			 * Therefore, synchronization is not necessary.
// 			 */
// 			id->tx_queue_full = false;
// 			tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
// 			tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox, combined_uart_irq, id);
// 		}
// 	}

//     // (void) TerminateTask();
// }