/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#include <common.h>
#include <debug_uart.h>
#include <asm/io.h>
#include <asm/arch/bootrom.h>
#include <asm/arch/grf_rk3128.h>
#include <asm/arch/hardware.h>
#include <asm/arch/sdram_rk3128.h>
#include <asm/arch/timer.h>
#include <asm/arch/uart.h>

DECLARE_GLOBAL_DATA_PTR;

#define GRF_BASE	0x20008000
static struct rk3128_grf * const grf = (void *)GRF_BASE;

#define DEBUG_UART_BASE	0x20068000

void board_init_f(ulong dummy)
{
#ifdef EARLY_DEBUG
	/*
	 * NOTE: sd card and debug uart use same iomux in rk3128,
	 * so if you enable uart,
	 * you can not boot from sdcard
	 */
	rk_clrsetreg(&grf->gpio1c_iomux,
		     GPIO1C3_MASK << GPIO1C3_SHIFT |
		     GPIO1C2_MASK << GPIO1C2_SHIFT,
		     GPIO1C3_UART2_SOUT << GPIO1C3_SHIFT |
		     GPIO1C2_UART2_SIN << GPIO1C2_SHIFT);
	debug_uart_init();
#endif
	puts("rk3128-board-f-init:---------------------------\n");
	rockchip_timer_init();
	sdram_init();

	/* return to maskrom */
	back_to_bootrom();
}

/* Place Holders */
void board_init_r(gd_t *id, ulong dest_addr)
{
	/*
	 * Function attribute is no-return
	 * This Function never executes
	 */
	while (1)
		;
}
/*
void hang(void)
{
	while (1)
		;
}
*/
