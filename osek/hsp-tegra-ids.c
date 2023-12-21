#include "address_map_new.h"
#include "aaa_irqs-hw.h"
#include "aaa_hsp.h"

static struct tegra_hsp_ctx tegra_hsp_ctx_top0 = {
	.id = {
		.devname = "hsp",
		.base_addr = NV_ADDRESS_MAP_TOP0_HSP_BASE,
		.host = TEGRA_HSP_DB_SPE,
		.db_irq = NV_AON_INTERRUPT_TOP0_HSP_DB + NV_AON_INTERRUPT_VIC1_BASE,
		.sh_irqs = { -1, -1, -1, -1, -1, -1, -1, -1, }
	},
};
extern const struct tegra_hsp_id tegra_hsp_id_top0 __attribute__((alias("tegra_hsp_ctx_top0")));

static struct tegra_hsp_ctx tegra_hsp_ctx_aon = {
	.id = {
		.devname = "aon-hsp",
		.base_addr = NV_ADDRESS_MAP_AON_HSP_BASE,
		.db_irq = -1,
		.sh_irqs = {
			NV_AON_INTERRUPT_VIC0_BASE + NV_AON_INTERRUPT_MBOX,
			/* 1-4 are connected to LIC: */ -1, -1, -1, -1,
			-1, -1, -1,
		},
	},
};
extern const struct tegra_hsp_id tegra_hsp_id_aon __attribute__((alias("tegra_hsp_ctx_aon")));

static struct tegra_hsp_ctx tegra_hsp_ctx_bpmp = {
	.id = {
		.devname = "bpmp-hsp",
		.base_addr = NV_ADDRESS_MAP_BPMP_HSP_BASE,
		.db_irq = -1,
		.sh_irqs = { -1, -1, -1, -1, -1, -1, -1, -1, }
	},
};
extern const struct tegra_hsp_id tegra_hsp_id_bpmp __attribute__((alias("tegra_hsp_ctx_bpmp")));

static struct tegra_hsp_ctx tegra_hsp_ctx_sce = {
	.id = {
		.devname = "sce-hsp",
		.base_addr = NV_ADDRESS_MAP_SCE_HSP_BASE,
		.db_irq = -1,
		.sh_irqs = { -1, -1, -1, -1, -1, -1, -1, -1, }
	},
};
extern const struct tegra_hsp_id tegra_hsp_id_sce __attribute__((alias("tegra_hsp_ctx_sce")));