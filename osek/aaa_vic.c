#include "aaa_vic.h"
#include "aaa_irq.h"
#include "aaa_type.h"
#include "aaa_araps_vic.h"
#include "address_map_new.h"

#define NUM_VIC_IRQS	32

static uint32_t vic_base_addr[] ={
	NV_ADDRESS_MAP_AON_VIC_0_BASE,
	NV_ADDRESS_MAP_AON_VIC_1_BASE
};


static inline void writel(uint32_t data, uint32_t addr)
{
	*(volatile uint32_t *)addr = data;
}

void arm_vic_set_isr_vect_addr(uint32_t vic_base, uint32_t irq,
				void (*isr_vect_addr)(void))
{
	uint32_t reg = APS_VIC_VICVECTADDR0_0 +
		(irq * (APS_VIC_VICVECTADDR1_0 - APS_VIC_VICVECTADDR0_0));

	writel((uint32_t)isr_vect_addr, vic_base + reg);
}

void arm_vic_write_intselect(uint32_t vic_base, uint32_t intselect)
{
	writel(intselect, vic_base + APS_VIC_VICINTSELECT_0);
}

void spe_vic0_irq_handler(unsigned int irq)
{
	irq_handler(irq);

	writel(0, vic_base_addr[0] + APS_VIC_VICADDRESS_0);
}

void spe_vic1_irq_handler(unsigned int irq)
{
	irq_handler(irq + 32);

	writel(0, vic_base_addr[1] + APS_VIC_VICADDRESS_0);
	writel(0, vic_base_addr[0] + APS_VIC_VICADDRESS_0);
}

extern void spe_vic0_vectors(void);
extern void spe_vic0_vectors_end(void);
extern void spe_vic1_vectors(void);
extern void spe_vic1_vectors_end(void);

void spe_vic_init(void)
{
	uint32_t vic0_vector_size;
	uint32_t vic1_vector_size;
	int i;
	void (*vic0_vector)(void) = spe_vic0_vectors;
	void (*vic1_vector)(void) = spe_vic1_vectors;

	vic0_vector_size = ((uint32_t)spe_vic0_vectors_end - (uint32_t)spe_vic0_vectors) / NUM_VIC_IRQS;
	vic1_vector_size = ((uint32_t)spe_vic1_vectors_end - (uint32_t)spe_vic1_vectors) / NUM_VIC_IRQS;

	for (i = 0; i < 32; i++) {
		arm_vic_set_isr_vect_addr(vic_base_addr[0], i, vic0_vector);
		arm_vic_set_isr_vect_addr(vic_base_addr[1], i, vic1_vector);
		vic0_vector = (void (*)(void))((uint32_t) vic0_vector + vic0_vector_size);
		vic1_vector = (void (*)(void))((uint32_t) vic1_vector + vic1_vector_size);
	}
}
