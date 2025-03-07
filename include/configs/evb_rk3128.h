/*
 * (C) Copyright 2017 Rockchip Electronics Co., Ltd
 *
 * SPDX-License-Identifier:     GPL-2.0+
 */

#ifndef __EVB_RK3128_H
#define __EVB_RK3128_H

#include <configs/rk3128_common.h>

#define CONFIG_ENV_IS_IN_MMC
#define CONFIG_SYS_MMC_ENV_DEV 1
/*
 * SPL @ 32k for ~36k
 * ENV @ 96k
 * u-boot @ 128K
 */
#define CONFIG_ENV_OFFSET (96 * 1024)

#define SDRAM_BANK_SIZE			(2UL << 30)

#define CONFIG_SYS_WHITE_ON_BLACK
#define CONFIG_CONSOLE_SCROLL_LINES		10

#endif
