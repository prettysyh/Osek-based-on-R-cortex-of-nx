#ifndef AAA_HSP_H
#define AAA_HSP_H

#include "aaa_type.h"
#include "aaa_irqs-hw.h"
#include "address_map_new.h"

#define MAX_TEGRA_HSP_SM  8U

#define MBOX_BPMP_BPMP			0
#define MBOX_BPMP_UART			1

#define MBOX_AON_BPMP			0
#define MBOX_AON_CCPLEX_IVC_TX		2
#define MBOX_AON_CCPLEX_IVC_RX		3
#define MBOX_AON_CCPLEX_UART		1
#define MBOX_AON_BPMP_UART		6
#define MBOX_AON_SCE_UART		4
#define MBOX_AON_TZ_UART		7
#define MBOX_AON_RCE_UART		5
#define MBOX_AON_TLK_UART		5

#define MBOX_SCE_UART                   4

#define MBOX_TAG_BIT (1 << 31)

#define TEGRA_HSP_DB_SPE 4

typedef void (*tegra_hsp_callback)(uint32_t source, BaseType_t *higher_prio_task_woken);

struct tegra_hsp_id {
	const char *devname;
	uint32_t base_addr;
	uint32_t host;
	int32_t db_irq;
	int32_t sh_irqs[MAX_TEGRA_HSP_SM];
};

struct tegra_hsp_ctx {
	const struct tegra_hsp_id id;
	tegra_hsp_callback db_callback;
	uint32_t db_base;
	struct {
		void (*callback)(void *, uint32_t);
		void *opaque;
	} sm[MAX_TEGRA_HSP_SM];
	uint8_t cbtype[MAX_TEGRA_HSP_SM];
	uint8_t n_sm;
	uint8_t n_ss;
	uint8_t n_as;
	uint8_t n_db;
	uint8_t n_si;
};


void tegra_hsp_init(const struct tegra_hsp_id *id);
void tegra_hsp_sm_full_enable(const struct tegra_hsp_id *id, uint32_t sm,
				void (*cb)(void *, uint32_t), void *data);
void tegra_hsp_sm_vacate(const struct tegra_hsp_id *id, uint32_t sm);
void tegra_hsp_sm_full_disable(const struct tegra_hsp_id *id, uint32_t sm);
void tegra_hsp_sm_produce(const struct tegra_hsp_id *id, uint32_t sm, int32_t value);
int32_t tegra_hsp_sm_peek(const struct tegra_hsp_id *id, uint32_t sm);
				
#endif