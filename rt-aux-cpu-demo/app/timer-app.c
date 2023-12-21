/*
 * Copyright (c) 2019, NVIDIA CORPORATION.  All rights reserved.
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

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#include <printf-isr.h>
#include <tke-tegra.h>
#include <tke-tegra-hw.h>

#include "timer-app.h"

/* Demo timer app which sets up 5 second periodic timer, modify below define to
 * adjust periodic value of the timer.
 */
#define TIMER2_PTV 5000000
#define STOP_TIMER 10

static void timer2_callback(void *data)
{
	static int count = 0;
	uint32_t usec, osc, tsc_hi, tsc_lo;

	usec = tegra_tke_get_usec();
	osc = tegra_tke_get_osc();
	tegra_tke_get_tsc(&tsc_hi, &tsc_lo);
	printf_isr("Timer2 irq triggered, usec = %lu, osc = %lu "
		   "tsc_hi = %lu, tsc_lo = %lu\r\n", usec, osc, tsc_hi, tsc_lo);
	if (++count > STOP_TIMER)
		tegra_tke_stop_timer(&tegra_tke_id_timer2);

}

void timer_app_init(void)
{
	tegra_tke_set_up_timer(&tegra_tke_id_timer2, TEGRA_TKE_CLK_SRC_USECCNT,
			       true, TIMER2_PTV, timer2_callback, 0);
}
