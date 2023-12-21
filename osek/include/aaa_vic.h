#include "aaa_type.h"

void arm_vic_set_isr_vect_addr(uint32_t vic_base, uint32_t irq,
				void (*isr_vect_addr)(void));
void arm_vic_write_intselect(uint32_t vic_base, uint32_t intselect);
void spe_vic0_irq_handler(unsigned int irq);
void spe_vic1_irq_handler(unsigned int irq);
void spe_vic_init(void);