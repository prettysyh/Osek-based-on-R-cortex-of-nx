#ifndef _ARMV7_EXCEPTION_H
#define _ARMV7_EXCEPTION_H

#define DATA_ABORT 0
#define PREFETCH_ABORT 1
#define UNDEFINED_INSTRUCTION 2

#ifndef __ASSEMBLER__

#include "aaa_type.h"

struct armv7_exception_frame {
	uint32_t sp;
	uint32_t lr;
	uint32_t spsr;
	uint32_t r0;
	uint32_t r1;
	uint32_t r2;
	uint32_t r3;
	uint32_t r4;
	uint32_t r5;
	uint32_t r6;
	uint32_t r7;
	uint32_t r8;
	uint32_t r9;
	uint32_t r10;
	uint32_t r11;
	uint32_t r12;
	uint32_t pc;
};

void armv7_exception(int type, struct armv7_exception_frame *frame);

#endif /* !defined __ASSEMBLER__ */

#endif /* !defined _ARMV7_EXCEPTION_H */
