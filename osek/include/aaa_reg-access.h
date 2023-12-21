#ifndef _REG_ACCESS_H_
#define _REG_ACCESS_H_

#include "aaa_type.h"

static inline uint32_t readl(uint32_t addr)
{
	return *(volatile uint32_t *)addr;
}

static inline void writel(uint32_t data, uint32_t addr)
{
	*(volatile uint32_t *)addr = data;
}

static inline uint8_t readb(uint32_t addr)
{
	return *(volatile uint8_t *)addr;
}

static inline void writeb(uint8_t data, uint32_t addr)
{
	*(volatile uint8_t *)addr = data;
}

#endif