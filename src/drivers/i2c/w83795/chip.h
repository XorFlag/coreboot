/* SPDX-License-Identifier: GPL-2.0-only */

#include <stdint.h>

#define W83795_SMART_FAN_CONTROL_POINTS 7
#define W83795_RELATIVE_TEMPERATURE_COUNT 6

struct w83795_control_mode_table {
	u8 temperatures[W83795_SMART_FAN_CONTROL_POINTS];
	u8 duty_cycles[W83795_SMART_FAN_CONTROL_POINTS];
};

struct drivers_i2c_w83795_config {

	/* Choose between server or workstation mode:
	 * - [1] server - all fans full speed, manual mode fixed values, no temp mapping
	 * - [0] workstation - set automatic mode per devicetree settings
	 */
	u8 server_manual_mode;
	u8 fanin_ctl1;
	u8 fanin_ctl2;

	u8 temp_ctl1;
	u8 temp_ctl2;
	u8 temp_dtse;

	u8 volt_ctl1;
	u8 volt_ctl2;

	u8 temp1_fan_select;
	u8 temp2_fan_select;
	u8 temp3_fan_select;
	u8 temp4_fan_select;
	u8 temp5_fan_select;
	u8 temp6_fan_select;

	u8 temp1_source_select;
	u8 temp2_source_select;
	u8 temp3_source_select;
	u8 temp4_source_select;
	u8 temp5_source_select;
	u8 temp6_source_select;

	u32 vcore1_high_limit_mv;		/* mV */
	u32 vcore1_low_limit_mv;		/* mV */
	u32 vcore2_high_limit_mv;		/* mV */
	u32 vcore2_low_limit_mv;		/* mV */
	u32 vtt_high_limit_mv;		/* mV */
	u32 vtt_low_limit_mv;		/* mV */
	u32 vsen3_high_limit_mv;		/* mV */
	u32 vsen3_low_limit_mv;		/* mV */
	u32 vsen4_high_limit_mv;		/* mV */
	u32 vsen4_low_limit_mv;		/* mV */
	u32 vsen5_high_limit_mv;		/* mV */
	u32 vsen5_low_limit_mv;		/* mV */
	u32 vsen6_high_limit_mv;		/* mV */
	u32 vsen6_low_limit_mv;		/* mV */
	u32 vsen7_high_limit_mv;		/* mV */
	u32 vsen7_low_limit_mv;		/* mV */
	u32 vsen8_high_limit_mv;		/* mV */
	u32 vsen8_low_limit_mv;		/* mV */
	u32 vsen9_high_limit_mv;		/* mV */
	u32 vsen9_low_limit_mv;		/* mV */
	u32 vsen10_high_limit_mv;		/* mV */
	u32 vsen10_low_limit_mv;		/* mV */
	u32 vsen11_high_limit_mv;		/* mV */
	u32 vsen11_low_limit_mv;		/* mV */
	u32 vsen12_high_limit_mv;		/* mV */
	u32 vsen12_low_limit_mv;		/* mV */
	u32 vsen13_high_limit_mv;		/* mV */
	u32 vsen13_low_limit_mv;		/* mV */
	u32 vdd_high_limit_mv;		/* mV */
	u32 vdd_low_limit_mv;		/* mV */
	u32 vsb_high_limit_mv;		/* mV */
	u32 vsb_low_limit_mv;		/* mV */
	u32 vbat_high_limit_mv;		/* mV */
	u32 vbat_low_limit_mv;		/* mV */

	s8 td1_offset;			/* °C */
	s8 td2_offset;			/* °C */
	s8 td3_offset;			/* °C */
	s8 td4_offset;			/* °C */
	s8 tr5_offset;			/* °C */
	s8 tr6_offset;			/* °C */

	s8 tr1_critical_temperature;	/* °C */
	s8 tr1_critical_hysteresis;		/* °C */
	s8 tr1_warning_temperature;		/* °C */
	s8 tr1_warning_hysteresis;		/* °C */
	s8 tr2_critical_temperature;	/* °C */
	s8 tr2_critical_hysteresis;		/* °C */
	s8 tr2_warning_temperature;		/* °C */
	s8 tr2_warning_hysteresis;		/* °C */
	s8 tr3_critical_temperature;	/* °C */
	s8 tr3_critical_hysteresis;		/* °C */
	s8 tr3_warning_temperature;		/* °C */
	s8 tr3_warning_hysteresis;		/* °C */
	s8 tr4_critical_temperature;	/* °C */
	s8 tr4_critical_hysteresis;		/* °C */
	s8 tr4_warning_temperature;		/* °C */
	s8 tr4_warning_hysteresis;		/* °C */
	s8 tr5_critical_temperature;	/* °C */
	s8 tr5_critical_hysteresis;		/* °C */
	s8 tr5_warning_temperature;		/* °C */
	s8 tr5_warning_hysteresis;		/* °C */
	s8 tr6_critical_temperature;	/* °C */
	s8 tr6_critical_hysteresis;		/* °C */
	s8 tr6_warning_temperature;		/* °C */
	s8 tr6_warning_hysteresis;		/* °C */
	s8 dts_critical_temperature;	/* °C */
	s8 dts_critical_hysteresis;		/* °C */
	s8 dts_warning_temperature;		/* °C */
	s8 dts_warning_hysteresis;		/* °C */

	u8 ht1_operation_hysteresis;	/* °C */
	u8 ht1_critical_hysteresis;	/* °C */
	u8 ht2_operation_hysteresis;	/* °C */
	u8 ht2_critical_hysteresis;	/* °C */
	u8 ht3_operation_hysteresis;	/* °C */
	u8 ht3_critical_hysteresis;	/* °C */
	u8 ht4_operation_hysteresis;	/* °C */
	u8 ht4_critical_hysteresis;	/* °C */
	u8 ht5_operation_hysteresis;	/* °C */
	u8 ht5_critical_hysteresis;	/* °C */
	u8 ht6_operation_hysteresis;	/* °C */
	u8 ht6_critical_hysteresis;	/* °C */

	s8 temp1_critical_temperature;	/* °C */
	s8 temp2_critical_temperature;	/* °C */
	s8 temp3_critical_temperature;	/* °C */
	s8 temp4_critical_temperature;	/* °C */
	s8 temp5_critical_temperature;	/* °C */
	s8 temp6_critical_temperature;	/* °C */

	s8 temp1_target_temperature;	/* °C */
	s8 temp2_target_temperature;	/* °C */
	s8 temp3_target_temperature;	/* °C */
	s8 temp4_target_temperature;	/* °C */
	s8 temp5_target_temperature;	/* °C */
	s8 temp6_target_temperature;	/* °C */

	u8 fan1_nonstop;			/* % of full speed (0-100) */
	u8 fan2_nonstop;			/* % of full speed (0-100) */
	u8 fan3_nonstop;			/* % of full speed (0-100) */
	u8 fan4_nonstop;			/* % of full speed (0-100) */
	u8 fan5_nonstop;			/* % of full speed (0-100) */
	u8 fan6_nonstop;			/* % of full speed (0-100) */
	u8 fan7_nonstop;			/* % of full speed (0-100) */
	u8 fan8_nonstop;			/* % of full speed (0-100) */

	u8 default_speed;			/* % of full speed (0-100) */

	u8 fan1_duty;			/* % of full speed (0-100) */
	u8 fan2_duty;			/* % of full speed (0-100) */
	u8 fan3_duty;			/* % of full speed (0-100) */
	u8 fan4_duty;			/* % of full speed (0-100) */
	u8 fan5_duty;			/* % of full speed (0-100) */
	u8 fan6_duty;			/* % of full speed (0-100) */
	u8 fan7_duty;			/* % of full speed (0-100) */
	u8 fan8_duty;			/* % of full speed (0-100) */

	u8 smbus_aux;			/* 0   == device located on primary SMBUS,
						 * 1   == device located on first auxiliary
						 *        SMBUS channel,
						 * <n> == device located on <n> auxiliary
						 *        SMBUS channel
						 */

	struct w83795_control_mode_table control_mode_table[W83795_RELATIVE_TEMPERATURE_COUNT];
};
