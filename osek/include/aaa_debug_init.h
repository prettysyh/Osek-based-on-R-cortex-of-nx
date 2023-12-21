#ifndef _DEBUG_INIT_H
#define _DEBUG_INIT_H

#include "address_map_new.h"
#include "aaa_irqs-hw.h"
#include "aaa_hsp.h"
#include "aaa_type.h"
#include "aaa_clock.h"
#include "aaa_nvrm_drf.h"
#include "aaa_queue.h"
#include "Os_Core.h"
#include "Os.h"

#define TEGRA_UARTC_IRQ NV_AON_INTERRUPT_UART_1

#define tegra_clk_uartc (&tegra_clk_uartc_data)
#define tegra_rst_uartc (&tegra_rst_uartc_data)

#define TAG_ESCAPE_CHAR		0xff
#define TAG_ESCAPE_STRING	"\377"

#define TAG_RESET		0xfd
#define TAG_BOOT_RESET_STRING	"\0\377\375"

#define SPE_NUM_MSGS		20
#define SPE_MSG_SIZE		128
#define EXT_CLIENT_MSG_SIZE	256
#define EXT_CLIENT_RX_BUF_SIZE	256

#define CLK_RST_CONTROLLER_CLK_OUT_ENB_UARTC_0 0xb41000
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0 0xb43000
#define CLK_RST_CONTROLLER_RST_DEV_UARTC_0 0xb40000
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_CLK_DIVISOR_RANGE 15:0
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_DIV_ENB_ENABLE 1
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_DIV_ENB_RANGE 24:24
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_CLK_SRC_OSC_UNDIV 7
#define CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_CLK_SRC_RANGE 31:29

struct tegra_uart_id {
	const char *devname;
	uint32_t base_addr;
	const struct tegra_clk *clk;
	const struct tegra_rst *reset;
	uint32_t irq;
	QueueHandle tx_queue;
	QueueHandle rx_queue;
	EventMaskType tx_event;
	EventMaskType rx_event;
	TaskType rx_TaskID;

};

struct ext_client_id {
	const struct tegra_hsp_id *hsp_id;
	const char *name;
	uint32_t recv_mbox;
	uint32_t send_mbox;
	uint8_t tag;
	bool enabled;
	bool tx_queue_full;
	bool rx_enabled;
	bool rx_timedout;
	QueueHandle tx_queue;
	QueueHandle rx_queue;
	EventMaskType tx_event;
	EventMaskType rx_event;
	TaskType rx_TaskID;
	TaskType tx_TaskID;
};

enum combined_uart_ext_client {
	COMBINED_UART_CCPLEX,
	COMBINED_UART_SCE,
	COMBINED_UART_TZ,
	COMBINED_UART_BPMP,
	COMBINED_UART_RCE,
	COMBINED_UART_NUM_EXT_CLIENTS
};

enum tegra_uart_parity {
	TEGRA_UART_NO_PARITY,
	TEGRA_UART_ODD_PARITY,
	TEGRA_UART_EVEN_PARITY,
};

enum tegra_uart_stop_bits {
	TEGRA_UART_STOP_BITS_1,
	TEGRA_UART_STOP_BITS_2
};

enum tegra_uart_data_bits {
	TEGRA_UART_DATA_BITS_5,
	TEGRA_UART_DATA_BITS_6,
	TEGRA_UART_DATA_BITS_7,
	TEGRA_UART_DATA_BITS_8,
} tegra_uart_data_bits;

struct tegra_uart_conf {
	enum tegra_uart_parity parity;
	enum tegra_uart_stop_bits stop_bits;
	enum tegra_uart_data_bits data_bits;
	unsigned int baud;
};

void print_msg(const struct ext_client_id *id, const char *msg_buf, uint32_t len);
void combined_uart_process_tx_queue(struct ext_client_id *id, uint32_t msg);
int tegra_uart_read(struct tegra_uart_id *id, char *buf, int count);
void tegra_uart_flush_tx_hw_fifo(struct tegra_uart_id *id);
void debug_init(void);
bool msg_needs_deferred_ack(uint32_t msg);
void combined_uart_irq(void *param, uint32_t data);
void send_rx_chars(struct ext_client_id *id, unsigned char c[], int len);
void combined_uart_raw_print(const char *str, uint32_t len);

#endif