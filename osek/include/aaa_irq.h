#ifndef INCLUDE_IRQS_H
#define INCLUDE_IRQS_H

#include "aaa_type.h"

void irq_enable(uint32_t irq);
void irq_disable(uint32_t irq);
void irq_set_handler(unsigned irq, void (*routine)(void *), void *data);
void irq_handler(unsigned irq);
bool in_interrupt(void);
bool in_critical(void);

#endif
