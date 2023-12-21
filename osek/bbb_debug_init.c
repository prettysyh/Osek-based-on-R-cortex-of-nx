/*
 * Copyright (c) 2018 NVIDIA CORPORATION.  All rights reserved.
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


#include <string.h>

#include <barriers.h>
#include <irqs.h>
#include <macros.h>
#include <hsp-tegra.h>
#include <hsp-tegra-hw.h>
#include <tke-tegra.h>
#include <uart-tegra.h>

#include <mbox-aon.h>
#include <combined-uart.h>
#include <combined-uart-priv.h>

#include "config.h"

#define NUM_BYTES_FIELD_BIT	24
#define FLUSH_BIT		26
#define HW_FLUSH_BIT		27
#define DMA_MODE_BIT		30
#define INTR_TRIGGER_BIT	31
#define NUM_BYTES(reg_val)	((reg_val >> NUM_BYTES_FIELD_BIT) & 0x3)

#define TASK_NAME_LEN		32

#define RX_TIMEOUT_MS		100

#define TAG_ESCAPE_CHAR		0xff
#define TAG_ESCAPE_STRING	"\377"

#define TAG_RESET		0xfd
#define TAG_BOOT_RESET_STRING	"\0\377\375"

#if defined(ENABLE_COMBINED_UART_SERVER)

bool combined_uart_inited = false;

extern struct ext_client_id ext_client_ids[COMBINED_UART_NUM_EXT_CLIENTS];

struct tegra_uart_id *combined_uart_id = NULL;
struct tegra_uart_conf combined_uart_conf = {
	.parity = TEGRA_UART_NO_PARITY,
	.stop_bits = TEGRA_UART_STOP_BITS_1,
	.data_bits = TEGRA_UART_DATA_BITS_8,
	.baud = 115200,
};

static struct ext_client_id spe_id = {
	.tag = 0xe0,
};

static const struct ext_client_id *last_id = NULL;


void combined_uart_raw_print(const char *str, size_t len)
{

	if (!combined_uart_inited)
		return;

	tegra_uart_write_now(combined_uart_id, str, len);
		return;
	


}

static void combined_uart_dbg_putc(const char *str, size_t len)
{
	const char *buf, *tag_escape;
	size_t remaining = len;
	size_t current_len;

	buf = str;

	while (remaining) {
		tag_escape = memchr(buf, TAG_ESCAPE_CHAR, remaining);

		if (tag_escape)
			current_len = tag_escape - buf + 1;
		else
			current_len = remaining;

		combined_uart_raw_print(buf, current_len);
		if (buf[current_len - 1] == TAG_ESCAPE_CHAR)
			combined_uart_raw_print(TAG_ESCAPE_STRING, 1);

		buf += current_len;
		remaining -= current_len;
	}
}


void print_msg(const struct ext_client_id *id, const char *msg_buf, size_t len)
{
	char c;

	if (last_id != id) {
		combined_uart_raw_print(TAG_ESCAPE_STRING, 1);
		c = id->tag;
		combined_uart_raw_print(&c, 1);
		last_id = id;
	}

	if (len > 0)
		combined_uart_dbg_putc(msg_buf, len);
}





#endif
