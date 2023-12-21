/*
 * Copyright (c) 2015-2018, NVIDIA CORPORATION.  All rights reserved.
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

#include "aaa_type.h"

static inline void dcache_invalidate_all(void)
{
	__asm__ __volatile__(
		"mcr p15, 0, r0, c15, c5, 0\n\t" /* Invalidate entire data cache */
		: : : "memory"
	);
}

static inline void icache_invalidate_all(void)
{
	__asm__ __volatile__(
		"mcr	p15, 0, %0, c7, c5, 0\n\t" /* ICIALLU */
		: : "r" (0) : "memory"
	);
}

static inline void branch_predictor_invalidate_all(void)
{
	__asm__ __volatile__(
		"mcr	p15, 0, %0, c7, c5, 6\n\t" /* BPIALL */
		: : "r" (0) : "memory"
	);
}

void cache_enable(void)
{
	uint32_t sctlr;

	__asm__ __volatile__(
		"mrc	p15, 0, %0, c1, c0, 0\n\t" /* Read System Control Register configuration data */
		"orr	%0, %0, #0x1 << 12\n\t" /* instruction cache enable */
		"orr	%0, %0, #0x1 << 2\n\t" /* data cache enable */
		"dsb\n\t"
		: "=r" (sctlr) : : "memory"
	);
	dcache_invalidate_all();
	icache_invalidate_all();
	branch_predictor_invalidate_all();
	__asm__ __volatile__(
		"mcr	p15, 0, %0, c1, c0, 0\n\t" /* enabled cache RAMs */
		"isb\n\t"
		: : "r" (sctlr) : "memory"
	);
}