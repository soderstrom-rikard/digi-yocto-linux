/*
 * arch/arm/mach-ns9xxx/mach-cc9p9215.c
 *
 * Copyright (C) 2007 by Digi International Inc.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 */
#include <asm/mach/arch.h>
#include <asm/mach-types.h>

#include "irq.h"
#include "processor-ns921x.h"

MACHINE_START(CCW9P9215, "ConnectCore Wi-9P 9215")
	.map_io = ns921x_map_io,
	.init_irq = ns9xxx_init_irq,
	.init_machine = ns921x_init_machine,
	.timer = &ns921x_timer,
	.boot_params = 0x100,
MACHINE_END
