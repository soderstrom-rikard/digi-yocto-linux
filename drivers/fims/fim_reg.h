/*
 * include/asm-arm/arch-ns9xxx/fim_reg.h
 *
 * Copyright (C) 2008 by Digi International Inc.
 * All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by
 * the Free Software Foundation.
 *
 *  !Revision:   $Revision: 1.8 $
 *  !Author:     Silvano Najera, Luis Galdos
 *  !Descr:
 *  !References:
 */


#ifndef __FIM_REG_H
#define __FIM_REG_H


/* @FIXME: We must use the IOHUB base address*/
#define NS92XX_FIM_IOHUB_BASE_PA		(0x90000000)
#define NS92XX_FIM_IOHUB_SIZE			(0x1000)
#define NS92XX_FIM_IOHUB_OFFSET			(0x8000)


/* Base addresses of all memory regions */
#define NS92XX_FIM_REG_BASE_PA			(0x90001000)
#define NS92XX_FIM_REG_OFFSET			(0x8000)
#define NS92XX_FIM_REG_SIZE                     (0x3000)

#define NS92XX_FIM_INSTR_BASE_PA		(0x90004000)
#define NS92XX_FIM_INSTR_OFFSET			(0x8000)
#define NS92XX_FIM_INSTR_SIZE                   (0x5000)

#define NS92XX_FIM_HWA_BASE_PA			(0x90068000)
#define NS92XX_FIM_HWA_OFFSET			(0x8000)
#define NS92XX_FIM_HWA_SIZE                     (0x8000)

#define NS92XX_FIM_IO_SPACE_BASE_PA		(0x90078000)
#define NS92XX_FIM_IO_SPACE_OFFSET		(0x8000)
#define NS92XX_FIM_IO_SPACE_SIZE                (0x8000)


/* FIM register offsets */
#define NS92XX_FIM_GEN_CTRL_REG			(0x00)

#define NS92XX_FIM_CTRL0_REG			(0x10)
#define NS92XX_FIM_CTRL1_REG			(0x14)
#define NS92XX_FIM_CTRL2_REG			(0x18)
#define NS92XX_FIM_CTRL3_REG			(0x1c)
#define NS92XX_FIM_CTRL4_REG			(0x20)
#define NS92XX_FIM_CTRL5_REG			(0x24)
#define NS92XX_FIM_CTRL6_REG			(0x28)
#define NS92XX_FIM_CTRL7_REG			(0x2c)
#define NS92XX_FIM_CTRL8_REG			(0x30)
#define NS92XX_FIM_CTRL9_REG			(0x34)
#define NS92XX_FIM_CTRL10_REG			(0x38)
#define NS92XX_FIM_CTRL11_REG			(0x3c)
#define NS92XX_FIM_CTRL12_REG			(0x40)
#define NS92XX_FIM_CTRL13_REG			(0x44)
#define NS92XX_FIM_CTRL14_REG			(0x48)
#define NS92XX_FIM_CTRL15_REG			(0x4c)
#define NS92XX_FIM_CTRL_REG(i)			(NS92XX_FIM_CTRL0_REG + 4*i)
#define NS92XX_FIM_CTRL_REG_CHECK(i)		((i<0 || i>15)?1:0)


/*
 * According to the HW-reference manual of the FIMs (page 16)
 * The macros have as offset the address 0x90001000 (NS92XX_FIM_REG_BASE_PA)
 */
#define NS92XX_FIM_STAT0_REG			(0x50)
#define NS92XX_FIM_STAT1_REG			(0x54)
#define NS92XX_FIM_STAT2_REG			(0x58)
#define NS92XX_FIM_STAT3_REG			(0x5c)
#define NS92XX_FIM_STAT4_REG			(0x60)
#define NS92XX_FIM_STAT5_REG			(0x64)
#define NS92XX_FIM_STAT6_REG			(0x68)
#define NS92XX_FIM_STAT7_REG			(0x6c)
#define NS92XX_FIM_STAT8_REG			(0x70)
#define NS92XX_FIM_STAT9_REG			(0x74)
#define NS92XX_FIM_STAT10_REG			(0x78)
#define NS92XX_FIM_STAT11_REG			(0x7c)
#define NS92XX_FIM_STAT12_REG			(0x80)
#define NS92XX_FIM_STAT13_REG			(0x84)
#define NS92XX_FIM_STAT14_REG			(0x88)
#define NS92XX_FIM_STAT_REG(i)			(NS92XX_FIM_STAT0_REG + 4*i)
#define NS92XX_FIM_STAT_REG_CHECK(i)		((i<0 || i>14)?1:0)


/*
 * According to the HW-reference manual of the FIMs (page 16)
 * The macros have as offset the address 0x90001000 (NS92XX_FIM_REG_BASE_PA)
 */
#define NS92XX_FIM_EXP0_REG			(0x50)
#define NS92XX_FIM_EXP1_REG			(0x54)
#define NS92XX_FIM_EXP2_REG			(0x58)
#define NS92XX_FIM_EXP3_REG			(0x5c)
#define NS92XX_FIM_EXP4_REG			(0x60)
#define NS92XX_FIM_EXP5_REG			(0x64)
#define NS92XX_FIM_EXP6_REG			(0x68)
#define NS92XX_FIM_EXP7_REG			(0x6c)
#define NS92XX_FIM_EXP8_REG			(0x70)
#define NS92XX_FIM_EXP9_REG			(0x74)
#define NS92XX_FIM_EXP10_REG			(0x78)
#define NS92XX_FIM_EXP11_REG			(0x7c)
#define NS92XX_FIM_EXP12_REG			(0x80)
#define NS92XX_FIM_EXP13_REG			(0x84)
#define NS92XX_FIM_EXP14_REG			(0x88)
#define NS92XX_FIM_EXP15_REG			(0x8c)
#define NS92XX_FIM_EXP_REG(i)			(NS92XX_FIM_EXP0_REG + 4*i)
#define NS92XX_FIM_EXP_REG_CHECK(i)		((i<0 || i>15)?1:0)


/* FIM intruction memory offset */
#define NS92XX_FIM_INSTRUCTION_ADDR		(0x00)

/* Hardware assist register offsets */
#define NS92XX_FIM_HWA_GEN_CONF_REG		(0x00)

#define NS92XX_FIM_HWA_SIGNAL0			(0x04)
#define NS92XX_FIM_HWA_SIGNAL1			(0x08)
#define NS92XX_FIM_HWA_SIGNAL2			(0x0c)
#define NS92XX_FIM_HWA_SIGNAL3			(0x10)
#define NS92XX_FIM_HWA_SIGNAL4			(0x14)
#define NS92XX_FIM_HWA_SIGNAL5			(0x18)
#define NS92XX_FIM_HWA_SIGNAL6			(0x1c)
#define NS92XX_FIM_HWA_SIGNAL7			(0x20)
#define NS92XX_FIM_HWA_CONTROL0			(0x24)
#define NS92XX_FIM_HWA_CONTROL1			(0x28)
#define NS92XX_FIM_HWA_CONTROL2			(0x2c)
#define NS92XX_FIM_HWA_CONTROL3			(0x30)
#define NS92XX_FIM_HWA_16_BIT_BUS		(0x34)
#define NS92XX_FIM_HWA_32_BIT_BUS		(0x38)
#define NS92XX_FIM_HWA_SIGNAL(index)		(NS92XX_FIM_HWA_GEN_CONF_REG + NS92XX_FIM_HWA_SIGNAL0 + 4*index)


/* Fim register bit fields */
#define NS92XX_FIM_GEN_CTRL_PROGMEM		(0x80000000)
#define NS92XX_FIM_GEN_CTRL_RESERVED1		(0x7fff0000)
#define NS92XX_FIM_GEN_CTRL_INTACKWR		(0x00008000)
#define NS92XX_FIM_GEN_CTRL_INTTOPIC		(0x00007f00)
#define NS92XX_FIM_GEN_CTRL_INTACKRD		(0x00000080)
#define NS92XX_FIM_GEN_CTRL_INTFROMPIC		(0x0000007f)

/* Mask used for the interrupt codes from the ARM to the PICs */
#define NS92XX_FIM_INT_MASK(code)		(code<<8)


/* FIM intructions bit fields*/
#define NS92XX_FIM_INSTRUCTION_MASK		(0x00003fff)

/* Hardware assist register bit fields */
#define NS92XX_FIM_HWA_GEN_CONF_RESERVED1	(0xffffffe0)
#define NS92XX_FIM_HWA_GEN_CONF_CLKSEL		(0x0000001c)
#define NS92XX_FIM_HWA_GEN_CONF_ENABLE		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL0_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL0_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL0_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL0_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL0_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL0_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL1_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL1_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL1_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL1_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL1_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL1_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL2_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL2_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL2_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL2_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL2_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL2_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL3_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL3_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL3_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL3_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL3_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL3_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL4_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL4_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL4_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL4_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL4_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL4_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL5_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL5_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL5_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL5_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL5_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL5_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL6_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL6_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL6_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL6_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL6_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL6_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_SIGNAL7_RESERVED		(0xfffffc00)
#define NS92XX_FIM_HWA_SIGNAL7_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_SIGNAL7_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_SIGNAL7_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_SIGNAL7_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_SIGNAL7_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_CONTROL0_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_CONTROL0_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_CONTROL0_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_CONTROL0_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_CONTROL0_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_CONTROL0_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_CONTROL1_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_CONTROL1_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_CONTROL1_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_CONTROL1_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_CONTROL1_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_CONTROL1_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_CONTROL2_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_CONTROL2_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_CONTROL2_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_CONTROL2_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_CONTROL2_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_CONTROL2_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_CONTROL3_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_CONTROL3_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_CONTROL3_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_CONTROL3_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_CONTROL3_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_CONTROL3_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_16_BIT_BUS_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_16_BIT_BUS_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_16_BIT_BUS_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_16_BIT_BUS_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_16_BIT_BUS_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_16_BIT_BUS_CLKS		(0x00000003)

#define NS92XX_FIM_HWA_32_BIT_BUS_RESERVED	(0xfffffc00)
#define NS92XX_FIM_HWA_32_BIT_BUS_OMODE		(0x00000300)
#define NS92XX_FIM_HWA_32_BIT_BUS_IMODE		(0x000000e0)
#define NS92XX_FIM_HWA_32_BIT_BUS_CLKE		(0x00000010)
#define NS92XX_FIM_HWA_32_BIT_BUS_CNTRL		(0x0000000c)
#define NS92XX_FIM_HWA_32_BIT_BUS_CLKS		(0x00000003)



/* H/W Assist General Configuration Register Codes */
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_2	(0)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_4	(1<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_8	(2<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_16	(3<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_32	(4<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_64	(5<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_128	(6<<2)
#define FIM_HWA_GEN_CFG_CLKSEL_DIVIDE_BY_256	(7<<2)



#endif	/* __FIM_REG_H */








