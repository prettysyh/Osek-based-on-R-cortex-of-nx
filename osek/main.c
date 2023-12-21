#include "aaa_vic.h"
#include "aaa_clock.h"
#include "aaa_print.h"
#include "aaa_type.h"
#include "aaa_irq.h"
#include "aaa_hsp.h"
#include "aaa_debug_init.h"
#include "address_map_new.h"
#include "aaa_irqs-hw.h"
#include "aaa_macros.h"
#include "Os_Core.h"

#define MB1_DB_IRQ (NV_AON_INTERRUPT_VIC0_BASE + NV_AON_INTERRUPT_TOP0_HSP_DB)

int sem = 0;
extern const struct tegra_hsp_id tegra_hsp_id_aon;
extern struct tegra_uart_id tegra_uart_id_uartc;
extern struct tegra_uart_id *combined_uart_id ;
extern struct tegra_uart_conf combined_uart_conf ;
extern bool combined_uart_inited ;
extern int tegra_uart_init_hw(struct tegra_uart_id *id, struct tegra_uart_conf *conf);


// static void late_init(void)
// {
// 	debug_init();
// 	combined_uart_raw_print("987654321",9);

// 	// if (ivc_init_channels_ccplex())
// 	// 	printf("ivc_init_channels_ccplex() failed\r\n");
// }
static void late_init(void)
{


	combined_uart_id = &tegra_uart_id_uartc;
	tegra_uart_init_hw(&tegra_uart_id_uartc, &combined_uart_conf);
	combined_uart_inited = true;
	combined_uart_raw_print("123456789\n",11);
	combined_uart_raw_print("123456789\n",11);
	combined_uart_raw_print("987654321",10);

	combined_uart_raw_print("123456789\n",11);
	combined_uart_raw_print("123456789\n",11);
	combined_uart_raw_print("123456789\n",11);
	combined_uart_raw_print("123456789\n",11);

}


static void late_init_db_irq(void *data)
{
	(void)data;
	

	irq_disable(MB1_DB_IRQ);
	irq_set_handler(MB1_DB_IRQ, NULL, NULL);
	late_init();

	sem = 1;
}
int main(void)
{
	
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
	if(0){
	irq_set_handler(MB1_DB_IRQ, late_init_db_irq, NULL);
	irq_enable(MB1_DB_IRQ);
	}

	late_init();

	
	// while (sem == 0);

	// unsigned long mode=1;
	StartOS(mode);

	for( ;; ) {
	}

	return 0;
}