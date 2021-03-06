/*
 * Freescale USBPHY Register Definitions
 *
 * Copyright 2008-2010 Freescale Semiconductor, Inc. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
 *
 * This file is created by xml file. Don't Edit it.
 *
 * Xml Revision: 1.52
 * Template revision: 26195
 */

#ifndef __ARCH_ARM___USBPHY_H
#define __ARCH_ARM___USBPHY_H


#define HW_USBPHY_PWD	(0x00000000)
#define HW_USBPHY_PWD_SET	(0x00000004)
#define HW_USBPHY_PWD_CLR	(0x00000008)
#define HW_USBPHY_PWD_TOG	(0x0000000c)

#define BP_USBPHY_PWD_RSVD2	21
#define BM_USBPHY_PWD_RSVD2	0xFFE00000
#define BF_USBPHY_PWD_RSVD2(v) \
		(((v) << 21) & BM_USBPHY_PWD_RSVD2)
#define BM_USBPHY_PWD_RXPWDRX	0x00100000
#define BM_USBPHY_PWD_RXPWDDIFF	0x00080000
#define BM_USBPHY_PWD_RXPWD1PT1	0x00040000
#define BM_USBPHY_PWD_RXPWDENV	0x00020000
#define BP_USBPHY_PWD_RSVD1	13
#define BM_USBPHY_PWD_RSVD1	0x0001E000
#define BF_USBPHY_PWD_RSVD1(v)  \
		(((v) << 13) & BM_USBPHY_PWD_RSVD1)
#define BM_USBPHY_PWD_TXPWDV2I	0x00001000
#define BM_USBPHY_PWD_TXPWDIBIAS	0x00000800
#define BM_USBPHY_PWD_TXPWDFS	0x00000400
#define BP_USBPHY_PWD_RSVD0	0
#define BM_USBPHY_PWD_RSVD0	0x000003FF
#define BF_USBPHY_PWD_RSVD0(v)  \
		(((v) << 0) & BM_USBPHY_PWD_RSVD0)

#define HW_USBPHY_TX	(0x00000010)
#define HW_USBPHY_TX_SET	(0x00000014)
#define HW_USBPHY_TX_CLR	(0x00000018)
#define HW_USBPHY_TX_TOG	(0x0000001c)

#define BP_USBPHY_TX_RSVD5	29
#define BM_USBPHY_TX_RSVD5	0xE0000000
#define BF_USBPHY_TX_RSVD5(v) \
		(((v) << 29) & BM_USBPHY_TX_RSVD5)
#define BP_USBPHY_TX_USBPHY_TX_EDGECTRL	26
#define BM_USBPHY_TX_USBPHY_TX_EDGECTRL	0x1C000000
#define BF_USBPHY_TX_USBPHY_TX_EDGECTRL(v)  \
		(((v) << 26) & BM_USBPHY_TX_USBPHY_TX_EDGECTRL)
#define BM_USBPHY_TX_USBPHY_TX_SYNC_INVERT	0x02000000
#define BM_USBPHY_TX_USBPHY_TX_SYNC_MUX	0x01000000
#define BP_USBPHY_TX_RSVD4	22
#define BM_USBPHY_TX_RSVD4	0x00C00000
#define BF_USBPHY_TX_RSVD4(v)  \
		(((v) << 22) & BM_USBPHY_TX_RSVD4)
#define BM_USBPHY_TX_TXENCAL45DP	0x00200000
#define BM_USBPHY_TX_RSVD3	0x00100000
#define BP_USBPHY_TX_TXCAL45DP	16
#define BM_USBPHY_TX_TXCAL45DP	0x000F0000
#define BF_USBPHY_TX_TXCAL45DP(v)  \
		(((v) << 16) & BM_USBPHY_TX_TXCAL45DP)
#define BP_USBPHY_TX_RSVD2	14
#define BM_USBPHY_TX_RSVD2	0x0000C000
#define BF_USBPHY_TX_RSVD2(v)  \
		(((v) << 14) & BM_USBPHY_TX_RSVD2)
#define BM_USBPHY_TX_TXENCAL45DN	0x00002000
#define BM_USBPHY_TX_RSVD1	0x00001000
#define BP_USBPHY_TX_TXCAL45DN	8
#define BM_USBPHY_TX_TXCAL45DN	0x00000F00
#define BF_USBPHY_TX_TXCAL45DN(v)  \
		(((v) << 8) & BM_USBPHY_TX_TXCAL45DN)
#define BP_USBPHY_TX_RSVD0	4
#define BM_USBPHY_TX_RSVD0	0x000000F0
#define BF_USBPHY_TX_RSVD0(v)  \
		(((v) << 4) & BM_USBPHY_TX_RSVD0)
#define BP_USBPHY_TX_D_CAL	0
#define BM_USBPHY_TX_D_CAL	0x0000000F
#define BF_USBPHY_TX_D_CAL(v)  \
		(((v) << 0) & BM_USBPHY_TX_D_CAL)

#define HW_USBPHY_RX	(0x00000020)
#define HW_USBPHY_RX_SET	(0x00000024)
#define HW_USBPHY_RX_CLR	(0x00000028)
#define HW_USBPHY_RX_TOG	(0x0000002c)

#define BP_USBPHY_RX_RSVD2	23
#define BM_USBPHY_RX_RSVD2	0xFF800000
#define BF_USBPHY_RX_RSVD2(v) \
		(((v) << 23) & BM_USBPHY_RX_RSVD2)
#define BM_USBPHY_RX_RXDBYPASS	0x00400000
#define BP_USBPHY_RX_RSVD1	7
#define BM_USBPHY_RX_RSVD1	0x003FFF80
#define BF_USBPHY_RX_RSVD1(v)  \
		(((v) << 7) & BM_USBPHY_RX_RSVD1)
#define BP_USBPHY_RX_DISCONADJ	4
#define BM_USBPHY_RX_DISCONADJ	0x00000070
#define BF_USBPHY_RX_DISCONADJ(v)  \
		(((v) << 4) & BM_USBPHY_RX_DISCONADJ)
#define BM_USBPHY_RX_RSVD0	0x00000008
#define BP_USBPHY_RX_ENVADJ	0
#define BM_USBPHY_RX_ENVADJ	0x00000007
#define BF_USBPHY_RX_ENVADJ(v)  \
		(((v) << 0) & BM_USBPHY_RX_ENVADJ)

#define HW_USBPHY_CTRL	(0x00000030)
#define HW_USBPHY_CTRL_SET	(0x00000034)
#define HW_USBPHY_CTRL_CLR	(0x00000038)
#define HW_USBPHY_CTRL_TOG	(0x0000003c)

#define BM_USBPHY_CTRL_SFTRST	0x80000000
#define BM_USBPHY_CTRL_CLKGATE	0x40000000
#define BM_USBPHY_CTRL_UTMI_SUSPENDM	0x20000000
#define BM_USBPHY_CTRL_HOST_FORCE_LS_SE0	0x10000000
#define BM_USBPHY_CTRL_RSVD3	0x08000000
#define BM_USBPHY_CTRL_ENAUTOSET_USBCLKS	0x04000000
#define BM_USBPHY_CTRL_ENAUTOCLR_USBCLKGATE	0x02000000
#define BM_USBPHY_CTRL_FSDLL_RST_EN	0x01000000
#define BM_USBPHY_CTRL_ENVBUSCHG_WKUP	0x00800000
#define BM_USBPHY_CTRL_ENIDCHG_WKUP	0x00400000
#define BM_USBPHY_CTRL_ENDPDMCHG_WKUP	0x00200000
#define BM_USBPHY_CTRL_ENAUTOCLR_PHY_PWD	0x00100000
#define BM_USBPHY_CTRL_ENAUTOCLR_CLKGATE	0x00080000
#define BM_USBPHY_CTRL_ENAUTO_PWRON_PLL	0x00040000
#define BM_USBPHY_CTRL_WAKEUP_IRQ	0x00020000
#define BM_USBPHY_CTRL_ENIRQWAKEUP	0x00010000
#define BM_USBPHY_CTRL_ENUTMILEVEL3	0x00008000
#define BM_USBPHY_CTRL_ENUTMILEVEL2	0x00004000
#define BM_USBPHY_CTRL_DATA_ON_LRADC	0x00002000
#define BM_USBPHY_CTRL_DEVPLUGIN_IRQ	0x00001000
#define BM_USBPHY_CTRL_ENIRQDEVPLUGIN	0x00000800
#define BM_USBPHY_CTRL_RESUME_IRQ	0x00000400
#define BM_USBPHY_CTRL_ENIRQRESUMEDETECT	0x00000200
#define BM_USBPHY_CTRL_RESUMEIRQSTICKY	0x00000100
#define BM_USBPHY_CTRL_ENOTGIDDETECT	0x00000080
#define BM_USBPHY_CTRL_RSVD1	0x00000040
#define BM_USBPHY_CTRL_DEVPLUGIN_POLARITY	0x00000020
#define BM_USBPHY_CTRL_ENDEVPLUGINDETECT	0x00000010
#define BM_USBPHY_CTRL_HOSTDISCONDETECT_IRQ	0x00000008
#define BM_USBPHY_CTRL_ENIRQHOSTDISCON	0x00000004
#define BM_USBPHY_CTRL_ENHOSTDISCONDETECT	0x00000002
#define BM_USBPHY_CTRL_RSVD0	0x00000001

#define HW_USBPHY_STATUS	(0x00000040)

#define BP_USBPHY_STATUS_RSVD4	11
#define BM_USBPHY_STATUS_RSVD4	0xFFFFF800
#define BF_USBPHY_STATUS_RSVD4(v) \
		(((v) << 11) & BM_USBPHY_STATUS_RSVD4)
#define BM_USBPHY_STATUS_RESUME_STATUS	0x00000400
#define BM_USBPHY_STATUS_RSVD3	0x00000200
#define BM_USBPHY_STATUS_OTGID_STATUS	0x00000100
#define BM_USBPHY_STATUS_RSVD2	0x00000080
#define BM_USBPHY_STATUS_DEVPLUGIN_STATUS	0x00000040
#define BP_USBPHY_STATUS_RSVD1	4
#define BM_USBPHY_STATUS_RSVD1	0x00000030
#define BF_USBPHY_STATUS_RSVD1(v)  \
		(((v) << 4) & BM_USBPHY_STATUS_RSVD1)
#define BM_USBPHY_STATUS_HOSTDISCONDETECT_STATUS	0x00000008
#define BP_USBPHY_STATUS_RSVD0	0
#define BM_USBPHY_STATUS_RSVD0	0x00000007
#define BF_USBPHY_STATUS_RSVD0(v)  \
		(((v) << 0) & BM_USBPHY_STATUS_RSVD0)

#define HW_USBPHY_DEBUG	(0x00000050)
#define HW_USBPHY_DEBUG_SET	(0x00000054)
#define HW_USBPHY_DEBUG_CLR	(0x00000058)
#define HW_USBPHY_DEBUG_TOG	(0x0000005c)

#define BM_USBPHY_DEBUG_RSVD3	0x80000000
#define BM_USBPHY_DEBUG_CLKGATE	0x40000000
#define BM_USBPHY_DEBUG_HOST_RESUME_DEBUG	0x20000000
#define BP_USBPHY_DEBUG_SQUELCHRESETLENGTH	25
#define BM_USBPHY_DEBUG_SQUELCHRESETLENGTH	0x1E000000
#define BF_USBPHY_DEBUG_SQUELCHRESETLENGTH(v)  \
		(((v) << 25) & BM_USBPHY_DEBUG_SQUELCHRESETLENGTH)
#define BM_USBPHY_DEBUG_ENSQUELCHRESET	0x01000000
#define BP_USBPHY_DEBUG_RSVD2	21
#define BM_USBPHY_DEBUG_RSVD2	0x00E00000
#define BF_USBPHY_DEBUG_RSVD2(v)  \
		(((v) << 21) & BM_USBPHY_DEBUG_RSVD2)
#define BP_USBPHY_DEBUG_SQUELCHRESETCOUNT	16
#define BM_USBPHY_DEBUG_SQUELCHRESETCOUNT	0x001F0000
#define BF_USBPHY_DEBUG_SQUELCHRESETCOUNT(v)  \
		(((v) << 16) & BM_USBPHY_DEBUG_SQUELCHRESETCOUNT)
#define BP_USBPHY_DEBUG_RSVD1	13
#define BM_USBPHY_DEBUG_RSVD1	0x0000E000
#define BF_USBPHY_DEBUG_RSVD1(v)  \
		(((v) << 13) & BM_USBPHY_DEBUG_RSVD1)
#define BM_USBPHY_DEBUG_ENTX2RXCOUNT	0x00001000
#define BP_USBPHY_DEBUG_TX2RXCOUNT	8
#define BM_USBPHY_DEBUG_TX2RXCOUNT	0x00000F00
#define BF_USBPHY_DEBUG_TX2RXCOUNT(v)  \
		(((v) << 8) & BM_USBPHY_DEBUG_TX2RXCOUNT)
#define BP_USBPHY_DEBUG_RSVD0	6
#define BM_USBPHY_DEBUG_RSVD0	0x000000C0
#define BF_USBPHY_DEBUG_RSVD0(v)  \
		(((v) << 6) & BM_USBPHY_DEBUG_RSVD0)
#define BP_USBPHY_DEBUG_ENHSTPULLDOWN	4
#define BM_USBPHY_DEBUG_ENHSTPULLDOWN	0x00000030
#define BF_USBPHY_DEBUG_ENHSTPULLDOWN(v)  \
		(((v) << 4) & BM_USBPHY_DEBUG_ENHSTPULLDOWN)
#define BP_USBPHY_DEBUG_HSTPULLDOWN	2
#define BM_USBPHY_DEBUG_HSTPULLDOWN	0x0000000C
#define BF_USBPHY_DEBUG_HSTPULLDOWN(v)  \
		(((v) << 2) & BM_USBPHY_DEBUG_HSTPULLDOWN)
#define BM_USBPHY_DEBUG_DEBUG_INTERFACE_HOLD	0x00000002
#define BM_USBPHY_DEBUG_OTGIDPIOLOCK	0x00000001

#define HW_USBPHY_DEBUG0_STATUS	(0x00000060)

#define BP_USBPHY_DEBUG0_STATUS_SQUELCH_COUNT	26
#define BM_USBPHY_DEBUG0_STATUS_SQUELCH_COUNT	0xFC000000
#define BF_USBPHY_DEBUG0_STATUS_SQUELCH_COUNT(v) \
		(((v) << 26) & BM_USBPHY_DEBUG0_STATUS_SQUELCH_COUNT)
#define BP_USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT	16
#define BM_USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT	0x03FF0000
#define BF_USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT(v)  \
		(((v) << 16) & BM_USBPHY_DEBUG0_STATUS_UTMI_RXERROR_FAIL_COUNT)
#define BP_USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT	0
#define BM_USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT	0x0000FFFF
#define BF_USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT(v)  \
		(((v) << 0) & BM_USBPHY_DEBUG0_STATUS_LOOP_BACK_FAIL_COUNT)

#define HW_USBPHY_DEBUG1	(0x00000070)
#define HW_USBPHY_DEBUG1_SET	(0x00000074)
#define HW_USBPHY_DEBUG1_CLR	(0x00000078)
#define HW_USBPHY_DEBUG1_TOG	(0x0000007c)

#define BP_USBPHY_DEBUG1_RSVD1	15
#define BM_USBPHY_DEBUG1_RSVD1	0xFFFF8000
#define BF_USBPHY_DEBUG1_RSVD1(v) \
		(((v) << 15) & BM_USBPHY_DEBUG1_RSVD1)
#define BP_USBPHY_DEBUG1_ENTAILADJVD	13
#define BM_USBPHY_DEBUG1_ENTAILADJVD	0x00006000
#define BF_USBPHY_DEBUG1_ENTAILADJVD(v)  \
		(((v) << 13) & BM_USBPHY_DEBUG1_ENTAILADJVD)
#define BM_USBPHY_DEBUG1_ENTX2TX	0x00001000
#define BP_USBPHY_DEBUG1_RSVD0	4
#define BM_USBPHY_DEBUG1_RSVD0	0x00000FF0
#define BF_USBPHY_DEBUG1_RSVD0(v)  \
		(((v) << 4) & BM_USBPHY_DEBUG1_RSVD0)
#define BP_USBPHY_DEBUG1_DBG_ADDRESS	0
#define BM_USBPHY_DEBUG1_DBG_ADDRESS	0x0000000F
#define BF_USBPHY_DEBUG1_DBG_ADDRESS(v)  \
		(((v) << 0) & BM_USBPHY_DEBUG1_DBG_ADDRESS)

#define HW_USBPHY_VERSION	(0x00000080)

#define BP_USBPHY_VERSION_MAJOR	24
#define BM_USBPHY_VERSION_MAJOR	0xFF000000
#define BF_USBPHY_VERSION_MAJOR(v) \
		(((v) << 24) & BM_USBPHY_VERSION_MAJOR)
#define BP_USBPHY_VERSION_MINOR	16
#define BM_USBPHY_VERSION_MINOR	0x00FF0000
#define BF_USBPHY_VERSION_MINOR(v)  \
		(((v) << 16) & BM_USBPHY_VERSION_MINOR)
#define BP_USBPHY_VERSION_STEP	0
#define BM_USBPHY_VERSION_STEP	0x0000FFFF
#define BF_USBPHY_VERSION_STEP(v)  \
		(((v) << 0) & BM_USBPHY_VERSION_STEP)

#define HW_USBPHY_IP	(0x00000090)
#define HW_USBPHY_IP_SET	(0x00000094)
#define HW_USBPHY_IP_CLR	(0x00000098)
#define HW_USBPHY_IP_TOG	(0x0000009c)

#define BP_USBPHY_IP_RSVD1	25
#define BM_USBPHY_IP_RSVD1	0xFE000000
#define BF_USBPHY_IP_RSVD1(v) \
		(((v) << 25) & BM_USBPHY_IP_RSVD1)
#define BP_USBPHY_IP_DIV_SEL	23
#define BM_USBPHY_IP_DIV_SEL	0x01800000
#define BF_USBPHY_IP_DIV_SEL(v)  \
		(((v) << 23) & BM_USBPHY_IP_DIV_SEL)
#define BV_USBPHY_IP_DIV_SEL__DEFAULT   0x0
#define BV_USBPHY_IP_DIV_SEL__LOWER     0x1
#define BV_USBPHY_IP_DIV_SEL__LOWEST    0x2
#define BV_USBPHY_IP_DIV_SEL__UNDEFINED 0x3
#define BP_USBPHY_IP_LFR_SEL	21
#define BM_USBPHY_IP_LFR_SEL	0x00600000
#define BF_USBPHY_IP_LFR_SEL(v)  \
		(((v) << 21) & BM_USBPHY_IP_LFR_SEL)
#define BV_USBPHY_IP_LFR_SEL__DEFAULT   0x0
#define BV_USBPHY_IP_LFR_SEL__TIMES_2   0x1
#define BV_USBPHY_IP_LFR_SEL__TIMES_05  0x2
#define BV_USBPHY_IP_LFR_SEL__UNDEFINED 0x3
#define BP_USBPHY_IP_CP_SEL	19
#define BM_USBPHY_IP_CP_SEL	0x00180000
#define BF_USBPHY_IP_CP_SEL(v)  \
		(((v) << 19) & BM_USBPHY_IP_CP_SEL)
#define BV_USBPHY_IP_CP_SEL__DEFAULT   0x0
#define BV_USBPHY_IP_CP_SEL__TIMES_2   0x1
#define BV_USBPHY_IP_CP_SEL__TIMES_05  0x2
#define BV_USBPHY_IP_CP_SEL__UNDEFINED 0x3
#define BM_USBPHY_IP_TSTI_TX_DP	0x00040000
#define BM_USBPHY_IP_TSTI_TX_DM	0x00020000
#define BM_USBPHY_IP_ANALOG_TESTMODE	0x00010000
#define BP_USBPHY_IP_RSVD0	3
#define BM_USBPHY_IP_RSVD0	0x0000FFF8
#define BF_USBPHY_IP_RSVD0(v)  \
		(((v) << 3) & BM_USBPHY_IP_RSVD0)
#define BM_USBPHY_IP_EN_USB_CLKS	0x00000004
#define BM_USBPHY_IP_PLL_LOCKED	0x00000002
#define BM_USBPHY_IP_PLL_POWER	0x00000001
#endif /* __ARCH_ARM___USBPHY_H */
