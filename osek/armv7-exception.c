/*
 * Copyright (c) 2015-2016, NVIDIA CORPORATION.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *  * Neither the name of NVIDIA CORPORATION nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY
 * OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "armv7-exception.h"
#include "aaa_print.h"

void armv7_exception(int type, struct armv7_exception_frame *frame)
{
	uint32_t dfar, dfsr, ifsr, ifar;

	print_char("--------------------------------------------------------------------------------\r\n");

	switch (type) {
	case DATA_ABORT:
		print_char("Exception: Data abort\r\n");
		__asm__ __volatile__(
			"mrc p15, 0, %0, c5, c0, 0\n\t"
			: "=r" (dfsr)
		);
		__asm__ __volatile__(
			"mrc p15, 0, %0, c6, c0, 0\n\t"
			: "=r" (dfar)
		);

		// print_char("DFAR: 0x%08lx, DFSR: 0x%08lx\r\n", dfar, dfsr);
		print_char("DFAR: ");
		print_reg(dfar);
		print_char("DFSR: ");
		print_reg(dfsr);
		break;

	case PREFETCH_ABORT:
		print_char("Exception: Prefetch abort\r\n");
		__asm__ __volatile__(
			"mrc p15, 0, %0, c5, c0, 1\n\t"
			: "=r" (ifsr)
		);
		__asm__ __volatile__(
			"mrc p15, 0, %0, c6, c0, 2\n\t"
			: "=r" (ifar)
		);
		// print_char("IFAR: 0x%08lx, IFSR: 0x%08lx\r\n", ifar, ifsr);
		print_char("IFAR: ");
		print_reg(ifar);
		print_char("IFSR: ");
		print_reg(ifsr);
		break;

	case UNDEFINED_INSTRUCTION:
		print_char("Exception: Undefined instruction\r\n");
		break;

	default:
		print_char("Exception: Unknown\r\n");
		break;
	}

	// print_char("PC: 0x%08lx\r\n", frame->pc);
	// print_char("LR: 0x%08lx, SP:  0x%08lx, PSR: 0x%08lx\r\n", frame->lr, frame->sp, frame->spsr);
	// print_char("R0: 0x%08lx, R1:  0x%08lx, R2:  0x%08lx\r\n", frame->r0, frame->r1, frame->r2);
	// print_char("R3: 0x%08lx, R4:  0x%08lx, R5:  0x%08lx\r\n", frame->r3, frame->r4, frame->r5);
	// print_char("R6: 0x%08lx, R7:  0x%08lx, R8:  0x%08lx\r\n", frame->r6, frame->r7, frame->r8);
	// print_char("R9: 0x%08lx, R10: 0x%08lx, R11: 0x%08lx\r\n", frame->r9, frame->r10, frame->r11);
	// print_char("R12: 0x%08lx\r\n", frame->r12);

	print_char("PC: ");
	print_reg(frame->lr);
	print_char("LR: ");
	print_reg(frame->pc);
	print_char("SP: ");
	print_reg(frame->sp);
	print_char("PSR: ");
	print_reg(frame->spsr);
	print_char("R0: ");
	print_reg(frame->r0);
	print_char("R1: ");
	print_reg(frame->r1);
	print_char("R2: ");
	print_reg(frame->r2);
	print_char("R3: ");
	print_reg(frame->r3);
	print_char("R4: ");
	print_reg(frame->r4);
	print_char("R5: ");
	print_reg(frame->r5);
	print_char("R6: ");
	print_reg(frame->r6);
	print_char("R7: ");
	print_reg(frame->r7);
	print_char("R8: ");
	print_reg(frame->r8);
	print_char("R9: ");
	print_reg(frame->r9);
	print_char("R10: ");
	print_reg(frame->r10);
	print_char("R11: ");
	print_reg(frame->r11);
	print_char("R12: ");
	print_reg(frame->r12);

	print_char("--------------------------------------------------------------------------------\r\n");


	while (1);
}
