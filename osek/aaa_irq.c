#include "aaa_type.h"
#include "aaa_araps_vic.h"
#include "address_map_new.h"
#include "Platform_Lib.h"
#include "aaa_irq.h"
#include "aaa_print.h"

#define BIT(_x_) ((uint32_t)(1U) << (_x_))

#define MAX_IRQS 64
#define NUM_VIC_IRQS 32

#define ARM_MODE_FIQ 0x11
#define ARM_MODE_IRQ 0x12
#define ARM_MODE_MASK 0x1F

#define ARM_CPSR_I_SHIFT 7
#define ARM_CPSR_I_MASK (1 << ARM_CPSR_I_SHIFT)

struct irq_handler {
	void (*handler)(void*);
	void *data;
};

static struct irq_handler irq_handlers[MAX_IRQS];

static uint32_t vic_base_addr[] ={
	NV_ADDRESS_MAP_AON_VIC_0_BASE,
	NV_ADDRESS_MAP_AON_VIC_1_BASE
};


static inline void writel(uint32_t data, uint32_t addr)
{
	*(volatile uint32_t *)addr = data;
}

void arm_vic_enable(uint32_t vic_base, uint32_t irq)
{
	writel(BIT(irq), vic_base + APS_VIC_VICINTENABLE_0);
}

void arm_vic_disable(uint32_t vic_base, uint32_t irq)
{
	writel(BIT(irq), vic_base + APS_VIC_VICINTENCLEAR_0);
}

void irq_enable(uint32_t irq)
{
	arm_vic_enable(vic_base_addr[(irq / NUM_VIC_IRQS)], (irq % NUM_VIC_IRQS));
}

void irq_disable(uint32_t irq)
{
	arm_vic_disable(vic_base_addr[(irq / NUM_VIC_IRQS)], (irq % NUM_VIC_IRQS));
}


void irq_handler(unsigned int irq)
{
	struct irq_handler *h;

	if (irq >= MAX_IRQS) {
		print_char("Recieved invalid interrupt!");
		return;
	}

	h = &irq_handlers[irq];
	if (h->handler) {
		h->handler(h->data);
	} else {
		print_char("Spurious interrupt!");
	}
}

void irq_set_handler(unsigned int irq, void (*fn)(void *), void *data)
{
	struct irq_handler *h;

	if (irq >= MAX_IRQS) {
		print_char("Trying to set invalid interrupt!");
		return;
	}

	h = &irq_handlers[irq];
	ENTER_CRITICAL();
	h->handler = fn;
	h->data = data;
	EXIT_CRITICAL();
}

static inline uint32_t arm_get_mode(void)
{
	uint32_t cpsr;

	__asm__ __volatile__ (
		"mrs %0, cpsr\n\t"
		: "=r" (cpsr)
	);

	return cpsr & ARM_MODE_MASK;
}


bool in_interrupt(void)
{
	uint32_t mode = arm_get_mode();
	return (mode == ARM_MODE_IRQ) || (mode == ARM_MODE_FIQ);
}



static inline uint32_t arm_get_i_bit(void)
{
	uint32_t cpsr;

	__asm__ __volatile__ (
		"mrs %0, cpsr\n\t"
		: "=r" (cpsr)
	);

	return (cpsr & ARM_CPSR_I_MASK) >> ARM_CPSR_I_SHIFT;
}

bool in_critical(void)
{
	return arm_get_i_bit();
}
