/*
 * Copyright (c) 2016-2017, NVIDIA CORPORATION.  All rights reserved.
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

#include <address_map_new.h>
#include <artke_top.h>

#include <irqs-hw.h>
#include <wdt-tegra-priv.h>
#include <wdt-tegra-hw.h>

struct tegra_wdt tegra_wdt_ape = {
	.id = {
		.devname = "atke-wdt",
		.base_addr = NV_ADDRESS_MAP_APE_TKE_WDT_BASE,
		.irq = NV_APE_AGIC_INTR_ID_ATKE_WDT_IRQ,
		.fiq = NV_APE_AGIC_INTR_ID_ATKE_WDT_FIQ,
	},
};
extern const struct tegra_wdt_id tegra_wdt_id_ape __attribute__((alias("tegra_wdt_ape")));

struct tegra_wdt tegra_wdt_top2 = {
	.id = {
		.devname = "top-wdt2",
		.base_addr = NV_ADDRESS_MAP_TOP_TKE_WDT_BASE
			+ TKE_TOP_WDT2_WDTCR_0 - TKE_TOP_WDT0_WDTCR_0,
		.irq = NV_APE_AGIC_INTR_ID_TOP_WDT_IRQ,
		.fiq = NV_APE_AGIC_INTR_ID_TOP_WDT_FIQ,
	},
};
extern const struct tegra_wdt_id tegra_wdt_id_top2 __attribute__((alias("tegra_wdt_top2")));
