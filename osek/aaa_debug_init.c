#include "aaa_print.h"
#include "aaa_type.h"
#include "aaa_hsp.h"
#include "aaa_reg-access.h"
#include "aaa_debug_init.h"
#include "aaa_aruart.h"
#include "aaa_irq.h"
#include "aaa_queue.h"
#include "aaa_macros.h"
#include "Os_Evt.h"
#include "aaa_semphr.h"

#define NUM_BYTES_FIELD_BIT	24
#define FLUSH_BIT		26
#define HW_FLUSH_BIT		27
#define DMA_MODE_BIT		30
#define INTR_TRIGGER_BIT	31
#define NUM_BYTES(reg_val)	((reg_val >> NUM_BYTES_FIELD_BIT) & 0x3)

#define TASK_NAME_LEN		32

#define RX_TIMEOUT_MS		100

bool combined_uart_inited = false;
char spe_msg_buf[SPE_NUM_MSGS][SPE_MSG_SIZE];
unsigned int spe_msg_buf_read_idx = 0, spe_msg_buf_write_idx = 0;

bool yield_required;

#define portEND_SWITCHING_ISR(xSwitchRequired) \
{ \
	yield_required = false; \
	if (xSwitchRequired == true) \
	{ \
		yield_required = true; \
	} \
}

queue_t spe_tx;
queue_t uartc_tx, uartc_rx;
queue_t ccplex_tx, ccplex_rx;
queue_t bpmp_tx, bpmp_rx;
queue_t sce_tx, sce_rx;
queue_t tz_tx;
queue_t rce_tx;

Sem_t tx_mutex, tx_sem;

struct ext_client_id spe_id = {
	.tag = 0xe0,
};

const struct ext_client_id *last_id = NULL;
struct tegra_uart_id *combined_uart_id = NULL;
struct tegra_uart_conf combined_uart_conf = {
	.parity = TEGRA_UART_NO_PARITY,
	.stop_bits = TEGRA_UART_STOP_BITS_1,
	.data_bits = TEGRA_UART_DATA_BITS_8,
	.baud = 115200,
};

extern struct tegra_parent_clk tegra_parent_clk_osc_undiv_data;

const struct tegra_clk tegra_clk_uartc_data = {
	.enb_base_reg = CLK_RST_CONTROLLER_CLK_OUT_ENB_UARTC_0,
	.src_reg = CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0,
	.div_range = FIELD_RANGE(CLK_RST_CONTROLLER_CLK_SOURCE_UARTC_0_UARTC_CLK_DIVISOR_RANGE),
	.div_enb = NV_DRF_DEF(CLK_RST_CONTROLLER, CLK_SOURCE_UARTC, UARTC_DIV_ENB, ENABLE),
	.frac_width = 1,
	.clk_src = NV_DRF_DEF(CLK_RST_CONTROLLER, CLK_SOURCE_UARTC, UARTC_CLK_SRC, OSC_UNDIV),
	.parent = &tegra_parent_clk_osc_undiv_data,
};

const struct tegra_rst tegra_rst_uartc_data = {
	.rst_base_reg = CLK_RST_CONTROLLER_RST_DEV_UARTC_0,
};


struct tegra_uart_id tegra_uart_id_uartc = {
	.devname = "uartc",
	.base_addr = NV_ADDRESS_MAP_UARTC_BASE,
	.clk = tegra_clk_uartc,
	.reset = tegra_rst_uartc,
	.irq = TEGRA_UARTC_IRQ,
};

extern const struct tegra_hsp_id tegra_hsp_id_top0;
extern const struct tegra_hsp_id tegra_hsp_id_aon;
extern const struct tegra_hsp_id tegra_hsp_id_bpmp;
extern const struct tegra_hsp_id tegra_hsp_id_sce;

struct ext_client_id ext_client_ids[] = {
	[COMBINED_UART_CCPLEX] = {
		.tag = 0xe1,
		.name = "ccplex",
		.hsp_id = &tegra_hsp_id_top0,
		.recv_mbox = MBOX_AON_CCPLEX_UART,
		.send_mbox = 0,
		.enabled = true,
	},
	[COMBINED_UART_BPMP] = {
		.tag = 0xe2,
		.name = "bpmp",
		.hsp_id = &tegra_hsp_id_bpmp,
		.recv_mbox = MBOX_AON_BPMP_UART,
		.send_mbox = MBOX_BPMP_UART,
		.enabled = true,
	},
	[COMBINED_UART_SCE]  = {
		.tag = 0xe3,
		.name = "sce",
		.hsp_id = &tegra_hsp_id_sce,
		.recv_mbox = MBOX_AON_SCE_UART,
		.send_mbox = MBOX_SCE_UART,
		.enabled = true,
	},
	[COMBINED_UART_TZ]  = {
		.tag = 0xe4,
		.name = "tz",
		.recv_mbox = MBOX_AON_TZ_UART,
		.enabled = true,
	},
	[COMBINED_UART_RCE]  = {
		.tag = 0xe5,
		.name = "rce",
		.recv_mbox = MBOX_AON_RCE_UART,
		.enabled = true,
	},
};

static inline uint32_t tegra_uart_readl(struct tegra_uart_id *id,
	uint32_t offset)
{
	offset += id->base_addr;
	return readl(offset);
}

static inline void tegra_uart_writel(struct tegra_uart_id *id,
	uint32_t val, uint32_t offset)
{
	offset += id->base_addr;
	writel(val, offset);
}



void init_id() {
	spe_tx.head = 0, spe_tx.tail = 0;
	uartc_tx.head = 0, uartc_tx.tail = 0;
	uartc_rx.head = 0, uartc_rx.tail = 0;
	ccplex_tx.head = 0, ccplex_tx.tail = 0;
	ccplex_rx.head = 0, ccplex_rx.tail = 0;
	bpmp_tx.head = 0, bpmp_tx.tail = 0;
	bpmp_rx.head = 0, bpmp_rx.tail = 0;
	sce_tx.head = 0, sce_tx.tail = 0;
	sce_rx.head = 0, sce_rx.tail = 0;
	tz_tx.head = 0, tz_tx.tail = 0;
	rce_tx.head = 0, rce_tx.tail = 0;

	combined_uart_id->tx_queue = &uartc_tx, combined_uart_id->rx_queue = &uartc_rx;
	combined_uart_id->tx_event = BIT(0), combined_uart_id->rx_event = BIT(1);
	spe_id.tx_queue = &spe_tx, spe_id.rx_queue = NULL;
	spe_id.tx_event = BIT(2), spe_id.rx_event = 0;
	ext_client_ids[COMBINED_UART_CCPLEX].tx_queue = &ccplex_tx, ext_client_ids[COMBINED_UART_CCPLEX].rx_queue = &ccplex_rx;
	ext_client_ids[COMBINED_UART_CCPLEX].tx_event = BIT(3), ext_client_ids[COMBINED_UART_CCPLEX].rx_event = BIT(4);
	ext_client_ids[COMBINED_UART_BPMP].tx_queue = &bpmp_tx, ext_client_ids[COMBINED_UART_BPMP].rx_queue = &bpmp_rx;
	ext_client_ids[COMBINED_UART_BPMP].tx_event = BIT(5), ext_client_ids[COMBINED_UART_BPMP].rx_event = BIT(6);
	ext_client_ids[COMBINED_UART_SCE].tx_queue = &sce_tx, ext_client_ids[COMBINED_UART_SCE].rx_queue = &sce_rx;
	ext_client_ids[COMBINED_UART_SCE].tx_event = BIT(7), ext_client_ids[COMBINED_UART_SCE].rx_event = BIT(8);
	ext_client_ids[COMBINED_UART_TZ].tx_queue = &tz_tx, ext_client_ids[COMBINED_UART_TZ].rx_queue = NULL;
	ext_client_ids[COMBINED_UART_TZ].tx_event = BIT(9), ext_client_ids[COMBINED_UART_TZ].rx_event = 0;
	ext_client_ids[COMBINED_UART_RCE].tx_queue = &rce_tx, ext_client_ids[COMBINED_UART_RCE].rx_queue = NULL;
	ext_client_ids[COMBINED_UART_RCE].tx_event = BIT(10), ext_client_ids[COMBINED_UART_RCE].rx_event = 0;
}

void *Memchr(const void *str, char c, uint32_t n) {
	while (n && (*(unsigned char *)str != (unsigned char)c)) {
        str = (unsigned char *)str + 1;
        n -- ;
    }
    return (n ? (void *)str : NULL);
}

bool msg_needs_deferred_ack(uint32_t msg)
{
	return (msg & (BIT(FLUSH_BIT) | BIT(HW_FLUSH_BIT)));
}

void tegra_uart_write_now(struct tegra_uart_id *id, const char *buf, int count)
{
	struct tegra_uart_ctlr *ctlr = (struct tegra_uart_ctlr *)id;
	int i;

	for (i = 0; i < count; i++) {
		while (!(tegra_uart_readl(id, UART_LSR_0) & TEGRA_UART_LSR_THRE_EMPTY))
			;
		tegra_uart_writel(id, *buf++, UART_THR_DLAB_0_0);
	}
}

int tegra_uart_read(struct tegra_uart_id *id, char *buf, int count)
{
	// uint64_t tstart;
	// uint32_t timeout_left;
	int read_cnt;

	// timeout_left = tegra_uart_timeout_us_to_ticks(timeout);
	// tstart = get_time_ticks();

	for (read_cnt = 0; read_cnt < count; read_cnt ++ ) {
		// if (xQueueReceive(ctlr->rx_queue, buf, timeout_left) == pdFALSE)
		bool flag;
		do {
			flag = pop(id->rx_queue, &buf, 1);
			if (!flag) {
				// 阻塞
				WaitEvent(id->rx_event);
			}
		} while (!flag);
		buf ++ ;
		// timeout_left = tegra_uart_get_elapsed_ticks(tstart, timeout);
	}

	return read_cnt;
}

void tegra_uart_flush_tx_hw_fifo(struct tegra_uart_id *id)
{
	while (!(tegra_uart_readl(id, UART_LSR_0) & TEGRA_UART_LSR_TX_SHIFT_EMPTY))
		;
}

void combined_uart_raw_print(const char *str, uint32_t len)
{
	uint32_t written = 0;

	if (!combined_uart_inited)
		return;

	tegra_uart_write_now(combined_uart_id, str, len);
}

static void combined_uart_dbg_putc(const char *str, uint32_t len)
{
	const char *buf, *tag_escape;
	uint32_t remaining = len;
	uint32_t current_len;

	buf = str;

	while (remaining) {
		tag_escape = (char*)Memchr(buf, TAG_ESCAPE_CHAR, remaining);

		if (tag_escape)
			current_len = tag_escape - buf + 1;
		else
			current_len = remaining;

		combined_uart_raw_print(buf, current_len);
		if (buf[current_len - 1] == TAG_ESCAPE_CHAR)
			combined_uart_raw_print(TAG_ESCAPE_STRING, 1);

		buf += current_len;
		remaining -= current_len;
	}
}

static void tegra_uart_disable_thre_interrupt(struct tegra_uart_id *id)
{
	uint32_t ier;
	irq_disable(id->irq);
	ier = tegra_uart_readl(id, UART_IER_DLAB_0_0);
	if (ier & TEGRA_UART_IER_THRE)
		tegra_uart_writel(id, ier & ~TEGRA_UART_IER_THRE, UART_IER_DLAB_0_0);
	irq_enable(id->irq);
}

void send_rx_chars(struct ext_client_id *id, unsigned char c[], int len)
{
	uint32_t mbox_val;
	uint32_t time;
	int i;

	if (len > 3)
		len = 3;
	if (len <= 0)
		return;

	mbox_val = ((len & 0x3) << NUM_BYTES_FIELD_BIT) | BIT(INTR_TRIGGER_BIT);
	for (i = 0; i < len; i++) {
		mbox_val |= ((c[i] & 0xff) << (i * 8));
	}
	time = tegra_tke_get_usec();
	while (tegra_hsp_sm_peek(id->hsp_id, id->send_mbox) >= 0) {
		if (id->rx_timedout)
			return;
		if (tegra_tke_get_usec() - time > RX_TIMEOUT_MS * 1000) {
			id->rx_timedout = true;
			return;
		}
	}
	id->rx_timedout = false;
	tegra_hsp_sm_produce(id->hsp_id, id->send_mbox, mbox_val);
}

int tegra_uart_flush_tx_buffer(struct tegra_uart_id *id, BaseType_t timeout)
{
	char c;
	if (TakeSem(&tx_sem))
		return -1;
	tegra_uart_disable_thre_interrupt(id);
	while (pop(id->tx_queue, &c, 1)) {
		while (!(tegra_uart_readl(id, UART_LSR_0) & TEGRA_UART_LSR_THRE_EMPTY))
			;
		tegra_uart_writel(id, c, UART_THR_DLAB_0_0);
	}
	GiveSem(&tx_sem);
	return 0;
}

void print_msg(const struct ext_client_id *id, const char *msg_buf, uint32_t len)
{
	char c;

	if (last_id != id) {
		combined_uart_raw_print(TAG_ESCAPE_STRING, 1);
		c = id->tag;
		combined_uart_raw_print(&c, 1);
		last_id = id;
	}

	if (len > 0)
		combined_uart_dbg_putc(msg_buf, len);
}

void combined_uart_process_tx_queue(struct ext_client_id *id, uint32_t msg)
{
	unsigned int i;
	unsigned int num_bytes = NUM_BYTES(msg);
	char buf[3];

	/* Extract characters from message packet */
	for (i = 0; i < num_bytes; i++)
		buf[i] = (msg >> i*8) & 0xff;

	TakeSem(&tx_mutex);
	print_msg(id, buf, num_bytes);
	/* Handle hardware flush command */
	// if (msg & BIT(HW_FLUSH_BIT)) {
	// 	tegra_uart_flush_tx_buffer(combined_uart_id, 0);
	// 	tegra_uart_flush_tx_hw_fifo(combined_uart_id);
	// }
	GiveSem(&tx_mutex);
}

void combined_uart_irq(void *param, uint32_t data)
{
	struct ext_client_id *id = param;
	// BaseType_t higher_prio_task_woken = pdFALSE;
	bool higher_prio_task_woken = false;
	id->rx_enabled = true;

	data &= ~MBOX_TAG_BIT;
	// xQueueSendToBackFromISR(id->tx_queue, &data, &higher_prio_task_woken);
	// portYIELD_FROM_ISR(higher_prio_task_woken);
	if (push(id->tx_queue, (void*)&data, 4)) {
		OSSetEvent(id->tx_TaskID, &id->tx_event, &higher_prio_task_woken);
	}

	if (msg_needs_deferred_ack(data)) {
		/* Pause until this message is processed */
		tegra_hsp_sm_full_disable(&tegra_hsp_id_aon, id->recv_mbox);
	} else if (is_full(id->tx_queue)) {
		/* Pause until the queue has space */
		id->tx_queue_full = true;
		tegra_hsp_sm_full_disable(&tegra_hsp_id_aon, id->recv_mbox);
	} else {
		/* Continue normally */
		tegra_hsp_sm_vacate(&tegra_hsp_id_aon, id->recv_mbox);
	}

	portEND_SWITCHING_ISR(higher_prio_task_woken);
}

void tegra_uart_irq(void *data)
{
	struct tegra_uart_id *id = data;
	uint32_t iir, ier;
	char c_in, c_out;
	bool higher_prio_task_woken;
	while (1) {
		iir = tegra_uart_readl(id, UART_IIR_FCR_0) & 0x0f;
		if (iir & TEGRA_UART_IIR_NO_INT)
			break;

		switch(iir) {
		case 0x0c: /* RX Timeout */
		case 0x04: /* Receive */
			do {
				c_in = tegra_uart_readl(id, UART_THR_DLAB_0_0) & 0xff;
				if (push(id->rx_queue, (void*)&c_in, 1)) {
					OSSetEvent(id->rx_TaskID, &id->rx_event, &higher_prio_task_woken);
				}
			} while(tegra_uart_readl(id, UART_LSR_0) & TEGRA_UART_LSR_RDY);
			break;
		case 0x02: /* THRE */
			// do {
			// 	if (xQueueReceiveFromISR(id->tx_queue, &c_out,
			// 				&higher_prio_task_woken) != pdTRUE) {
			// 		ier = tegra_uart_readl(id, UART_IER_DLAB_0_0);
			// 		tegra_uart_writel(id, ier & ~TEGRA_UART_IER_THRE, UART_IER_DLAB_0_0);
			// 		break;
			// 	}
			// 	tegra_uart_writel(id, c_out, UART_THR_DLAB_0_0);
			// } while (tegra_uart_readl(id, UART_LSR_0) & TEGRA_UART_LSR_THRE_EMPTY);
			break;
		case 0x06: /* LSINT */
			tegra_uart_readl(id, UART_LSR_0);
			break;
		case 0x00: /* MSINT */
			tegra_uart_readl(id, UART_MSR_0);
			break;
		}
	}

	portEND_SWITCHING_ISR(higher_prio_task_woken);

}

int tegra_uart_init_hw(struct tegra_uart_id *id, struct tegra_uart_conf *conf)
{
	// struct tegra_uart_ctlr *ctlr = (struct tegra_uart_ctlr *)id;
	uint32_t fcr, divisor, comm_param, ier;

	tegra_clk_enable(id->clk);
	// tegra_clk_reset_pulse(id->reset, 10);

	/* Program the FCR register */
	fcr = (UART_IIR_FCR_0_FCR_EN_FIFO_ENABLE << UART_IIR_FCR_0_FCR_EN_FIFO_SHIFT);
	fcr |= (UART_IIR_FCR_0_TX_TRIG_FIFO_COUNT_GREATER_8 <<
			UART_IIR_FCR_0_TX_TRIG_SHIFT);
	fcr |= (UART_IIR_FCR_0_RX_TRIG_FIFO_COUNT_GREATER_4 <<
			UART_IIR_FCR_0_RX_TRIG_SHIFT);
	tegra_uart_writel(id, fcr, UART_IIR_FCR_0);

	tegra_clk_set_rate((id->clk), conf->baud * 16);
	divisor = 1;

	switch (conf->parity) {
	case TEGRA_UART_NO_PARITY:
		comm_param = (UART_LCR_0_PAR_NO_PARITY << UART_LCR_0_PAR_SHIFT);
		break;
	case TEGRA_UART_ODD_PARITY:
		comm_param = (UART_LCR_0_EVEN_DISABLE << UART_LCR_0_EVEN_SHIFT) |
			(UART_LCR_0_PAR_PARITY << UART_LCR_0_PAR_SHIFT);
		break;
	case TEGRA_UART_EVEN_PARITY:
		comm_param = (UART_LCR_0_EVEN_ENABLE << UART_LCR_0_EVEN_SHIFT) |
			(UART_LCR_0_PAR_PARITY << UART_LCR_0_PAR_SHIFT);
		break;
	default:
		goto conf_err;
	}

	switch (conf->data_bits) {
	case TEGRA_UART_DATA_BITS_5:
		comm_param |= (UART_LCR_0_WD_SIZE_WORD_LENGTH_5 <<
				UART_LCR_0_WD_SIZE_SHIFT);
		break;
	case TEGRA_UART_DATA_BITS_6:
		comm_param |= (UART_LCR_0_WD_SIZE_WORD_LENGTH_6 <<
				UART_LCR_0_WD_SIZE_SHIFT);
		break;
	case TEGRA_UART_DATA_BITS_7:
		comm_param |= (UART_LCR_0_WD_SIZE_WORD_LENGTH_7 <<
				UART_LCR_0_WD_SIZE_SHIFT);
		break;
	case TEGRA_UART_DATA_BITS_8:
		comm_param |= (UART_LCR_0_WD_SIZE_WORD_LENGTH_8 <<
				UART_LCR_0_WD_SIZE_SHIFT);
		break;
	default:
		goto conf_err;
	}

	if (conf->stop_bits == TEGRA_UART_STOP_BITS_2)
		comm_param |= (UART_LCR_0_STOP_ENABLE << UART_LCR_0_STOP_SHIFT);

	tegra_uart_writel(id, 0x0, UART_LCR_0);
	tegra_uart_writel(id, 0x0, UART_IER_DLAB_0_0);

	tegra_uart_writel(id, comm_param | TEGRA_UART_LCR_DLAB, UART_LCR_0);
	tegra_uart_writel(id, divisor & 0xFF, UART_THR_DLAB_0_0);
	tegra_uart_writel(id, ((divisor >> 8) & 0xFF), UART_IER_DLAB_0_0);
	tegra_uart_writel(id, comm_param & ~TEGRA_UART_LCR_DLAB, UART_LCR_0);

	/* dummy read to ensure write is posted */
	tegra_uart_readl(id, UART_SPR_0);

	/* Enable RX Interrupts */
	ier = (UART_IER_DLAB_0_0_IE_RHR_ENABLE << UART_IER_DLAB_0_0_IE_RHR_SHIFT) |
		(UART_IER_DLAB_0_0_IE_RXS_ENABLE << UART_IER_DLAB_0_0_IE_RXS_SHIFT) |
		(UART_IER_DLAB_0_0_IE_RX_TIMEOUT_ENABLE << UART_IER_DLAB_0_0_IE_RX_TIMEOUT_SHIFT);
	tegra_uart_writel(id, ier, UART_IER_DLAB_0_0);

	// irq_set_handler(id->irq, tegra_uart_irq, id);
	// irq_enable(id->irq);

	return 0;

conf_err:
	tegra_clk_disable(id->clk);
	return 1;
}

int combined_uart_init(struct tegra_uart_id *uart_id)
{
	int i;
	struct ext_client_id *id;

	combined_uart_id = uart_id;
	tegra_uart_init_hw(uart_id, &combined_uart_conf);

	combined_uart_inited = true;
	
	init_id();
	InitSem(&tx_mutex);
	InitSem(&tx_sem);

	combined_uart_raw_print(TAG_BOOT_RESET_STRING, 3);

	for (i = 0; i < COMBINED_UART_NUM_EXT_CLIENTS; i++) {
		id = &ext_client_ids[i];
		id->rx_enabled = false;
		id->rx_timedout = false;
		id->tx_queue_full = false;
		tegra_hsp_sm_full_enable(&tegra_hsp_id_aon, id->recv_mbox,
			combined_uart_irq, id);
	}

	combined_uart_raw_print("aaaaaaaaaaaaaaa",16);

	return 0;
}

void debug_init(void)
{
	int ret = 0;
	ret = combined_uart_init(&tegra_uart_id_uartc);
	print_char("init uartc for combined uart\r\n");
}
