/*
 * This file is part of the coreboot project.
 *
 * Copyright 2016 Google Inc.
 * Copyright (C) 2017-2018 Siemens AG
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
 * GNU General Public License for more details.
 */

#include <commonlib/helpers.h>
#include <compiler.h>
#include <baseboard/variants.h>

/*
 * Pad configuration in ramstage. The order largely follows the 'GPIO Muxing'
 * table found in EDS vol 1, but some pins aren't grouped functionally in
 * the table so those were moved for more logical grouping.
 */
static const struct pad_config gpio_table[] = {

	/* Southwest Community */

	/* PCIE_WAKE[0:3]_N */
	PAD_CFG_NF(GPIO_205, UP_20K, DEEP, NF1),	/* PCIE_WAKE0_N */
	PAD_CFG_NF(GPIO_206, UP_20K, DEEP, NF1),	/* PCIE_WAKE1_N */
	PAD_CFG_NF(GPIO_207, UP_20K, DEEP, NF1),	/* PCIE_WAKE2_N */
	PAD_CFG_NF(GPIO_208, UP_20K, DEEP, NF1),	/* PCIE_WAKE3_N */

	/* EMMC interface. */
	PAD_CFG_NF(GPIO_156, DN_20K, DEEP, NF1),	/* EMMC_CLK */
	PAD_CFG_NF(GPIO_157, UP_20K, DEEP, NF1),	/* EMMC_D0 */
	PAD_CFG_NF(GPIO_158, UP_20K, DEEP, NF1),	/* EMMC_D1 */
	PAD_CFG_NF(GPIO_159, UP_20K, DEEP, NF1),	/* EMMC_D2 */
	PAD_CFG_NF(GPIO_160, UP_20K, DEEP, NF1),	/* EMMC_D3 */
	PAD_CFG_NF(GPIO_161, UP_20K, DEEP, NF1),	/* EMMC_D4 */
	PAD_CFG_NF(GPIO_162, UP_20K, DEEP, NF1),	/* EMMC_D5 */
	PAD_CFG_NF(GPIO_163, UP_20K, DEEP, NF1),	/* EMMC_D6 */
	PAD_CFG_NF(GPIO_164, UP_20K, DEEP, NF1),	/* EMMC_D7 */
	PAD_CFG_NF(GPIO_165, UP_20K, DEEP, NF1),	/* EMMC_CMD */
	PAD_CFG_NF(GPIO_182, DN_20K, DEEP, NF1),	/* EMMC_RCLK */

	/* SDIO -- unused */
	PAD_CFG_GPI(GPIO_166, DN_20K, DEEP),		/* SDIO_CLK */
	PAD_CFG_GPI(GPIO_167, DN_20K, DEEP),		/* SDIO_D0 */
	/* Configure SDIO to enable power gating. */
	PAD_CFG_GPI(GPIO_168, DN_20K, DEEP),		/* SDIO_D1 */
	PAD_CFG_GPI(GPIO_169, DN_20K, DEEP),		/* SDIO_D2 */
	PAD_CFG_GPI(GPIO_170, DN_20K, DEEP),		/* SDIO_D3 */
	PAD_CFG_GPI(GPIO_171, DN_20K, DEEP),		/* SDIO_CMD */

	/* SDCARD */
	/* Pull down clock by 20K. */
	PAD_CFG_NF(GPIO_172, DN_20K, DEEP, NF1),	/* SDCARD_CLK */
	PAD_CFG_NF(GPIO_173, UP_20K, DEEP, NF1),	/* SDCARD_D0 */
	PAD_CFG_NF(GPIO_174, UP_20K, DEEP, NF1),	/* SDCARD_D1 */
	PAD_CFG_NF(GPIO_175, UP_20K, DEEP, NF1),	/* SDCARD_D2 */
	PAD_CFG_NF(GPIO_176, UP_20K, DEEP, NF1),	/* SDCARD_D3 */
	/* Card detect is active LOW with external pull up. */
	PAD_CFG_NF(GPIO_177, UP_20K, DEEP, NF1),	/* SDCARD_CD_N */
	PAD_CFG_NF(GPIO_178, UP_20K, DEEP, NF1),	/* SDCARD_CMD */
	/* CLK feedback, internal signal, needs 20K pull down. */
	PAD_CFG_NF(GPIO_179, DN_20K, DEEP, NF1),	/* SDCARD_CLK_FB */
	PAD_CFG_GPI(GPIO_186, UP_20K, DEEP),		/* SDCARD_LVL_WP */
	/* EN_SD_SOCKET_PWR_L for SD slot power control. Default on. */
	PAD_CFG_GPO(GPIO_183, 1, DEEP),			/* SDIO_PWR_DOWN_N */

	/* SMBus */
	PAD_CFG_GPI(SMB_ALERTB, UP_20K, DEEP),		/* SMB_ALERT _N */
	PAD_CFG_NF(SMB_CLK, UP_20K, DEEP, NF1),		/* SMB_CLK */
	PAD_CFG_NF(SMB_DATA, UP_20K, DEEP, NF1),	/* SMB_DATA */

	/* LPC */
	PAD_CFG_NF(LPC_ILB_SERIRQ, UP_20K, DEEP, NF1),	/* LPC_SERIRQ */
	PAD_CFG_NF(LPC_CLKOUT0, NONE, DEEP, NF1),	/* LPC_CLKOUT0 */
	PAD_CFG_GPI(LPC_CLKOUT1, UP_20K, DEEP),		/* LPC_CLKOUT1 */
	PAD_CFG_NF(LPC_AD0, UP_20K, DEEP, NF1),		/* LPC_AD0 */
	PAD_CFG_NF(LPC_AD1, UP_20K, DEEP, NF1),		/* LPC_AD1 */
	PAD_CFG_NF(LPC_AD2, UP_20K, DEEP, NF1),		/* LPC_AD2 */
	PAD_CFG_NF(LPC_AD3, UP_20K, DEEP, NF1),		/* LPC_AD3 */
	PAD_CFG_GPI(LPC_CLKRUNB, UP_20K, DEEP),		/* LPC_CLKRUN_N */
	PAD_CFG_NF(LPC_FRAMEB, UP_20K, DEEP, NF1),	/* LPC_FRAME_N */

	/* West Community */

	/* I2C0 - I2C Level Shifter */
	PAD_CFG_NF(GPIO_124, UP_2K, DEEP, NF1),		/* LPSS_I2C0_SDA */
	PAD_CFG_NF(GPIO_125, UP_2K, DEEP, NF1),		/* LPSS_I2C0_SCL */

	/* I2C[1:7] -- unused */
	PAD_CFG_GPI(GPIO_126, UP_20K, DEEP),		/* LPSS_I2C1_SDA */
	PAD_CFG_GPI(GPIO_127, UP_20K, DEEP),		/* LPSS_I2C1_SCL */
	PAD_CFG_GPI(GPIO_128, UP_20K, DEEP),		/* LPSS_I2C2_SDA */
	PAD_CFG_GPI(GPIO_129, UP_20K, DEEP),		/* LPSS_I2C2_SCL */
	PAD_CFG_GPI(GPIO_130, UP_20K, DEEP),		/* LPSS_I2C3_SDA */
	PAD_CFG_GPI(GPIO_131, UP_20K, DEEP),		/* LPSS_I2C3_SCL */
	PAD_CFG_GPI(GPIO_132, UP_20K, DEEP),		/* LPSS_I2C4_SDA */
	PAD_CFG_GPI(GPIO_133, UP_20K, DEEP),		/* LPSS_I2C4_SCL */
	PAD_CFG_GPI(GPIO_134, UP_20K, DEEP),		/* LPSS_I2C5_SDA */
	PAD_CFG_GPI(GPIO_135, UP_20K, DEEP),		/* LPSS_I2C5_SCL */
	PAD_CFG_GPI(GPIO_136, UP_20K, DEEP),		/* LPSS_I2C6_SDA */
	PAD_CFG_GPI(GPIO_137, UP_20K, DEEP),		/* LPSS_I2C6_SCL */
	PAD_CFG_GPI(GPIO_138, UP_20K, DEEP),		/* LPSS_I2C7_SDA */
	PAD_CFG_GPI(GPIO_139, UP_20K, DEEP),		/* LPSS_I2C7_SCL */

	/* ISH_GPIO_[0:9] -- unused */
	PAD_CFG_GPI(GPIO_146, DN_20K, DEEP),		/* ISH_GPIO_0 */
	PAD_CFG_GPI(GPIO_147, DN_20K, DEEP),		/* ISH_GPIO_1 */
	PAD_CFG_GPI(GPIO_148, DN_20K, DEEP),		/* ISH_GPIO_2 */
	PAD_CFG_GPI(GPIO_149, DN_20K, DEEP),		/* ISH_GPIO_3 */
	PAD_CFG_GPI(GPIO_150, DN_20K, DEEP),		/* ISH_GPIO_4 */
	PAD_CFG_GPI(GPIO_151, DN_20K, DEEP),		/* ISH_GPIO_5 */
	PAD_CFG_GPI(GPIO_152, DN_20K, DEEP),		/* ISH_GPIO_6 */
	PAD_CFG_GPI(GPIO_153, DN_20K, DEEP),		/* ISH_GPIO_7 */
	PAD_CFG_GPI(GPIO_154, DN_20K, DEEP),		/* ISH_GPIO_8 */
	PAD_CFG_GPI(GPIO_155, DN_20K, DEEP),		/* ISH_GPIO_9 */

	/* PCIE_CLKREQ[0:3]_N */
	PAD_CFG_NF(GPIO_209, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_210, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_211, UP_20K, DEEP, NF1),
	PAD_CFG_NF(GPIO_212, UP_20K, DEEP, NF1),

	/* OSC_CLK_OUT_0 - RES_CLK_CPU_FPGA */
	PAD_CFG_NF(OSC_CLK_OUT_0, DN_20K, DEEP, NF1),
	/* OSC_CLK_OUT_[1:4] -- unused */
	PAD_CFG_GPI(OSC_CLK_OUT_1, DN_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_2, DN_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_3, DN_20K, DEEP),
	PAD_CFG_GPI(OSC_CLK_OUT_4, DN_20K, DEEP),

	/* PMU Signals */
	PAD_CFG_GPI(PMU_AC_PRESENT, DN_20K, DEEP),	/* PMU_AC_PRESENT */
	PAD_CFG_NF(PMU_BATLOW_B, UP_20K, DEEP, NF1),	/* PMU_BATLOW_N */
	PAD_CFG_NF(PMU_PLTRST_B, NONE, DEEP, NF1),	/* PMU_PLTRST_N */
	PAD_CFG_NF(PMU_PWRBTN_B, UP_20K, DEEP, NF1),	/* PMU_PWRBTN_N */
	PAD_CFG_NF(PMU_RESETBUTTON_B, NONE, DEEP, NF1),	/* PMU_RSTBTN_N */
	/* PMU_SLP_S0_N */
	PAD_CFG_NF_IOSSTATE(PMU_SLP_S0_B, NONE, DEEP, NF1, IGNORE),
	PAD_CFG_NF(PMU_SLP_S3_B, NONE, DEEP, NF1),	/* PMU_SLP_S3_N */
	PAD_CFG_NF(PMU_SLP_S4_B, NONE, DEEP, NF1),	/* PMU_SLP_S4_N */
	PAD_CFG_NF(PMU_SUSCLK, NONE, DEEP, NF1),	/* PMU_SUSCLK */
	PAD_CFG_GPO(PMU_WAKE_B, 1, DEEP),		/* EN_PP3300_EMMC */
	PAD_CFG_NF(SUS_STAT_B, NONE, DEEP, NF1),	/* SUS_STAT_N */
	PAD_CFG_NF(SUSPWRDNACK, NONE, DEEP, NF1),	/* SUSPWRDNACK */

	/* Northwest Community */

	/* DDI0 SDA and SCL -- unused */
	PAD_CFG_GPI(GPIO_187, DN_20K, DEEP),		/* HV_DDI0_DDC_SDA */
	PAD_CFG_GPI(GPIO_188, DN_20K, DEEP),		/* HV_DDI0_DDC_SCL */
	/* DDI1 SDA and SCL - Display-Port */
	PAD_CFG_NF(GPIO_189, UP_20K, DEEP, NF1),	/* HV_DDI1_DDC_SDA */
	PAD_CFG_NF(GPIO_190, UP_20K, DEEP, NF1),	/* HV_DDI1_DDC_SCL */

	/* MIPI I2C -- unused */
	PAD_CFG_GPI(GPIO_191, DN_20K, DEEP),		/* MIPI_I2C_SDA */
	PAD_CFG_GPI(GPIO_192, DN_20K, DEEP),		/* MIPI_I2C_SCL */

	/* Panel 0 control -- unused */
	PAD_CFG_GPI(GPIO_193, DN_20K, DEEP),		/* PNL0_VDDEN */
	PAD_CFG_GPI(GPIO_194, DN_20K, DEEP),		/* PNL0_BKLTEN */
	PAD_CFG_GPI(GPIO_195, DN_20K, DEEP),		/* PNL0_BKLTCTL */

	/* Panel 1 control -- unused */
	PAD_CFG_NF(GPIO_196, DN_20K, DEEP, NF1),	/* PNL1_VDDEN */
	PAD_CFG_NF(GPIO_197, DN_20K, DEEP, NF1),	/* PNL1_BKLTEN */
	PAD_CFG_NF(GPIO_198, DN_20K, DEEP, NF1),	/* PNL1_BKLTCTL */

	/* DDI[0:1]_HPD -- unused */
	PAD_CFG_GPI(GPIO_199, UP_20K, DEEP),		/* XHPD_DP */
	PAD_CFG_GPI(GPIO_200, DN_20K, DEEP),		/* unused */

	/* MDSI signals -- unused */
	PAD_CFG_GPI(GPIO_201, DN_20K, DEEP),		/* MDSI_A_TE */
	PAD_CFG_GPI(GPIO_202, DN_20K, DEEP),		/* MDSI_C_TE */

	/* USB overcurrent pins. */
	PAD_CFG_NF(GPIO_203, UP_20K, DEEP, NF1),	/* USB_OC0_N */
	PAD_CFG_NF(GPIO_204, UP_20K, DEEP, NF1),	/* USB_OC1_N */

	/* PMC SPI -- almost entirely unused. */
	PAD_CFG_GPI(PMC_SPI_FS0, UP_20K, DEEP),
	PAD_CFG_NF(PMC_SPI_FS1, UP_20K, DEEP, NF2),	/* XHPD_EDP_APL */
	PAD_CFG_GPI(PMC_SPI_FS2, UP_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_RXD, DN_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_TXD, DN_20K, DEEP),
	PAD_CFG_GPI(PMC_SPI_CLK, DN_20K, DEEP),

	/* PMIC Signals unused signals related to an old PMIC interface. */
	PAD_CFG_GPO(PMIC_PWRGOOD, 1, DEEP),		/* PMIC_PWRGOOD */
	PAD_CFG_GPI(PMIC_RESET_B, NONE, DEEP),		/* PMIC_RESET_B */
	PAD_CFG_GPI(GPIO_213, DN_20K, DEEP),		/* NFC_OUT_RESERVE */
	PAD_CFG_GPI(GPIO_214, DN_20K, DEEP),		/* NFC_EN */
	PAD_CFG_GPI(GPIO_215, DN_20K, DEEP),		/* NFC_IN_RESERVE */
	/* THERMTRIP_N */
	PAD_CFG_NF(PMIC_THERMTRIP_B, UP_20K, DEEP, NF1),
	PAD_CFG_GPO(PMIC_STDBY, 1, DEEP),		/* unused */
	PAD_CFG_NF(PROCHOT_B, UP_20K, DEEP, NF1),	/* PROCHOT_N */
	PAD_CFG_NF(PMIC_I2C_SCL, UP_1K, DEEP, NF1),	/* PMIC_I2C_SCL */
	PAD_CFG_NF(PMIC_I2C_SDA, UP_1K, DEEP, NF1),	/* PMIC_I2C_SDA */

	/* I2S1 -- unused */
	PAD_CFG_GPI(GPIO_74, DN_20K, DEEP),		/* I2S1_MCLK */
	PAD_CFG_GPI(GPIO_75, DN_20K, DEEP),		/* I2S1_BCLK */
	PAD_CFG_GPI(GPIO_76, DN_20K, DEEP),		/* I2S1_WS_SYNC */
	PAD_CFG_GPI(GPIO_77, DN_20K, DEEP),		/* I2S1_SDI */
	PAD_CFG_GPI(GPIO_78, DN_20K, DEEP),		/* I2S1_SDO */

	/* DMIC or I2S4 -- unused */
	PAD_CFG_GPI(GPIO_79, DN_20K, DEEP),		/* AVS_M_CLK_A1 */
	PAD_CFG_GPI(GPIO_80, DN_20K, DEEP),		/* AVS_M_CLK_B1 */
	PAD_CFG_GPI(GPIO_81, DN_20K, DEEP),		/* AVS_M_DATA_1 */
	PAD_CFG_GPI(GPIO_82, DN_20K, DEEP),		/* AVS_M_CLK_AB2 */
	PAD_CFG_GPI(GPIO_83, DN_20K, DEEP),		/* AVS_M_DATA_2 */

	/* I2S2 -- unused */
	PAD_CFG_GPI(GPIO_84, DN_20K, DEEP),		/* AVS_I2S2_MCLK */
	PAD_CFG_GPI(GPIO_85, DN_20K, DEEP),		/* AVS_I2S2_BCLK */
	PAD_CFG_GPI(GPIO_86, DN_20K, DEEP),		/* AVS_I2S2_WS_SYNC */
	PAD_CFG_GPI(GPIO_87, DN_20K, DEEP),		/* AVS_I2S2_SDI */
	PAD_CFG_GPI(GPIO_88, DN_20K, DEEP),		/* AVS_I2S2_SDO */

	/* I2S3 -- unused */
	PAD_CFG_GPI(GPIO_89, DN_20K, DEEP),		/* AVS_I2S3_BCLK */
	PAD_CFG_GPI(GPIO_90, DN_20K, DEEP),		/* AVS_I2S3_WS_SYNC */
	PAD_CFG_GPI(GPIO_91, DN_20K, DEEP),		/* AVS_I2S3_SDI */
	PAD_CFG_GPI(GPIO_92, DN_20K, DEEP),		/* AVS_I2S3_SDO */

	/* Fast SPI */
	/* FST_SPI_CS0_B */
	PAD_CFG_NF_IOSSTATE(GPIO_97, NATIVE, DEEP, NF1, IGNORE),
	/* FST_SPI_CS1_B -- unused */
	PAD_CFG_GPI(GPIO_98, DN_20K, DEEP),
	/* FST_SPI_MOSI_IO0 */
	PAD_CFG_NF_IOSSTATE(GPIO_99, NATIVE, DEEP, NF1, IGNORE),
	/* FST_SPI_MISO_IO1 */
	PAD_CFG_NF_IOSSTATE(GPIO_100, NATIVE, DEEP, NF1, IGNORE),
	/* FST_IO2 -- MEM_CONFIG0 */
	PAD_CFG_NF(GPIO_101, NATIVE, DEEP, NF1),
	/* FST_IO3 -- MEM_CONFIG1 */
	PAD_CFG_NF(GPIO_102, NATIVE, DEEP, NF1),
	/* FST_SPI_CLK */
	PAD_CFG_NF_IOSSTATE(GPIO_103, NATIVE, DEEP, NF1, IGNORE),
	/* FST_SPI_CLK_FB */
	PAD_CFG_NF_IOSSTATE(FST_SPI_CLK_FB, NATIVE, DEEP, NF1, IGNORE),

	/* SIO_SPI_0 -- unused */
	PAD_CFG_GPI(GPIO_104, DN_20K, DEEP),		/* GP_SSP_0_CLK */
	PAD_CFG_GPI(GPIO_105, DN_20K, DEEP),		/* GP_SSP_0_FS0 */
	PAD_CFG_GPI(GPIO_106, UP_20K, DEEP),		/* GP_SSP_0_FS1 */
	PAD_CFG_GPI(GPIO_109, DN_20K, DEEP),		/* GP_SSP_0_RXD */
	PAD_CFG_GPI(GPIO_110, DN_20K, DEEP),		/* GP_SSP_0_TXD */

	/* SIO_SPI_1 -- unused */
	PAD_CFG_GPI(GPIO_111, DN_20K, DEEP),		/* GP_SSP_1_CLK */
	PAD_CFG_GPI(GPIO_112, DN_20K, DEEP),		/* GP_SSP_1_FS0 */
	PAD_CFG_GPI(GPIO_113, DN_20K, DEEP),		/* GP_SSP_1_FS1 */
	PAD_CFG_GPI(GPIO_116, DN_20K, DEEP),		/* GP_SSP_1_RXD */
	PAD_CFG_GPI(GPIO_117, DN_20K, DEEP),		/* GP_SSP_1_TXD */

	/* SIO_SPI_2 -- unused */
	PAD_CFG_GPI(GPIO_118, DN_20K, DEEP),		/* GP_SSP_2_CLK */
	PAD_CFG_GPI(GPIO_119, DN_20K, DEEP),		/* GP_SSP_2_FS0 */
	PAD_CFG_GPI(GPIO_120, DN_20K, DEEP),		/* GP_SSP_2_FS1 */
	PAD_CFG_GPI(GPIO_121, DN_20K, DEEP),		/* GP_SSP_2_FS2 */
	PAD_CFG_GPI(GPIO_122, DN_20K, DEEP),		/* GP_SSP_2_RXD */
	PAD_CFG_GPI(GPIO_123, UP_20K, DEEP),		/* GP_SSP_2_TXD */

	/* North Community */

	/* Debug tracing. */
	PAD_CFG_GPI(GPIO_0, DN_20K, DEEP),	/* TRACE_0_CLK_VNN */
	PAD_CFG_GPI(GPIO_1, DN_20K, DEEP),	/* TRACE_0_DATA0_VNN */
	PAD_CFG_GPI(GPIO_2, DN_20K, DEEP),	/* TRACE_0_DATA1_VNN */
	PAD_CFG_GPI(GPIO_3, DN_20K, DEEP),	/* TRACE_0_DATA2_VNN */
	PAD_CFG_GPI(GPIO_4, DN_20K, DEEP),	/* TRACE_0_DATA3_VNN */
	PAD_CFG_GPI(GPIO_5, DN_20K, DEEP),	/* TRACE_0_DATA4_VNN */
	PAD_CFG_GPI(GPIO_6, DN_20K, DEEP),	/* TRACE_0_DATA5_VNN */
	PAD_CFG_GPI(GPIO_7, DN_20K, DEEP),	/* TRACE_0_DATA6_VNN */
	PAD_CFG_GPI(GPIO_8, DN_20K, DEEP),	/* TRACE_0_DATA7_VNN */

	PAD_CFG_GPI(GPIO_9, DN_20K, DEEP),	/* TRACE_1_CLK_VNN */
	PAD_CFG_GPI(GPIO_10, DN_20K, DEEP),	/* TRACE_1_DATA0_VNN */
	PAD_CFG_GPI(GPIO_11, DN_20K, DEEP),	/* TRACE_1_DATA1_VNN */
	PAD_CFG_GPI(GPIO_12, DN_20K, DEEP),	/* TRACE_1_DATA2_VNN */
	PAD_CFG_GPI(GPIO_13, DN_20K, DEEP),	/* TRACE_1_DATA3_VNN */
	PAD_CFG_GPI(GPIO_14, DN_20K, DEEP),	/* TRACE_1_DATA4_VNN */
	PAD_CFG_GPI(GPIO_15, DN_20K, DEEP),	/* TRACE_1_DATA5_VNN */
	PAD_CFG_GPI(GPIO_16, DN_20K, DEEP),	/* TRACE_1_DATA6_VNN */
	PAD_CFG_GPI(GPIO_17, DN_20K, DEEP),	/* TRACE_1_DATA7_VNN */

	PAD_CFG_GPI(GPIO_18, UP_20K, DEEP),	/* TRACE_2_CLK_VNN */
	PAD_CFG_GPI(GPIO_19, UP_20K, DEEP),	/* TRACE_2_DATA0_VNN */
	PAD_CFG_GPI(GPIO_20, DN_20K, DEEP),	/* TRACE_2_DATA1_VNN */
	PAD_CFG_GPI(GPIO_21, DN_20K, DEEP),	/* TRACE_2_DATA2_VNN */
	PAD_CFG_GPI(GPIO_22, DN_20K, DEEP),	/* TRACE_2_DATA3_VNN */
	PAD_CFG_GPI(GPIO_23, DN_20K, DEEP),	/* TRACE_2_DATA4_VNN */
	PAD_CFG_GPI(GPIO_24, DN_20K, DEEP),	/* TRACE_2_DATA5_VNN */
	PAD_CFG_GPI(GPIO_25, DN_20K, DEEP),	/* TRACE_2_DATA6_VNN */
	PAD_CFG_GPI(GPIO_26, DN_20K, DEEP),	/* TRACE_2_DATA7_VNN */

	PAD_CFG_GPI(GPIO_27, DN_20K, DEEP),	/* TRIGOUT_0 */
	PAD_CFG_GPI(GPIO_28, DN_20K, DEEP),	/* TRIGOUT_1 */
	PAD_CFG_GPI(GPIO_29, DN_20K, DEEP),	/* TRIGIN_0 */

	PAD_CFG_GPI(GPIO_30, DN_20K, DEEP),	/* ISH_GPIO_12 */
	PAD_CFG_GPI(GPIO_31, DN_20K, DEEP),	/* ISH_GPIO_13 */
	PAD_CFG_GPI(GPIO_32, DN_20K, DEEP),	/* ISH_GPIO_14 */
	PAD_CFG_GPI(GPIO_33, DN_20K, DEEP),	/* ISH_GPIO_15 */

	/* PWM[0:3] -- unused */
	PAD_CFG_GPI(GPIO_34, DN_20K, DEEP),
	PAD_CFG_GPI(GPIO_35, DN_20K, DEEP),
	PAD_CFG_GPI(GPIO_36, DN_20K, DEEP),
	PAD_CFG_GPI(GPIO_37, DN_20K, DEEP),

	/* LPSS_UART[0:2] */
	PAD_CFG_GPI(GPIO_38, UP_20K, DEEP),	/* LPSS_UART0_RXD - unused */
	PAD_CFG_GPI(GPIO_39, DN_20K, DEEP),	/* LPSS_UART0_TXD - unused */
	PAD_CFG_GPI(GPIO_40, DN_20K, DEEP),	/* LPSS_UART0_RTS - unused */
	PAD_CFG_GPI(GPIO_41, UP_20K, DEEP),	/* LPSS_UART0_CTS - unused */
	PAD_CFG_GPI(GPIO_42, UP_20K, DEEP),	/* LPSS_UART1_RXD - unused */
	PAD_CFG_GPI(GPIO_43, DN_20K, DEEP),	/* LPSS_UART1_TXD - unused */
	PAD_CFG_GPI(GPIO_44, UP_20K, DEEP),	/* LPSS_UART1_RTS - unused */
	PAD_CFG_GPI(GPIO_45, UP_20K, DEEP),	/* LPSS_UART1_CTS - unused */
	PAD_CFG_NF(GPIO_46, NATIVE, DEEP, NF1),	/* LPSS_UART2_RXD */
	/* LPSS_UART2_TXD */
	PAD_CFG_NF_IOSSTATE(GPIO_47, NATIVE, DEEP, NF1, Tx1RXDCRx0),
	PAD_CFG_GPI(GPIO_48, DN_20K, DEEP),	/* LPSS_UART2_RTS - unused */
	PAD_CFG_GPI(GPIO_49, UP_20K, DEEP),	/* LPSS_UART2_CTS - unused */

	/* Camera interface -- completely unused. */
	PAD_CFG_GPI(GPIO_62, DN_20K, DEEP),	/* GP_CAMERASB00 */
	PAD_CFG_GPI(GPIO_63, DN_20K, DEEP),	/* GP_CAMERASB01 */
	PAD_CFG_GPI(GPIO_64, DN_20K, DEEP),	/* GP_CAMERASB02 */
	PAD_CFG_GPI(GPIO_65, DN_20K, DEEP),	/* GP_CAMERASB03 */
	PAD_CFG_GPI(GPIO_66, DN_20K, DEEP),	/* GP_CAMERASB04 */
	PAD_CFG_GPI(GPIO_67, DN_20K, DEEP),	/* GP_CAMERASB05 */
	PAD_CFG_GPI(GPIO_68, DN_20K, DEEP),	/* GP_CAMERASB06 */
	PAD_CFG_GPI(GPIO_69, DN_20K, DEEP),	/* GP_CAMERASB07 */
	PAD_CFG_GPI(GPIO_70, DN_20K, DEEP),	/* GP_CAMERASB08 */
	PAD_CFG_GPI(GPIO_71, DN_20K, DEEP),	/* GP_CAMERASB09 */
	PAD_CFG_GPI(GPIO_72, DN_20K, DEEP),	/* GP_CAMERASB10 */
	PAD_CFG_GPI(GPIO_73, DN_20K, DEEP),	/* GP_CAMERASB11 */

	/* CNV bridge described into IAFW Vol2. */
	/* GPIO_[216:219] described into EDS Vol1. */
	PAD_CFG_GPO(CNV_BRI_DT, 0, DEEP),		/* Reserve of FPGA */
	PAD_CFG_GPO(CNV_BRI_RSP, 0, DEEP),		/* Reserve of FPGA */
	PAD_CFG_GPO(CNV_RGI_DT, 0, DEEP),		/* Reserve of FPGA */
	PAD_CFG_NF(CNV_RGI_RSP, UP_20K, DEEP, NF1),	/* eMMC */

	/* Serial VID */
	PAD_CFG_NF(SVID0_ALERT_B, NONE, DEEP, NF1),	/* SVID0_ALERT_B */
	PAD_CFG_NF(SVID0_DATA, UP_20K, DEEP, NF1),	/* SVID0_DATA */
	PAD_CFG_NF(SVID0_CLK, UP_20K, DEEP, NF1),	/* SVID0_CLK */
};

const struct pad_config *__weak variant_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(gpio_table);
	return gpio_table;
}

/* GPIOs needed prior to ramstage. */
static const struct pad_config early_gpio_table[] = {

	/* Debug tracing. */
	PAD_CFG_GPI(GPIO_0, DN_20K, DEEP),	/* TRACE_0_CLK_VNN */
	PAD_CFG_GPI(GPIO_1, DN_20K, DEEP),	/* TRACE_0_DATA0_VNN */
	PAD_CFG_GPI(GPIO_2, DN_20K, DEEP),	/* TRACE_0_DATA1_VNN */
	PAD_CFG_GPI(GPIO_3, DN_20K, DEEP),	/* TRACE_0_DATA2_VNN */
	PAD_CFG_GPI(GPIO_4, DN_20K, DEEP),	/* TRACE_0_DATA3_VNN */
	PAD_CFG_GPI(GPIO_5, DN_20K, DEEP),	/* TRACE_0_DATA4_VNN */
	PAD_CFG_GPI(GPIO_6, DN_20K, DEEP),	/* TRACE_0_DATA5_VNN */
	PAD_CFG_GPI(GPIO_7, DN_20K, DEEP),	/* TRACE_0_DATA6_VNN */
	PAD_CFG_GPI(GPIO_8, DN_20K, DEEP),	/* TRACE_0_DATA7_VNN */

	PAD_CFG_GPO(GPIO_13, 0, DEEP),		/* PERST# */
	PAD_CFG_GPO(GPIO_15, 0, DEEP),		/* PERST# */
	PAD_CFG_GPO(GPIO_17, 1, DEEP),		/* PFET */
	PAD_CFG_GPO(GPIO_19, 1, DEEP),		/* PFET */
	PAD_CFG_GPO(GPIO_152, 0, DEEP),		/* PERST# */

	/* SMBus */
	PAD_CFG_NF(SMB_CLK, UP_20K, DEEP, NF1),		/* SMB_CLK */
	PAD_CFG_NF(SMB_DATA, UP_20K, DEEP, NF1),	/* SMB_DATA */

	/* LPC */
	PAD_CFG_NF(LPC_ILB_SERIRQ, UP_20K, DEEP, NF1),	/* LPC_SERIRQ */
	PAD_CFG_NF(LPC_CLKOUT0, UP_20K, DEEP, NF1),	/* LPC_CLKOUT0 */
	/* LPC_CLKOUT1 - unused */
	PAD_CFG_GPI(LPC_CLKOUT1, DN_20K, DEEP),
	PAD_CFG_NF(LPC_AD0, UP_20K, DEEP, NF1),		/* LPC_AD0 */
	PAD_CFG_NF(LPC_AD1, UP_20K, DEEP, NF1),		/* LPC_AD1 */
	PAD_CFG_NF(LPC_AD2, UP_20K, DEEP, NF1),		/* LPC_AD2 */
	PAD_CFG_NF(LPC_AD3, UP_20K, DEEP, NF1),		/* LPC_AD3 */
	PAD_CFG_GPI(LPC_CLKRUNB, UP_20K, DEEP),		/* LPC_CLKRUN_N */
	PAD_CFG_NF(LPC_FRAMEB, UP_20K, DEEP, NF1),	/* LPC_FRAME_N */
};

const struct pad_config *__weak
variant_early_gpio_table(size_t *num)
{
	*num = ARRAY_SIZE(early_gpio_table);
	return early_gpio_table;
}
