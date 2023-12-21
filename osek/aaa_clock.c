#include "aaa_clock.h"
#include "aaa_type.h"
#include "address_map_new.h"
#include "aaa_nvrm_drf.h"
#include "aaa_reg-access.h"
#include "aaa_macros.h"
#include "aaa_artke_top.h"
#include "Os_Cpu_Types.h"
#include "Os_Alarm.h"
#include "Os.h"
#include "IntHandle.h"
#include "aaa_irqs-hw.h"

static uint32_t cntfid0, cntperiod;

const uint32_t tke_top_base = NV_ADDRESS_MAP_AON_TKE_BASE;

extern unsigned int startos;

#define taskYIELD()					portYIELD()
#define portYIELD()					__asm__ volatile ( "SWI 0" )

#define TEGRA_TKE_NO_IRQ 0xFFFFFFFF


struct tegra_parent_clk tegra_parent_clk_osc_undiv_data = {
	.rate = 0,
};

struct tegra_tke tegra_tke_timer0 = {
	.conf = {
		.devname = "tke0",
		.base_addr = NV_ADDRESS_MAP_AON_TKE_TMR_0_BASE,
		.irq = NV_AON_INTERRUPT_TIMER0,
	},
};
extern const struct tegra_tke_id tegra_tke_id_timer0 __attribute__((alias("tegra_tke_timer0")));


static inline uint32_t tegra_tke_timer_readl(const struct tegra_tke_id *id, uint32_t reg)
{
	return readl(id->base_addr + reg);
}

static void tegra_tke_timer_writel(const struct tegra_tke_id *id, uint32_t val, uint32_t reg)
{
	writel(val, id->base_addr + reg);
}

int tegra_clk_enable(const struct tegra_clk *clk)
{
	writel(BIT(0), NV_ADDRESS_MAP_CAR_BASE + clk->enb_base_reg + CLK_RST_CONTROLLER_CLK_OUT_ENB_SET_0);
	return 0;
}

int tegra_clk_disable(const struct tegra_clk *clk)
{
	writel(BIT(0), NV_ADDRESS_MAP_CAR_BASE + clk->enb_base_reg + CLK_RST_CONTROLLER_CLK_OUT_ENB_CLR_0);
	return 0;
}

int tegra_clk_reset_set(const struct tegra_rst *rst)
{
	writel(BIT(0), NV_ADDRESS_MAP_CAR_BASE + rst->rst_base_reg + CLK_RST_CONTROLLER_RST_DEV_SET_0);
	return 0;
}

int tegra_clk_reset_clear(const struct tegra_rst *rst)
{
	writel(BIT(0), NV_ADDRESS_MAP_CAR_BASE + rst->rst_base_reg + CLK_RST_CONTROLLER_RST_DEV_CLR_0);
	return 0;
}


uint32_t tegra_tke_get_usec(void)
{
	return readl(tke_top_base + TKE_TOP_SHARED_TKEUSEC_0);
}

void udelay(uint32_t delay_us)
{
	UBaseType_t state;
	bool cant_yield;
	uint32_t start = tegra_tke_get_usec();

	cant_yield = in_interrupt();

	while ((tegra_tke_get_usec() - start) < (delay_us + 1))
		if (cant_yield)
			;
		else
			taskYIELD();
}

int tegra_clk_reset_pulse(const struct tegra_rst *rst, uint32_t delay_us)
{
	int ret;

	ret = tegra_clk_reset_set(rst);
	if (ret)
		return ret;
	udelay(delay_us);
	return tegra_clk_reset_clear(rst);
}


int tegra_clk_set_rate(const struct tegra_clk *clk, uint32_t rate_hz)
{
	uint32_t divisor;
	uint32_t val;
	
	divisor = (((clk->parent->rate) << clk->frac_width) + rate_hz - 1) / rate_hz;
	divisor -= (1 << clk->frac_width);
	if (divisor & ~NV_FIELD_MASK(clk->div_range[HIGHBIT]:clk->div_range[LOWBIT]))
		return 1;

	val = NV_FIELD_BITS(divisor, clk->div_range[HIGHBIT]:clk->div_range[LOWBIT]) |
	      clk->clk_src | clk->div_enb;

	writel(val, NV_ADDRESS_MAP_CAR_BASE + clk->src_reg);

	return 0;
}

void tegra_tsc_init(void)
{
	uint32_t m0, r0, d0;
	uint32_t val;

	val = readl(NV_ADDRESS_MAP_TSC_IMPL_BASE + TSC_MTSCANNR_0);

	m0 = (val & TSC_MTSCANNR_0_M0_MASK) >> TSC_MTSCANNR_0_M0_SHIFT;
	r0 = (val & TSC_MTSCANNR_0_R0_MASK) >> TSC_MTSCANNR_0_R0_SHIFT;

	val = readl(NV_ADDRESS_MAP_TSC_IMPL_BASE + TSC_MTSCANDR_0);
	d0 = (val & TSC_MTSCANDR_0_D0_MASK) >> TSC_MTSCANDR_0_D0_SHIFT;

	cntfid0 = (TSC_BASE_RATE / d0) * (d0 * r0 + m0);
	cntperiod = 1000000000U / cntfid0;
}

int tegra_clk_init(void)
{
	uint32_t osc_undiv_rate;
#ifndef _NV_BUILD_FPGA_
	uint32_t val;
	uint32_t osc_freq;

	val = readl(NV_ADDRESS_MAP_CAR_BASE + CLK_RST_CONTROLLER_OSC_CTRL_0);

	osc_freq = NV_DRF_VAL(CLK_RST_CONTROLLER, OSC_CTRL, OSC_FREQ, val);
	switch (osc_freq) {
	case 0:
		osc_undiv_rate = 13000000;
		break;
	case 1:
		osc_undiv_rate = 16800000;
		break;
	case 4:
		osc_undiv_rate = 19200000;
		break;
	case 5:
		osc_undiv_rate = 38400000;
		break;
	case 8:
		osc_undiv_rate = 12000000;
		break;
	case 9:
		osc_undiv_rate = 48000000;
		break;
	case 12:
		osc_undiv_rate = 26000000;
		break;
	default:
		osc_undiv_rate = 38400000;
		break;
	}
#else
	/* FPGA */
	osc_undiv_rate = FPGA_FREQUENCY_CLK_M;
#endif
	tegra_parent_clk_osc_undiv_data.rate = osc_undiv_rate;

	return 0;
}

void tegra_tke_clear_timer_irq(const struct tegra_tke_id *id)
{
	tegra_tke_timer_writel(id, TKE_TIMER_TMRSR_0_INTR_CLR, TKE_TIMER_TMRSR_0);
}

void tegra_tke_irq(void *id)
{
	struct tegra_tke *tke_dev = id;

	tegra_tke_clear_timer_irq(&tke_dev->conf);

	if (tke_dev->callback)
		tke_dev->callback(tke_dev->data);
}

void tegra_tke_set_up_timer(const struct tegra_tke_id *id, uint32_t clk_src_sel,
				bool periodic, uint32_t divisor,
				tegra_tke_timer_callback callback, void *data)
{
	/* struct tegra_tke_id assumed to be first field in tegra_tke */
	struct tegra_tke *tke_dev = (struct tegra_tke *)id;
	uint32_t tmrcr;

	tke_dev->callback = callback;
	tke_dev->data = data;

	/* select timer clock source */
	tegra_tke_timer_writel(id, clk_src_sel, TKE_TIMER_TMRCSSR_0);

	/* Disable timer, set cycle counter */
	tmrcr = (divisor - 1) & TKE_TIMER_TMRCR_0_PTV;
	tegra_tke_timer_writel(id, tmrcr, TKE_TIMER_TMRCR_0);

	/* Clear timer interrupts. */
	tegra_tke_timer_writel(id, TKE_TIMER_TMRSR_0_INTR_CLR, TKE_TIMER_TMRSR_0);

	/* Enable timer and configure timer type. */
	tmrcr |= TKE_TIMER_TMRCR_0_EN;
	if (periodic)
		tmrcr |= TKE_TIMER_TMRCR_0_PER;
	tegra_tke_timer_writel(id, tmrcr, TKE_TIMER_TMRCR_0);

	if (id->irq != TEGRA_TKE_NO_IRQ) {
		irq_set_handler(id->irq, tegra_tke_irq, tke_dev);
		irq_enable(id->irq);
	}
}

void FreeRTOS_Tick_Handler(void) {
	
	print_char("timer interrupt generation\r\n");
	if(startos==1)
    {
        IntEnter();
        OSCounterTrigger(OSCounters);
  /* USER CODE BEGIN SysTick_IRQn 1 */
        if(CounterRdy == 1){
            IntExit();
        }
        else{
            --IntNesting;
        }
        print_char("finish timer\r\n");
    }
}

static void tegra_tke_os_tick(void *data)
{
	FreeRTOS_Tick_Handler();
}


void tegra_tke_set_up_tick(const struct tegra_tke_id *id, uint32_t clk_src, uint32_t divisor)
{
	tegra_tke_set_up_timer(id, clk_src, true, divisor, tegra_tke_os_tick, NULL);
}