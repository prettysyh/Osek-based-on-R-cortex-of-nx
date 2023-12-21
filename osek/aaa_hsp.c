#include "aaa_hsp.h"
#include "aaa_irq.h"
#include "aaa_arhsp_int.h"
#include "aaa_reg-access.h"
#include "IntHandle.h"
#include "aaa_macros.h"

#define SI_INDEX 0
#define HSP_SHRD_MBOX_TAG_FIELD (1 << 31)
#define HSP_COMMON_SIZE (NV_ADDRESS_MAP_TOP0_HSP_COMMON_SIZE)
#define HSP_INT_DIMENSIONING_FIELD(regval, field) \
        (((regval) >> HSP_INT_DIMENSIONING_0_ ## field ## _SHIFT) & \
                (HSP_INT_DIMENSIONING_0_ ## field ## _FIELD >> \
                        HSP_INT_DIMENSIONING_0_ ## field ## _SHIFT))
#define HSP_INT_IE_OFFSET (HSP_INT_IE_1 - HSP_INT_IE_0)
#define HSP_SHRD_MBOX_OFFSET 0x8000

#define HSP_SHRD_MBOX_DATA_FIELD 0x7fffffff

enum {
	tegra_hsp_sm_none,
	tegra_hsp_sm_full,
	tegra_hsp_sm_empty,
};


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

static inline struct tegra_hsp_ctx *hsp_ctx(const struct tegra_hsp_id *id)
{
	/* struct tegra_hsp_id assumed to be first field in tegra_hsp_ctx */
	return (struct tegra_hsp_ctx *)id;
}

static void tegra_hsp_sm_writel(struct tegra_hsp_ctx *ctx, uint32_t index,
				uint32_t value)
{
	const struct tegra_hsp_id *id = &ctx->id;

	writel(value, id->base_addr + HSP_COMMON_SIZE +
               (HSP_SHRD_MBOX_OFFSET * index));
}

static uint32_t tegra_hsp_sm_readl(struct tegra_hsp_ctx *ctx, uint32_t index)
{
	const struct tegra_hsp_id *id = &ctx->id;

	return readl(id->base_addr + HSP_COMMON_SIZE +
                     (HSP_SHRD_MBOX_OFFSET * index));
}

static void tegra_hsp_si_writel(struct tegra_hsp_ctx *ctx, uint32_t index,
				uint32_t value)
{
	const struct tegra_hsp_id *id = &ctx->id;

	writel(value, id->base_addr + HSP_INT_IE + (HSP_INT_IE_OFFSET * index));
}

static uint32_t tegra_hsp_si_readl(struct tegra_hsp_ctx *ctx, uint32_t index)
{
	const struct tegra_hsp_id *id = &ctx->id;

	return readl(id->base_addr + HSP_INT_IE + (HSP_INT_IE_OFFSET * index));
}

static void tegra_hsp_irq_handler(void *data)
{
	struct tegra_hsp_ctx *ctx = data;
	unsigned i;
	for (i = 0; i < ctx->n_sm; i++) {
		void *cb_data = ctx->sm[i].opaque;
		uint32_t value;

		switch (ctx->cbtype[i]) {
		case tegra_hsp_sm_full:
			value = tegra_hsp_sm_readl(ctx, i);
			if ((value & HSP_SHRD_MBOX_TAG_FIELD) != 0) {
				ctx->sm[i].callback(cb_data, value);
			}
			break;
		case tegra_hsp_sm_empty:
			value = tegra_hsp_sm_readl(ctx, i);
			if ((value & HSP_SHRD_MBOX_TAG_FIELD) == 0) {
				ctx->sm[i].callback(cb_data, value);
			}
			break;
		case tegra_hsp_sm_none:
		default:
			break;
		}
	}
}

static void tegra_hsp_sm_enable(const struct tegra_hsp_id *id,
				uint32_t sm, unsigned setbit, uint8_t cbtype,
				void (*cb)(void *, uint32_t), void *data)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);
	uint32_t ie;

	ie = tegra_hsp_si_readl(ctx, SI_INDEX);

	ctx->sm[sm].callback = cb;
	ctx->sm[sm].opaque = data;
	ctx->cbtype[sm] = cbtype;

	tegra_hsp_si_writel(ctx, SI_INDEX, ie | BIT(setbit));
}

static void tegra_hsp_sm_disable(const struct tegra_hsp_id *id,
				uint32_t sm, unsigned clrbit)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);
	uint32_t ie;

	if (!in_interrupt())
		taskENTER_CRITICAL();

	ie = tegra_hsp_si_readl(ctx, SI_INDEX);
	tegra_hsp_si_writel(ctx, SI_INDEX, ie & ~BIT(clrbit));

	/* FIXME: sync interrupt handler here */
	ctx->sm[sm].callback = NULL;
	ctx->cbtype[sm] = tegra_hsp_sm_none;

	if (!in_interrupt())
		taskEXIT_CRITICAL();
}

void tegra_hsp_sm_full_enable(const struct tegra_hsp_id *id, uint32_t sm,
				void (*cb)(void *, uint32_t), void *data)
{
	unsigned iebit = HSP_INT_IE_0_mbox_full_enable_SHIFT + sm;
	tegra_hsp_sm_enable(id, sm, iebit, tegra_hsp_sm_full, cb, data);
}

void tegra_hsp_sm_full_disable(const struct tegra_hsp_id *id, uint32_t sm)
{
	unsigned iebit = HSP_INT_IE_0_mbox_full_enable_SHIFT + sm;
	tegra_hsp_sm_disable(id, sm, iebit);
}

void tegra_hsp_sm_vacate(const struct tegra_hsp_id *id, uint32_t sm)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);

	tegra_hsp_sm_writel(ctx, sm, 0);
}

void tegra_hsp_sm_produce(const struct tegra_hsp_id *id, uint32_t sm,
				int32_t value)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);

	tegra_hsp_sm_writel(ctx, sm, HSP_SHRD_MBOX_TAG_FIELD | (uint32_t)value);
}

int32_t tegra_hsp_sm_peek(const struct tegra_hsp_id *id, uint32_t sm)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);
	uint32_t v = tegra_hsp_sm_readl(ctx, sm);

	if ((v & HSP_SHRD_MBOX_TAG_FIELD) == 0)
		return -1; /* mailbox is empty */

	return v & HSP_SHRD_MBOX_DATA_FIELD;
}


void tegra_hsp_init(const struct tegra_hsp_id *id)
{
	struct tegra_hsp_ctx *ctx = hsp_ctx(id);
	uint32_t val;

	val = readl(id->base_addr + HSP_INT_DIMENSIONING_0);

	ctx->n_sm = HSP_INT_DIMENSIONING_FIELD(val, nSM);
	ctx->n_ss = HSP_INT_DIMENSIONING_FIELD(val, nSS);
	ctx->n_as = HSP_INT_DIMENSIONING_FIELD(val, nAS);
	ctx->n_db = HSP_INT_DIMENSIONING_FIELD(val, nDB);
	ctx->n_si = HSP_INT_DIMENSIONING_FIELD(val, nSI);
	ctx->db_base = id->base_addr +
		((1 + (ctx->n_sm / 2) + ctx->n_ss + ctx->n_as) << 16u);

	if (id->sh_irqs[SI_INDEX] >= 0) {
		irq_set_handler(id->sh_irqs[SI_INDEX], tegra_hsp_irq_handler, ctx);
		irq_enable(id->sh_irqs[SI_INDEX]);
	}
}