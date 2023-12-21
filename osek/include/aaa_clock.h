#ifndef _CLOCK_
#define _CLOCK_

#include "aaa_type.h"

#define TSC_MTSCANNR_0			0x8
#define TSC_MTSCANDR_0			0xc

#define TSC_MTSCANNR_0_M0_SHIFT		16
#define TSC_MTSCANNR_0_R0_SHIFT		0
#define TSC_MTSCANDR_0_D0_SHIFT		0
#define TSC_MTSCANNR_0_M0_MASK		(0xfff << TSC_MTSCANNR_0_M0_SHIFT)
#define TSC_MTSCANNR_0_R0_MASK		(0xfff << TSC_MTSCANNR_0_R0_SHIFT)
#define TSC_MTSCANDR_0_D0_MASK		(0xfff << TSC_MTSCANDR_0_D0_SHIFT)

#define TSC_BASE_RATE			32768UL

#define TKE_TIMER_TMRCR_0		0x0
#define TKE_TIMER_TMRCR_0_PTV		0x1fffffffU
#define TKE_TIMER_TMRCR_0_PER		BIT(30)
#define TKE_TIMER_TMRCR_0_EN		BIT(31)

#define TKE_TIMER_TMRSR_0		0x4
#define TKE_TIMER_TMRSR_0_INTR_CLR	BIT(30)
#define TKE_TIMER_TMRSR_0_PCV		0x1fffffffU

#define TKE_TIMER_TMRCSSR_0		0x8

#define TSC_MTSCANNR_0			0x8
#define TSC_MTSCANDR_0			0xc

#define TSC_MTSCANNR_0_M0_SHIFT		16
#define TSC_MTSCANNR_0_R0_SHIFT		0
#define TSC_MTSCANDR_0_D0_SHIFT		0
#define TSC_MTSCANNR_0_M0_MASK		(0xfff << TSC_MTSCANNR_0_M0_SHIFT)
#define TSC_MTSCANNR_0_R0_MASK		(0xfff << TSC_MTSCANNR_0_R0_SHIFT)
#define TSC_MTSCANDR_0_D0_MASK		(0xfff << TSC_MTSCANDR_0_D0_SHIFT)

#define TSC_BASE_RATE			32768UL

#define CLK_RST_CONTROLLER_BASE				0x60006000

#define CLK_RST_CONTROLLER_OSC_CTRL_0 0xbf0000
#define CLK_RST_CONTROLLER_CLK_SOURCE_I2C1_0    0x123000

#define CLK_RST_CONTROLLER_OSC_CTRL_0_OSC_FREQ_RANGE	31:28

#define CLK_RST_CONTROLLER_CLK_SOURCE_0_DIVISOR_RANGE	15:0
#define CLK_RST_CONTROLLER_CLK_SOURCE_0_CLK_SRC_RANGE	31:29

#define CLK_RST_CONTROLLER_CLK_OUT_ENB_0		0x00
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_SET_0		0x04
#define CLK_RST_CONTROLLER_CLK_OUT_ENB_CLR_0		0x08

#define CLK_RST_CONTROLLER_RST_DEV_0			0x00
#define CLK_RST_CONTROLLER_RST_DEV_SET_0		0x04
#define CLK_RST_CONTROLLER_RST_DEV_CLR_0		0x08

#define LOWBIT     0
#define HIGHBIT    1
#define FIELD_RANGE(x) { \
	[LOWBIT]  = NV_FIELD_LOWBIT(x), \
	[HIGHBIT] = NV_FIELD_HIGHBIT(x) \
}

#define TEGRA_TKE_CLK_SRC_USECCNT	0U
#define TEGRA_TKE_CLK_SRC_OSCCNT	1U
#define TEGRA_TKE_CLK_SRC_TSC_BIT0	2U
#define TEGRA_TKE_CLK_SRC_TSC_BIT12	3U
#define TIMER_CLK_SRC	TEGRA_TKE_CLK_SRC_USECCNT

#define configCPU_CLOCK_HZ				1000000
#define configTICK_RATE_HZ				1000

typedef void (*tegra_tke_timer_callback)(void *data);

struct tegra_parent_clk {
	uint32_t rate;
};

struct tegra_rst {
	uint32_t rst_base_reg;
};

struct tegra_clk {
	uint32_t enb_base_reg;
	uint32_t src_reg;
	uint8_t div_range[2]; /* [0]=LOWBIT [1]=HIGHBIT */
	uint32_t div_enb; /* 0 if enable bit is not available */
	uint8_t frac_width;
	uint32_t clk_src;
	const struct tegra_parent_clk *parent;
};

struct tegra_tke_id {
	const char *devname;
	uint32_t base_addr;
	uint32_t irq;
};


struct tegra_tke {
	/*
	 * The driver relies on this being the first field, since it casts
	 * pointers between structs tegra_tke_timer_id and tegra_tke.
	 */
	struct tegra_tke_id const conf;
	tegra_tke_timer_callback callback;
	void *data;
};


int tegra_clk_enable(const struct tegra_clk *clk);
int tegra_clk_disable(const struct tegra_clk *clk);
int tegra_clk_reset_set(const struct tegra_rst *rst);
int tegra_clk_reset_clear(const struct tegra_rst *rst);
int tegra_clk_reset_pulse(const struct tegra_rst *rst, uint32_t delay_us);
void tegra_tsc_init(void);
int tegra_clk_init(void);
void tegra_tke_set_up_tick(const struct tegra_tke_id *id, uint32_t clk_src, uint32_t divisor);

#endif