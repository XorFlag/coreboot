/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT8192_DRAMC_REGISTER_H__
#define __SOC_MEDIATEK_MT8192_DRAMC_REGISTER_H__

#include <soc/addressmap.h>
#include <soc/dpm.h>
#include <stdint.h>

struct dramc_nao_regs {
	u32 testmode;
	u32 rsvd_0[4];
	u32 rdqc_cmp;
	u32 rdqc_dqm_cmp;
	u32 rsvd_1[2];
	u32 dmmonitor;
	u32 rsvd_2[2];
	u32 initk_pat0;
	u32 initk_pat1;
	u32 initk_pat2;
	u32 initk_pat3;
	u32 initk_pat4;
	u32 rsvd_3[3];
	u32 spcmdresp3;
	u32 cbt_wlev_status2;
	u32 rsvd_4[10];
	u32 misc_statusa;
	u32 special_status;
	u32 spcmdresp;
	u32 mrr_status;
	u32 mrr_status2;
	u32 mrrdata0;
	u32 mrrdata1;
	u32 mrrdata2;
	u32 mrrdata3;
	u32 ref_status;
	u32 rsvd_5[2];
	u32 wck_status;
	u32 rsvd_6[3];
	u32 tcmdo1lat;
	u32 cbt_wlev_status1;
	u32 cbt_wlev_status;
	u32 spcmdresp2;
	u32 cbt_wlev_atk_result0;
	u32 cbt_wlev_atk_result1;
	u32 cbt_wlev_atk_result2;
	u32 cbt_wlev_atk_result3;
	u32 cbt_wlev_atk_result4;
	u32 cbt_wlev_atk_result5;
	u32 cbt_wlev_atk_result6;
	u32 cbt_wlev_atk_result7;
	u32 cbt_wlev_atk_result8;
	u32 cbt_wlev_atk_result9;
	u32 cbt_wlev_atk_result10;
	u32 cbt_wlev_atk_result11;
	u32 cbt_wlev_atk_result12;
	u32 cbt_wlev_atk_result13;
	u32 rsvd_7[1];
	u32 hwmrr_push2pop_cnt;
	u32 hwmrr_status;
	u32 hw_refrate_mon;
	u32 hw_refrate_mon2;
	u32 hw_refrate_mon3;
	u32 testrpt;
	u32 cmp_err;
	u32 test_abit_status1;
	u32 test_abit_status2;
	u32 test_abit_status3;
	u32 test_abit_status4;
	u32 test_abit_status5;
	u32 test_abit_status6;
	u32 test_abit_status7;
	u32 test_abit_status8;
	u32 test_rf_error_flag0;
	u32 test_rf_error_flag1;
	u32 test_rf_error_cnt1;
	u32 test_rf_error_cnt2;
	u32 test_rf_error_cnt3;
	u32 test_rf_error_cnt4;
	u32 test_rf_error_cnt5;
	u32 test_rf_error_cnt6;
	u32 test_rf_error_cnt7;
	u32 test_rf_error_cnt8;
	u32 test_loop_cnt;
	u32 rsvd_8[3];
	u32 sref_dly_cnt;
	u32 rsvd_9[31];
	u32 tx_atk_set0;
	u32 tx_atk_set1;
	u32 rsvd_10[2];
	u32 tx_atk_result0;
	u32 tx_atk_result1;
	u32 tx_atk_result2;
	u32 tx_atk_result3;
	u32 tx_atk_result4;
	u32 tx_atk_result5;
	u32 tx_atk_result6;
	u32 tx_atk_result7;
	u32 tx_atk_result8;
	u32 rsvd_11[3];
	u32 tx_atk_dbg_bit_status1;
	u32 tx_atk_dbg_bit_status2;
	u32 tx_atk_dbg_bit_status3;
	u32 tx_atk_dbg_bit_status4;
	u32 rsvd_12[34];
	u32 lp5_pdx_pde_mon;
	u32 lp5_pdx_pde_max_mon;
	u32 dram_clk_en_0_old_counter;
	u32 aphypi_cg_ck_old_counter;
	u32 ckeo_pre_old_counter;
	u32 cke1o_pre_old_counter;
	u32 dram_clk_en_0_new_counter;
	u32 aphypi_cg_ck_new_counter;
	u32 ckeo_pre_new_counter;
	u32 cke1o_pre_new_counter;
	u32 refresh_pop_counter;
	u32 freerun_26m_counter;
	u32 dramc_idle_counter;
	u32 r2r_page_hit_counter;
	u32 r2r_page_miss_counter;
	u32 r2r_interbank_counter;
	u32 r2w_page_hit_counter;
	u32 r2w_page_miss_counter;
	u32 r2w_interbank_counter;
	u32 w2r_page_hit_counter;
	u32 w2r_page_miss_counter;
	u32 w2r_interbank_counter;
	u32 w2w_page_hit_counter;
	u32 w2w_page_miss_counter;
	u32 w2w_interbank_counter;
	u32 rk0_pre_standby_counter;
	u32 rk0_pre_powerdown_counter;
	u32 rk0_act_standby_counter;
	u32 rk0_act_powerdown_counter;
	u32 rk1_pre_standby_counter;
	u32 rk1_pre_powerdown_counter;
	u32 rk1_act_standby_counter;
	u32 rk1_act_powerdown_counter;
	u32 rk2_pre_standby_counter;
	u32 rk2_pre_powerdown_counter;
	u32 rk2_act_standby_counter;
	u32 rk2_act_powerdown_counter;
	u32 dq0_toggle_counter;
	u32 dq1_toggle_counter;
	u32 dq2_toggle_counter;
	u32 dq3_toggle_counter;
	u32 dq0_toggle_counter_r;
	u32 dq1_toggle_counter_r;
	u32 dq2_toggle_counter_r;
	u32 dq3_toggle_counter_r;
	u32 read_bytes_counter;
	u32 write_bytes_counter;
	u32 max_sref_req_to_ack_latency_counter;
	u32 rsvd_13[2];
	u32 dramc_idle_dcm_counter;
	u32 ddrphy_clk_en_counter;
	u32 ddrphy_clk_en_comb_counter;
	u32 rsvd_14[1];
	u32 ebg_counter_cnt0;
	u32 ebg_counter_cnt1;
	u32 ebg_counter_cnt2;
	u32 rsvd_15[1];
	u32 lat_counter_cmd0;
	u32 lat_counter_cmd1;
	u32 lat_counter_cmd2;
	u32 lat_counter_cmd3;
	u32 lat_counter_cmd4;
	u32 lat_counter_cmd5;
	u32 lat_counter_cmd6;
	u32 lat_counter_cmd7;
	u32 lat_counter_aver;
	u32 lat_counter_num;
	u32 lat_counter_block_ale;
	u32 rsvd_16[70];
	u32 dramc_loop_bak_adr;
	u32 dramc_loop_bak_rk;
	u32 rsvd_17[1];
	u32 dramc_loop_bak_wdat0;
	u32 dramc_loop_bak_wdat1;
	u32 dramc_loop_bak_wdat2;
	u32 dramc_loop_bak_wdat3;
	u32 dramc_loop_bak_wdat4;
	u32 dramc_loop_bak_wdat5;
	u32 dramc_loop_bak_wdat6;
	u32 dramc_loop_bak_wdat7;
	u32 rsvd_18[52];
	u32 rk0_dqsosc_status;
	u32 rk0_dqsosc_delta;
	u32 rk0_dqsosc_delta2;
	u32 rsvd_19[1];
	u32 rk0_current_tx_setting1;
	u32 rk0_current_tx_setting2;
	u32 rk0_current_tx_setting3;
	u32 rk0_current_tx_setting4;
	u32 rk0_dummy_rd_data0;
	u32 rk0_dummy_rd_data1;
	u32 rk0_dummy_rd_data2;
	u32 rk0_dummy_rd_data3;
	u32 rk0_dummy_rd_data4;
	u32 rk0_dummy_rd_data5;
	u32 rk0_dummy_rd_data6;
	u32 rk0_dummy_rd_data7;
	u32 rsvd_20[8];
	u32 rk0_pi_dq_cal;
	u32 rsvd_21[1];
	u32 rk0_pi_dqm_cal;
	u32 rsvd_22[37];
	u32 rk1_dqsosc_status;
	u32 rk1_dqsosc_delta;
	u32 rk1_dqsosc_delta2;
	u32 rsvd_23[1];
	u32 rk1_current_tx_setting1;
	u32 rk1_current_tx_setting2;
	u32 rk1_current_tx_setting3;
	u32 rk1_current_tx_setting4;
	u32 rk1_dummy_rd_data0;
	u32 rk1_dummy_rd_data1;
	u32 rk1_dummy_rd_data2;
	u32 rk1_dummy_rd_data3;
	u32 rk1_dummy_rd_data4;
	u32 rk1_dummy_rd_data5;
	u32 rk1_dummy_rd_data6;
	u32 rk1_dummy_rd_data7;
	u32 rsvd_24[8];
	u32 rk1_pi_dq_cal;
	u32 rsvd_25[1];
	u32 rk1_pi_dqm_cal;
	u32 rsvd_26[101];
	u32 mr_backup_00_rk0_fsp0;
	u32 mr_backup_01_rk0_fsp0;
	u32 mr_backup_02_rk0_fsp0;
	u32 mr_backup_03_rk0_fsp0;
	u32 mr_backup_04_rk0_fsp0;
	u32 mr_backup_05_rk0_fsp0;
	u32 mr_backup_06_rk0_fsp0;
	u32 mr_backup_07_rk0_fsp0;
	u32 mr_backup_08_rk0_fsp0;
	u32 mr_backup_09_rk0_fsp0;
	u32 rsvd_27[2];
	u32 mr_backup_00_rk0_fsp1;
	u32 mr_backup_01_rk0_fsp1;
	u32 mr_backup_02_rk0_fsp1;
	u32 mr_backup_03_rk0_fsp1;
	u32 mr_backup_04_rk0_fsp1;
	u32 rsvd_28[7];
	u32 mr_backup_00_rk0_fsp2;
	u32 mr_backup_01_rk0_fsp2;
	u32 mr_backup_02_rk0_fsp2;
	u32 mr_backup_03_rk0_fsp2;
	u32 rsvd_29[100];
	u32 mr_backup_00_rk1_fsp0;
	u32 mr_backup_01_rk1_fsp0;
	u32 mr_backup_02_rk1_fsp0;
	u32 mr_backup_03_rk1_fsp0;
	u32 mr_backup_04_rk1_fsp0;
	u32 mr_backup_05_rk1_fsp0;
	u32 mr_backup_06_rk1_fsp0;
	u32 mr_backup_07_rk1_fsp0;
	u32 mr_backup_08_rk1_fsp0;
	u32 mr_backup_09_rk1_fsp0;
	u32 rsvd_30[2];
	u32 mr_backup_00_rk1_fsp1;
	u32 mr_backup_01_rk1_fsp1;
	u32 mr_backup_02_rk1_fsp1;
	u32 mr_backup_03_rk1_fsp1;
	u32 mr_backup_04_rk1_fsp1;
	u32 rsvd_31[7];
	u32 mr_backup_00_rk1_fsp2;
	u32 mr_backup_01_rk1_fsp2;
	u32 mr_backup_02_rk1_fsp2;
	u32 mr_backup_03_rk1_fsp2;
};

struct ddrphy_nao_regs {
	u32 misc_sta_extlb0;
	u32 misc_sta_extlb1;
	u32 misc_sta_extlb2;
	u32 rsvd_0[1];
	u32 misc_dma_debug0;
	u32 misc_dma_debug1;
	u32 misc_retry_dbg0;
	u32 misc_retry_dbg1;
	u32 misc_retry_dbg2;
	u32 misc_rdsel_track_dbg;
	u32 rsvd_1[22];
	u32 misc_dq_rxdly_trro0;
	u32 misc_dq_rxdly_trro1;
	u32 misc_dq_rxdly_trro2;
	u32 misc_dq_rxdly_trro3;
	u32 misc_dq_rxdly_trro4;
	u32 misc_dq_rxdly_trro5;
	u32 misc_dq_rxdly_trro6;
	u32 misc_dq_rxdly_trro7;
	u32 misc_dq_rxdly_trro8;
	u32 misc_dq_rxdly_trro9;
	u32 misc_dq_rxdly_trro10;
	u32 misc_dq_rxdly_trro11;
	u32 misc_dq_rxdly_trro12;
	u32 misc_dq_rxdly_trro13;
	u32 misc_dq_rxdly_trro14;
	u32 misc_dq_rxdly_trro15;
	u32 misc_dq_rxdly_trro16;
	u32 misc_dq_rxdly_trro17;
	u32 misc_dq_rxdly_trro18;
	u32 misc_dq_rxdly_trro19;
	u32 misc_dq_rxdly_trro20;
	u32 misc_dq_rxdly_trro21;
	u32 misc_dq_rxdly_trro22;
	u32 misc_dq_rxdly_trro23;
	u32 misc_dq_rxdly_trro24;
	u32 misc_dq_rxdly_trro25;
	u32 misc_dq_rxdly_trro26;
	u32 misc_dq_rxdly_trro27;
	u32 misc_dq_rxdly_trro28;
	u32 misc_dq_rxdly_trro29;
	u32 misc_dq_rxdly_trro30;
	u32 misc_dq_rxdly_trro31;
	u32 rsvd_2[20];
	u32 misc_ca_rxdly_trro20;
	u32 misc_ca_rxdly_trro21;
	u32 misc_ca_rxdly_trro22;
	u32 misc_ca_rxdly_trro23;
	u32 misc_ca_rxdly_trro24;
	u32 misc_ca_rxdly_trro25;
	u32 misc_ca_rxdly_trro26;
	u32 misc_ca_rxdly_trro27;
	u32 misc_ca_rxdly_trro28;
	u32 misc_ca_rxdly_trro29;
	u32 misc_ca_rxdly_trro30;
	u32 misc_ca_rxdly_trro31;
	u32 misc_dqo1;
	u32 misc_cao1;
	u32 misc_ad_rx_dq_o1;
	u32 misc_ad_rx_cmd_o1;
	u32 misc_phy_rgs_dq;
	u32 misc_phy_rgs_cmd;
	u32 misc_phy_rgs_stben_b0;
	u32 misc_phy_rgs_stben_b1;
	u32 misc_phy_rgs_stben_cmd;
	u32 misc_phy_picg_mon_s0;
	u32 misc_phy_picg_mon_s1;
	u32 misc_phy_picg_mon_s2;
	u32 misc_phy_picg_mon_s3;
	u32 misc_phy_picg_mon_s4;
	u32 misc_phy_picg_mon_s5;
	u32 misc_phy_picg_mon_s6;
	u32 misc_phy_picg_mon_s7;
	u32 misc_phy_picg_mon_s8;
	u32 misc_mbist_status;
	u32 misc_mbist_status2;
	u32 misc_impcal_status1;
	u32 misc_impcal_status2;
	u32 misc_impcal_status3;
	u32 misc_impcal_status4;
	u32 misc_impcal_status5;
	u32 misc_impcal_status6;
	u32 misc_impcal_status7;
	u32 misc_impcal_status8;
	u32 rsvd_3[1];
	u32 misc_impcal_status9;
	u32 misc_sta_toglb0;
	u32 misc_sta_toglb1;
	u32 rsvd_4[5];
	u32 misc_sta_extlb_dbg0;
	u32 misc_sta_extlb_dbg1;
	u32 misc_sta_extlb_dbg2;
	u32 misc_sta_extlb_dbg3;
	u32 misc_duty_toggle_cnt;
	u32 misc_duty_dqs0_err_cnt;
	u32 misc_duty_dq_err_cnt0;
	u32 misc_duty_dqs1_err_cnt;
	u32 misc_duty_dq_err_cnt1;
	u32 misc_duty_dqs2_err_cnt;
	u32 misc_duty_dq_err_cnt2;
	u32 misc_duty_dqs3_err_cnt;
	u32 misc_duty_dq_err_cnt3;
	u32 misc_jmeter_st0;
	u32 misc_jmeter_st1;
	u32 misc_emi_lpbk0;
	u32 misc_emi_lpbk1;
	u32 misc_emi_lpbk2;
	u32 misc_emi_lpbk3;
	u32 misc_emi_lpbk4;
	u32 misc_emi_lpbk5;
	u32 misc_emi_lpbk6;
	u32 misc_emi_lpbk7;
	u32 misc_ft_status0;
	u32 misc_ft_status1;
	u32 misc_ft_status2;
	u32 misc_ft_status3;
	u32 misc_ft_status4;
	u32 misc_sta_toglb2;
	u32 misc_sta_toglb3;
	u32 misc_sta_extlb3;
	u32 misc_sta_extlb4;
	u32 misc_sta_extlb5;
	u32 rsvd_5[90];
	u32 debug_aphy_rx_ctl;
	u32 rsvd_6[3];
	u32 gating_err_infor;
	u32 debug_dqsien_b0;
	u32 debug_dqsien_b1;
	u32 debug_dqsien_ca;
	u32 gating_err_latch_dly_b0_rk0;
	u32 gating_err_latch_dly_b1_rk0;
	u32 gating_err_latch_dly_ca_rk0;
	u32 rsvd_7[1];
	u32 gating_err_latch_dly_b0_rk1;
	u32 gating_err_latch_dly_b1_rk1;
	u32 gating_err_latch_dly_ca_rk1;
	u32 rsvd_8[1];
	u32 debug_rodt_ctl;
	u32 rsvd_9[47];
	u32 cal_dqsg_cnt_b0;
	u32 cal_dqsg_cnt_b1;
	u32 cal_dqsg_cnt_ca;
	u32 dvfs_status;
	u32 rx_autok_status0;
	u32 rx_autok_status1;
	u32 rx_autok_status2;
	u32 rx_autok_status3;
	u32 rx_autok_status4;
	u32 rx_autok_status5;
	u32 rx_autok_status6;
	u32 rx_autok_status7;
	u32 rx_autok_status8;
	u32 rx_autok_status9;
	u32 rx_autok_status10;
	u32 rx_autok_status11;
	u32 rx_autok_status12;
	u32 rx_autok_status13;
	u32 rx_autok_status14;
	u32 rx_autok_status15;
	u32 rx_autok_status16;
	u32 rx_autok_status17;
	u32 rx_autok_status18;
	u32 rx_autok_status19;
	u32 rx_autok_status20;
	u32 rsvd_10[39];
	u32 dqsien_autok_b0_rk0_status0;
	u32 dqsien_autok_b0_rk0_status1;
	u32 dqsien_autok_b0_rk0_dbg_status0;
	u32 dqsien_autok_b0_rk0_dbg_status1;
	u32 dqsien_autok_b0_rk0_dbg_status2;
	u32 dqsien_autok_b0_rk0_dbg_status3;
	u32 dqsien_autok_b0_rk0_dbg_status4;
	u32 dqsien_autok_b0_rk0_dbg_status5;
	u32 dqsien_autok_b0_rk1_status0;
	u32 dqsien_autok_b0_rk1_status1;
	u32 dqsien_autok_b0_rk1_dbg_status0;
	u32 dqsien_autok_b0_rk1_dbg_status1;
	u32 dqsien_autok_b0_rk1_dbg_status2;
	u32 dqsien_autok_b0_rk1_dbg_status3;
	u32 dqsien_autok_b0_rk1_dbg_status4;
	u32 dqsien_autok_b0_rk1_dbg_status5;
	u32 dqsien_autok_b1_rk0_status0;
	u32 dqsien_autok_b1_rk0_status1;
	u32 dqsien_autok_b1_rk0_dbg_status0;
	u32 dqsien_autok_b1_rk0_dbg_status1;
	u32 dqsien_autok_b1_rk0_dbg_status2;
	u32 dqsien_autok_b1_rk0_dbg_status3;
	u32 dqsien_autok_b1_rk0_dbg_status4;
	u32 dqsien_autok_b1_rk0_dbg_status5;
	u32 dqsien_autok_b1_rk1_status0;
	u32 dqsien_autok_b1_rk1_status1;
	u32 dqsien_autok_b1_rk1_dbg_status0;
	u32 dqsien_autok_b1_rk1_dbg_status1;
	u32 dqsien_autok_b1_rk1_dbg_status2;
	u32 dqsien_autok_b1_rk1_dbg_status3;
	u32 dqsien_autok_b1_rk1_dbg_status4;
	u32 dqsien_autok_b1_rk1_dbg_status5;
	u32 dqsien_autok_ca_rk0_status0;
	u32 dqsien_autok_ca_rk0_status1;
	u32 dqsien_autok_ca_rk0_dbg_status0;
	u32 dqsien_autok_ca_rk0_dbg_status1;
	u32 dqsien_autok_ca_rk0_dbg_status2;
	u32 dqsien_autok_ca_rk0_dbg_status3;
	u32 dqsien_autok_ca_rk0_dbg_status4;
	u32 dqsien_autok_ca_rk0_dbg_status5;
	u32 rsvd_11[24];
	u32 dqsien_autok_ca_rk1_status0;
	u32 dqsien_autok_ca_rk1_status1;
	u32 dqsien_autok_ca_rk1_dbg_status0;
	u32 dqsien_autok_ca_rk1_dbg_status1;
	u32 dqsien_autok_ca_rk1_dbg_status2;
	u32 dqsien_autok_ca_rk1_dbg_status3;
	u32 dqsien_autok_ca_rk1_dbg_status4;
	u32 dqsien_autok_ca_rk1_dbg_status5;
	u32 dqsien_autok_ctrl_status;
	u32 ad_dline_mon;
	u32 dline_mon_track_dbg;
	u32 misc_dutycal_status;
	u32 misc_dbg_db_imp_message0;
	u32 misc_dbg_db_imp_message1;
	u32 misc_dbg_db_imp_message2;
	u32 misc_dbg_db_imp_message3;
	u32 misc_dbg_db_imp_message4;
	u32 misc_dbg_db_imp_message5;
	u32 misc_dbg_db_imp_message6;
	u32 misc_dbg_db_imp_message7;
	u32 misc_dbg_db_imp_message8;
	u32 misc_dbg_db_imp_message9;
	u32 misc_dbg_db_imp_message10;
	u32 misc_dbg_db_imp_message11;
	u32 rsvd_12[40];
	u32 misc_dma_sram_mbist;
	u32 rsvd_13[7];
	u32 misc_aphy_obs0;
	u32 misc_aphy_obs1;
	u32 misc_aphy_obs2;
	u32 misc_aphy_obs3;
	u32 misc_aphy_obs4;
	u32 misc_aphy_obs5;
	u32 misc_aphy_obs6;
	u32 misc_aphy_obs7;
	u32 misc_aphy_obs8;
};

struct dramc_ao_rk {
	u32 rk_test2_a1;
	u32 rk_dummy_rd_wdata0;
	u32 rk_dummy_rd_wdata1;
	u32 rk_dummy_rd_wdata2;
	u32 rk_dummy_rd_wdata3;
	u32 rk_dummy_rd_adr;
	u32 rsvd_0[15];
	u32 rk_dummy_rd_adr2;
	u32 rsvd_1[4];
	u32 rk_sref_dpd_tck_rk_ctrl;
	u32 rsvd_2[9];
	u32 rk_dqsosc;
	u32 rsvd_3[91];
};

struct dramc_ao_shu_rk {
	u32 shurk_selph_dq0;
	u32 shurk_selph_dq1;
	u32 shurk_selph_dq2;
	u32 shurk_selph_dq3;
	u32 shurk_dqs2dq_cal1;
	u32 shurk_dqs2dq_cal2;
	u32 shurk_dqs2dq_cal3;
	u32 shurk_dqs2dq_cal4;
	u32 shurk_dqs2dq_cal5;
	u32 shurk_pi;
	u32 shurk_dqsosc;
	u32 shurk_dqsosc_thrd;
	u32 shurk_aphy_tx_picg_ctrl;
	u32 rsvd_25[3];
	u32 shurk_wck_wr_mck;
	u32 shurk_wck_rd_mck;
	u32 shurk_wck_fs_mck;
	u32 shurk_wck_wr_ui;
	u32 shurk_wck_rd_ui;
	u32 shurk_wck_fs_ui;
	u32 rsvd_26[2];
	u32 shurk_cke_ctrl;
	u32 rsvd_27[103];
};

struct dramc_ao_regs {
	u32 ddrcommon0;
	u32 rsvd_0[2];
	u32 sa_reserve;
	u32 rsvd_1[59];
	u32 nonshu_rsv;
	u32 test2_a0;
	u32 test2_a2;
	u32 test2_a3;
	u32 test2_a4;
	u32 dummy_rd;
	u32 dummy_rd_intv;
	u32 bus_mon1;
	u32 dramc_dbg_sel1;
	u32 dramc_dbg_sel2;
	u32 swcmd_en;
	u32 swcmd_ctrl0;
	u32 swcmd_ctrl1;
	u32 swcmd_ctrl2;
	u32 rddqcgolden1;
	u32 rddqcgolden;
	u32 rtmrw_ctrl0;
	u32 rtmrw_ctrl1;
	u32 rtmrw_ctrl2;
	u32 rtmrw_ctrl3;
	u32 cbt_wlev_ctrl0;
	u32 cbt_wlev_ctrl1;
	u32 cbt_wlev_ctrl2;
	u32 cbt_wlev_ctrl3;
	u32 cbt_wlev_ctrl4;
	u32 cbt_wlev_atk_ctrl0;
	u32 cbt_wlev_atk_ctrl1;
	u32 sref_dpd_ctrl;
	u32 cfc_ctrl;
	u32 dllfrz_ctrl;
	u32 mpc_ctrl;
	u32 hw_mrr_fun;
	u32 scheduler_com;
	u32 rsvd_2[4];
	u32 actiming_ctrl;
	u32 rsvd_3[3];
	u32 zq_set0;
	u32 zq_set1;
	u32 rsvd_4[2];
	u32 tx_tracking_set0;
	u32 rsvd_5[3];
	u32 tx_retry_set0;
	u32 rsvd_6[1];
	u32 mpc_option;
	u32 rsvd_7[1];
	u32 mrr_bit_mux1;
	u32 mrr_bit_mux2;
	u32 mrr_bit_mux3;
	u32 mrr_bit_mux4;
	u32 rsvd_8[6];
	u32 shuctrl;
	u32 dramc_pd_ctrl;
	u32 dcm_ctrl0;
	u32 ckectrl;
	u32 dvfs_ctrl0;
	u32 shuctrl1;
	u32 dvfs_timing_ctrl1;
	u32 shuctrl3;
	u32 dvfs_timing_ctrl3;
	u32 cmd_dec_ctrl0;
	u32 hmr4;
	u32 bypass_fspop;
	u32 rkcfg;
	u32 slp4_testmode;
	u32 dq_mux_set0;
	u32 dbiwr_protect;
	u32 tx_set0;
	u32 tx_cg_set0;
	u32 rx_set0;
	u32 rx_cg_set0;
	u32 dqsoscr;
	u32 dramctrl;
	u32 misctl0;
	u32 perfctl0;
	u32 arbctl;
	u32 datascr;
	u32 clkar;
	u32 refctrl0;
	u32 refctrl1;
	u32 ref_bounce1;
	u32 ref_bounce2;
	u32 rsvd_9[1];
	u32 refpend1;
	u32 refpend2;
	u32 refque_cnt;
	u32 scsmctrl;
	u32 scsmctrl_cg;
	u32 refctrl2;
	u32 tx_freq_ratio_old_mode0;
	u32 tx_freq_ratio_old_mode1;
	u32 tx_freq_ratio_old_mode2;
	u32 wdt_rst;
	u32 seda_loop_bak_err_pat_b01;
	u32 seda_loop_bak_err_pat_b23;
	u32 seda_loop_bak_err_pat_b45;
	u32 seda_loop_bak_err_pat_b67;
	u32 seda_loop_bak_set;
	u32 rsvd_10[3];
	u32 dbg_cmddec_cmdsel0;
	u32 dbg_cmddec_cmdsel1;
	u32 dbg_cmddec_cmdsel2;
	u32 dbg_cmddec_cmdsel3;
	u32 dbg_cmddec_cmdsel4;
	u32 rtswcmd_cnt;
	u32 refctrl3;
	u32 rsvd_11[1];
	u32 dramc_irq_en;
	u32 dramc_irq_clear;
	u32 irq_rsv1;
	u32 irq_rsv2;
	u32 refcnt_fr_clk1;
	u32 refcnt_fr_clk2;
	u32 refcnt_fr_clk3;
	u32 refcnt_fr_clk4;
	u32 refcnt_fr_clk5;
	u32 refcnt_fr_clk6;
	u32 refcnt_fr_clk7;
	u32 rsvd_12[1];
	u32 dcm_sub_ctrl;
	u32 rsvd_13[3];
	u32 cbt_wlev_ctrl5;
	u32 rsvd_14[3];
	u32 dram_clk_ctrl;
	u32 rsvd_15[115];
	struct dramc_ao_rk rk[RANK_MAX];
	u32 rsvd_19[256];
	u32 wdt_dbg_signal;
	u32 rsvd_20[1];
	u32 selfref_hwsave_flag;
	u32 rsvd_21[125];
	u32 dramc_irq_status1;
	u32 dramc_irq_status2;
	u32 rsvd_22[2];
	u32 dramc_irq_info1;
	u32 dramc_irq_info1a;
	u32 rsvd_23[2];
	u32 dramc_irq_info2;
	u32 dramc_irq_info3;
	u32 dramc_irq_info4;
	u32 dramc_irq_info5;
	u32 rsvd_24[180];
	struct dramc_ao_shu_rk shu_rk[RANK_MAX];
	u32 shu_matype;
	u32 shu_common0;
	u32 shu_sref_ctrl;
	u32 shu_scheduler;
	u32 shu_dcm_ctrl0;
	u32 shu_hmr4_dvfs_ctrl0;
	u32 shu_selph_ca1;
	u32 shu_selph_ca2;
	u32 shu_selph_ca3;
	u32 shu_selph_ca4;
	u32 shu_selph_ca5;
	u32 shu_selph_ca6;
	u32 shu_selph_ca7;
	u32 shu_selph_ca8;
	u32 shu_hwset_mr2;
	u32 shu_hwset_mr13;
	u32 shu_hwset_vrcg;
	u32 shu_actim0;
	u32 shu_actim1;
	u32 shu_actim2;
	u32 shu_actim3;
	u32 shu_actim4;
	u32 shu_actim5;
	u32 shu_actim6;
	u32 shu_actim_xrt;
	u32 shu_ac_time_05t;
	u32 shu_ac_derating0;
	u32 shu_ac_derating1;
	u32 shu_ac_derating_05t;
	u32 shu_actiming_conf;
	u32 shu_ckectrl;
	u32 shu_selph_dqs0;
	u32 shu_selph_dqs1;
	u32 shu_wodt;
	u32 shu_tx_set0;
	u32 shu_rx_cg_set0;
	u32 shu_dqsosc_set0;
	u32 shu_dqsoscr;
	u32 shu_tx_rankctl;
	u32 shu_zq_set0;
	u32 shu_conf0;
	u32 shu_misc;
	u32 shu_new_xrw2w_ctrl;
	u32 shu_aphy_tx_picg_ctrl;
	u32 shu_freq_ratio_set0;
	u32 shu_freq_ratio_set1;
	u32 shu_freq_ratio_set2;
	u32 shureg_rsv;
	u32 shu_wckctrl;
	u32 shu_wckctrl_1;
	u32 rsvd_28[2];
	u32 shu_rx_set0;
	u32 shu_ref0;
	u32 rsvd_29[2];
	u32 shu_lp5_cmd;
	u32 shu_lp5_sact;
	u32 shu_actim7;
};

struct emi_regs {
	u32 cona;
	u32 conp;
	u32 conb;
	u32 conq;
	u32 conc;
	u32 conr;
	u32 cond;
	u32 conp_2nd;
	u32 cone;
	u32 conq_2nd;
	u32 conf;
	u32 conr_2nd;
	u32 cong;
	u32 conb_3rd;
	u32 conh;
	u32 conh_2nd;
	u32 coni;
	u32 conb_4th;
	u32 conj;
	u32 conb_5th;
	u32 conk;
	u32 conb_6th;
	u32 rsvd_0[1];
	u32 conb_7th;
	u32 conm;
	u32 conb_8th;
	u32 conn;
	u32 conc_3rd;
	u32 cono;
	u32 conc_4th;
	u32 mdct;
	u32 mdct_2nd;
	u32 rsvd_1[1];
	u32 conc_5th;
	u32 rsvd_2[1];
	u32 conc_6th;
	u32 rsvd_3[1];
	u32 conc_7th;
	u32 rsvd_4[1];
	u32 conc_8th;
	u32 rsvd_5[9];
	u32 cong_3rd;
	u32 cong_4th;
	u32 cong_5th;
	u32 iocl;
	u32 iocl_2nd;
	u32 iocm;
	u32 iocm_2nd;
	u32 rsvd_6[1];
	u32 cong_6th;
	u32 testb;
	u32 rsvd_7[1];
	u32 testc;
	u32 cong_7th;
	u32 testd;
	u32 rsvd_8[1];
	u32 arba;
	u32 rsvd_9[1];
	u32 arbb;
	u32 rsvd_10[1];
	u32 arbc;
	u32 rsvd_11[1];
	u32 arbd;
	u32 rsvd_12[1];
	u32 arbe;
	u32 rsvd_13[1];
	u32 arbf;
	u32 cong_8th;
	u32 arbg;
	u32 rsvd_14[1];
	u32 arbh;
	u32 conp_3rd;
	u32 arbi;
	u32 arbi_2nd;
	u32 rsvd_15[1];
	u32 arbj_2nd;
	u32 arbk;
	u32 arbk_2nd;
	u32 slct;
	u32 rsvd_16[1];
	u32 mpud0_st;
	u32 mpud1_st;
	u32 mpud2_st;
	u32 mpud3_st;
	u32 mpud4_st;
	u32 mpud5_st;
	u32 mpud6_st;
	u32 mpud7_st;
	u32 mpud8_st;
	u32 mpud9_st;
	u32 mpud10_st;
	u32 mpud11_st;
	u32 mpud12_st;
	u32 mpud13_st;
	u32 mpud14_st;
	u32 mpud15_st;
	u32 mpud16_st;
	u32 mpud17_st;
	u32 mpud18_st;
	u32 mpud19_st;
	u32 mpud20_st;
	u32 mpud21_st;
	u32 mpud22_st;
	u32 mpud23_st;
	u32 mpud24_st;
	u32 mpud25_st;
	u32 mpud26_st;
	u32 mpud27_st;
	u32 mpud28_st;
	u32 mpud29_st;
	u32 mpud30_st;
	u32 mpud31_st;
	u32 conp_4th;
	u32 conp_5th;
	u32 conp_6th;
	u32 rsvd_17[1];
	u32 mpus;
	u32 conp_8th;
	u32 mput;
	u32 mput_2nd;
	u32 d0_st2;
	u32 d1_st2;
	u32 d2_st2;
	u32 d3_st2;
	u32 d4_st2;
	u32 d5_st2;
	u32 d6_st2;
	u32 d7_st2;
	u32 d8_st2;
	u32 d9_st2;
	u32 d10_st2;
	u32 d11_st2;
	u32 d12_st2;
	u32 d13_st2;
	u32 d14_st2;
	u32 d15_st2;
	u32 d16_st2;
	u32 d17_st2;
	u32 d18_st2;
	u32 d19_st2;
	u32 d20_st2;
	u32 d21_st2;
	u32 d22_st2;
	u32 d23_st2;
	u32 d24_st2;
	u32 d25_st2;
	u32 d26_st2;
	u32 d27_st2;
	u32 d28_st2;
	u32 d29_st2;
	u32 d30_st2;
	u32 d31_st2;
	u32 rsvd_18[33];
	u32 prtcl_m0_cyc;
	u32 rsvd_19[1];
	u32 prtcl_m0_ctl;
	u32 rsvd_20[1];
	u32 prtcl_m0_msk;
	u32 rsvd_21[13];
	u32 prtcl_m1_cyc;
	u32 rsvd_22[1];
	u32 prtcl_m1_ctl;
	u32 rsvd_23[1];
	u32 prtcl_m1_msk;
	u32 rsvd_24[13];
	u32 prtcl_m2_cyc;
	u32 rsvd_25[1];
	u32 prtcl_m2_ctl;
	u32 rsvd_26[1];
	u32 prtcl_m2_msk;
	u32 rsvd_27[12];
	u32 prtcl_m3_cyc;
	u32 prtcl_m3_ctl;
	u32 prtcl_m3_msk;
	u32 rsvd_28[6];
	u32 prtcl_m4_cyc;
	u32 bmen;
	u32 bstp;
	u32 bcnt;
	u32 prtcl_m4_ctl;
	u32 tact;
	u32 prtcl_m4_msk;
	u32 tsct;
	u32 rsvd_29[1];
	u32 wact;
	u32 rsvd_30[1];
	u32 wsct;
	u32 rsvd_31[1];
	u32 bact;
	u32 rsvd_32[1];
	u32 bsct;
	u32 rsvd_33[1];
	u32 msel;
	u32 rsvd_34[1];
	u32 tsct2;
	u32 prtcl_m5_cyc;
	u32 tsct3;
	u32 prtcl_m5_ctl;
	u32 wsct2;
	u32 prtcl_m5_msk;
	u32 wsct3;
	u32 wsct4;
	u32 msel2;
	u32 rsvd_35[1];
	u32 msel3;
	u32 rsvd_36[1];
	u32 msel4;
	u32 rsvd_37[1];
	u32 msel5;
	u32 rsvd_38[1];
	u32 msel6;
	u32 rsvd_39[1];
	u32 msel7;
	u32 rsvd_40[1];
	u32 msel8;
	u32 prtcl_m6_cyc;
	u32 msel9;
	u32 prtcl_m6_ctl;
	u32 msel10;
	u32 prtcl_m6_msk;
	u32 bmid0;
	u32 bmid1;
	u32 bmid2;
	u32 bmid3;
	u32 bmid4;
	u32 bmid5;
	u32 bmid6;
	u32 bmid7;
	u32 bmid8;
	u32 bmid9;
	u32 bmid10;
	u32 rsvd_41[1];
	u32 bmen1;
	u32 rsvd_42[1];
	u32 bmen2;
	u32 rsvd_43[3];
	u32 bmrw0;
	u32 bmrw1;
	u32 ttype1;
	u32 rsvd_44[1];
	u32 ttype2;
	u32 prtcl_m7_cyc;
	u32 ttype3;
	u32 prtcl_m7_ctl;
	u32 ttype4;
	u32 prtcl_m7_msk;
	u32 ttype5;
	u32 rsvd_45[1];
	u32 ttype6;
	u32 rsvd_46[1];
	u32 ttype7;
	u32 rsvd_47[1];
	u32 ttype8;
	u32 rsvd_48[1];
	u32 ttype9;
	u32 rsvd_49[1];
	u32 ttype10;
	u32 rsvd_50[1];
	u32 ttype11;
	u32 rsvd_51[1];
	u32 ttype12;
	u32 rsvd_52[1];
	u32 ttype13;
	u32 rsvd_53[1];
	u32 ttype14;
	u32 rsvd_54[1];
	u32 ttype15;
	u32 rsvd_55[1];
	u32 ttype16;
	u32 rsvd_56[1];
	u32 ttype17;
	u32 rsvd_57[1];
	u32 ttype18;
	u32 rsvd_58[1];
	u32 ttype19;
	u32 rsvd_59[1];
	u32 ttype20;
	u32 rsvd_60[1];
	u32 ttype21;
	u32 rsvd_61[3];
	u32 bwct0;
	u32 bwct1;
	u32 bwct2;
	u32 bwct3;
	u32 bwct4;
	u32 bwst0;
	u32 bwst1;
	u32 rsvd_62[1];
	u32 ex_con;
	u32 ex_st0;
	u32 ex_st1;
	u32 ex_st2;
	u32 wp_adr;
	u32 wp_adr_2nd;
	u32 wp_ctrl;
	u32 rsvd_63[1];
	u32 chker;
	u32 chker_type;
	u32 chker_adr;
	u32 chker_adr_2nd;
	u32 rsvd_64[7];
	u32 thro_slv_con0;
	u32 rsvd_65[1];
	u32 thro_slv_con1;
	u32 mxto0;
	u32 mxto1;
	u32 rsvd_66[4];
	u32 conq_3rd;
	u32 conq_4th;
	u32 conq_5th;
	u32 conq_6th;
	u32 rsvd_67[4];
	u32 conq_7th;
	u32 conq_8th;
	u32 conr_3rd;
	u32 conr_4th;
	u32 rsvd_68[9];
	u32 conr_5th;
	u32 rsvd_69[2];
	u32 bwct0_2nd;
	u32 rsvd_70[25];
	u32 conr_6th;
	u32 conr_7th;
	u32 shf0;
	u32 dvfs_shf_con;
	u32 shf1;
	u32 clua;
	u32 rsvd_71[10];
	u32 conr_8th;
	u32 rsvd_72[1];
	u32 ltct0_2nd;
	u32 ltct1_2nd;
	u32 ltct2_2nd;
	u32 ltct3_2nd;
	u32 rsvd_73[4];
	u32 bwct0_3rd;
	u32 bwlmte_8th;
	u32 rsvd_74[1];
	u32 bwlmtf_8th;
	u32 bwct0_4th;
	u32 bwlmtg_8th;
	u32 rsvd_75[1];
	u32 bwlmth_8th;
	u32 rsvd_76[5];
	u32 chn_hash0;
	u32 rsvd_77[2];
	u32 bwct0_5th;
	u32 rsvd_78[5];
	u32 bwct0_6th;
	u32 rsvd_79[11];
	u32 snst;
	u32 rsvd_80[1];
	u32 slva;
	u32 rsvd_81[7];
	u32 thro_os0;
	u32 thro_os1;
	u32 thro_os2;
	u32 thro_os3;
	u32 thro_ctrl0;
	u32 thro_prd0;
	u32 thro_prd1;
	u32 thro_lat0;
	u32 thro_lat1;
	u32 thro_lat2;
	u32 thro_lat3;
	u32 thro_lat4;
	u32 thro_lat5;
	u32 thro_lat6;
	u32 thro_ctrl1;
	u32 thro_prd2;
	u32 rsvd_82[5];
	u32 thro_lat7;
	u32 thro_lat8;
	u32 thro_prd3;
	u32 rsvd_83[4];
	u32 bwlmta;
	u32 bwlmtb;
	u32 rsvd_84[2];
	u32 bwlmte;
	u32 bwlmtf;
	u32 rsvd_85[2];
	u32 conb_2nd;
	u32 conc_2nd;
	u32 cong_2nd;
	u32 rsvd_86[1];
	u32 thro_lat9;
	u32 thro_lat10;
	u32 thro_lat11;
	u32 thro_lat12;
	u32 thro_lat13;
	u32 thro_lat14;
	u32 rsvd_87[2];
	u32 bwlmte_2nd;
	u32 bwlmtf_2nd;
	u32 bwlmtg_2nd;
	u32 rsvd_88[13];
	u32 bwlmte_4th;
	u32 bwlmtf_4th;
	u32 rsvd_89[2];
	u32 bwlmte_5th;
	u32 bwlmtf_5th;
	u32 bwlmtg_5th;
	u32 rsvd_90[7];
	u32 bwlmtg_7th;
	u32 rsvd_91[12];
	u32 axi_bist_adr0;
	u32 axi_bist_adr1;
	u32 axi_bist_adr2;
	u32 rsvd_92[22];
	u32 thro_lat27;
	u32 thro_lat28;
	u32 thro_lat29;
	u32 thro_lat30;
	u32 rsvd_93[64];
	u32 thro_lat31;
	u32 thro_lat32;
	u32 thro_lat33;
	u32 thro_lat34;
	u32 thro_lat35;
	u32 thro_lat36;
	u32 rsvd_94[4];
	u32 thro_lat41;
	u32 thro_lat42;
	u32 rsvd_95[12];
	u32 thro_lat55;
	u32 thro_lat56;
	u32 rsvd_96[12];
	u32 thro_lat69;
	u32 thro_lat70;
	u32 rsvd_97[12];
	u32 thro_lat83;
	u32 thro_lat84;
	u32 rsvd_98[12];
	u32 thro_lat97;
	u32 thro_lat98;
	u32 rsvd_99[12];
	u32 thro_lat111;
	u32 thro_lat112;
	u32 rsvd_100[1];
	u32 thro_prd5;
	u32 rsvd_101[12];
	u32 thro_lat113;
	u32 thro_lat114;
	u32 thro_lat115;
	u32 thro_lat116;
	u32 thro_lat117;
	u32 thro_lat118;
	u32 thro_lat119;
	u32 thro_lat120;
	u32 rsvd_102[4];
	u32 thro_lat125;
	u32 thro_lat126;
	u32 rsvd_103[16];
	u32 thro_lat139;
	u32 thro_lat140;
	u32 rsvd_104[1];
	u32 qos_mdr_be0a;
	u32 rsvd_105[1];
	u32 qos_mdr_be1a;
	u32 rsvd_106[1];
	u32 qos_mdr_shf0;
	u32 qos_mdr_shf1;
	u32 qos_mdw_be0a;
	u32 rsvd_107[1];
	u32 qos_mdw_be1a;
	u32 rsvd_108[1];
	u32 qos_mdw_shf0;
	u32 qos_mdw_shf1;
	u32 qos_apr_be0a;
	u32 rsvd_109[1];
	u32 qos_apr_be1a;
	u32 rsvd_110[1];
	u32 qos_apr_shf0;
	u32 qos_apw_be0a;
	u32 rsvd_111[1];
	u32 qos_apw_be1a;
	u32 rsvd_112[1];
	u32 qos_mmr_be0a;
	u32 rsvd_113[1];
	u32 qos_mmr_be1a;
	u32 qos_mmr_be1b;
	u32 qos_mmr_be2a;
	u32 qos_mmr_be2b;
	u32 qos_mmr_shf0;
	u32 qos_mmr_shf1;
	u32 qos_mmw_be0a;
	u32 rsvd_114[1];
	u32 qos_mmw_be1a;
	u32 qos_mmw_be1b;
	u32 qos_mmw_be2a;
	u32 qos_mmw_be2b;
	u32 qos_mmw_shf0;
	u32 qos_mmw_shf1;
	u32 qos_mdhwr_be0a;
	u32 rsvd_115[1];
	u32 qos_mdhwr_be1a;
	u32 rsvd_116[1];
	u32 qos_mdhwr_shf0;
	u32 qos_mdhww_be0a;
	u32 rsvd_117[1];
	u32 qos_mdhww_be1a;
	u32 rsvd_118[1];
	u32 qos_gpur_be0a;
	u32 rsvd_119[1];
	u32 qos_gpur_be1a;
	u32 rsvd_120[1];
	u32 qos_gpur_shf0;
	u32 qos_gpuw_be0a;
	u32 rsvd_121[1];
	u32 qos_gpuw_be1a;
	u32 rsvd_122[1];
	u32 qos_arbr_be0a;
	u32 rsvd_123[1];
	u32 qos_arbr_be1a;
	u32 rsvd_124[1];
	u32 qos_arbr_shf0;
	u32 qos_ctrl1;
	u32 rsvd_125[3];
	u32 ext_lt_con1_1st;
	u32 ext_lt_con2_1st;
	u32 ext_lt_con3_1st;
	u32 rsvd_126[1];
	u32 ext_lt_con1_2nd;
	u32 ext_lt_con2_2nd;
	u32 ext_lt_con3_2nd;
	u32 rsvd_127[1];
	u32 ext_lt_con1_3rd;
	u32 ext_lt_con2_3rd;
	u32 ext_lt_con3_3rd;
	u32 rsvd_128[1];
	u32 ext_lt_con1_4th;
	u32 ext_lt_con2_4th;
	u32 ext_lt_con3_4th;
};

struct phy_ao_rk {
	u32 shu_r0_b0_txdly0;
	u32 shu_r0_b0_txdly1;
	u32 shu_r0_b0_txdly2;
	u32 shu_r0_b0_txdly3;
	u32 shu_r0_b0_txdly4;
	u32 shu_r0_b0_rxdly0;
	u32 shu_r0_b0_rxdly1;
	u32 shu_r0_b0_rxdly2;
	u32 shu_r0_b0_rxdly3;
	u32 shu_r0_b0_rxdly4;
	u32 shu_r0_b0_rxdly5;
	u32 shu_rk_b0_dq1;
	u32 shu_b0_phy_vref_sel;
	u32 shu_r0_b0_dq0;
	u32 shu_r0_b0_ini_uipi;
	u32 shu_r0_b0_next_ini_uipi;
	u32 shu_dqsien_mck_ui_dly;
	u32 shu_rk_b0_dqsien_pi_dly;
	u32 shu_rk_b0_rodten_mck_ui_dly;
	u32 shu_rk_b0_dq0;
	u32 rsvd_0[4];
	u32 shu_rk_b0_bist_ctrl;
	u32 rsvd_1[7];
};

struct phy_ao_shu_byte {
	struct phy_ao_rk rk[RANK_MAX];
	u32 shu_b0_dq0;
	u32 shu_b0_dq3;
	u32 shu_b0_dq4;
	u32 shu_b0_dq5;
	u32 shu_b0_dq6;
	u32 shu_b0_dq1;
	u32 shu_b0_dq2;
	u32 shu_b0_dq10;
	u32 shu_b0_dq11;
	u32 shu_b0_dq7;
	u32 shu_b0_dq8;
	u32 shu_b0_dq9;
	u32 shu_b0_dq12;
	u32 shu_b0_dll0;
	u32 shu_b0_dll1;
	u32 shu_b0_dll2;
	u32 shu_b0_rank_selph_ui_dly;
	u32 shu_b0_dll_arpi2;
	u32 shu_b0_dll_arpi3;
	u32 shu_b0_txduty;
	u32 shu_b0_vref;
	u32 shu_b0_dq13;
	u32 shu_b0_dq14;
	u32 b0_shu_midpi_ctrl;
	u32 rsvd_16[8];
};

struct phy_ao_rx_dvs_byte {
	struct {
		u32 rk_b0_rxdvs0;
		u32 rk_b0_rxdvs1;
		u32 rk_b0_rxdvs2;
		u32 rk_b0_rxdvs3;
		u32 rk_b0_rxdvs4;
		u32 rsvd[27];
	} rk[RANK_MAX];
	u32 b0_lp_ctrl0;
	u32 b0_rxdvs0;
	u32 b0_rxdvs1;
	u32 b0_dll_arpi0;
	u32 b0_dll_arpi1;
	u32 b0_dll_arpi4;
	u32 b0_dll_arpi5;
	u32 b0_dq2;
	u32 b0_dq3;
	u32 b0_dq4;
	u32 b0_dq5;
	u32 b0_dq6;
	u32 b0_dq7;
	u32 b0_dq8;
	u32 b0_dq9;
	u32 b0_dq10;
	u32 b0_dq11;
	u32 b0_phy2;
	u32 b0_phy3;
	u32 b0_tx_mck;
	u32 rsvd_3[12];
};

struct phy_ao_ca_rk {
	u32 shu_r0_ca_txdly0;
	u32 shu_r0_ca_txdly1;
	u32 shu_r0_ca_txdly2;
	u32 shu_r0_ca_txdly3;
	u32 shu_r0_ca_txdly4;
	u32 shu_r0_ca_rxdly0;
	u32 shu_r0_ca_rxdly1;
	u32 shu_r0_ca_rxdly2;
	u32 shu_r0_ca_rxdly6;
	u32 shu_r0_ca_rxdly3;
	u32 shu_r0_ca_rxdly4;
	u32 shu_r0_ca_rxdly5;
	u32 shu_r0_ca_rxdly7;
	u32 shu_r0_ca_cmd0;
	u32 shu_r0_ca_ini_uipi;
	u32 shu_r0_ca_next_ini_uipi;
	u32 shu_rk_ca_dqsien_mck_ui_dly;
	u32 shu_rk_ca_dqsien_pi_dly;
	u32 shu_rk_ca_rodten_mck_ui_dly;
	u32 shu_rk_ca_cmd0;
	u32 shu_rk_ca_cmd1;
	u32 shu_ca_phy_vref_sel;
	u32 rsvd[10];
};

struct phy_ao_misc_rk {
	u32 misc_shu_rk_dqsctl;
	u32 misc_shu_rk_dqsien_picg_ctrl;
	u32 misc_shu_rk_dqscal;
	u32 rsvd[29];
};

struct ddrphy_ao_regs {
	u32 phypll0;
	u32 phypll1;
	u32 phypll2;
	u32 rsvd_0[5];
	u32 clrpll0;
	u32 rsvd_1[15];
	struct phy_ao_rx_dvs_byte dvs_b[BYTE_NUM];
	u32 rk_ca_rxdvs0;
	u32 rk_ca_rxdvs1;
	u32 rk_ca_rxdvs2;
	u32 rk_ca_rxdvs3;
	u32 rk_ca_rxdvs4;
	u32 rsvd_6[59];
	u32 ca_lp_ctrl0;
	u32 ca_rxdvs0;
	u32 ca_rxdvs1;
	u32 ca_dll_arpi0;
	u32 ca_dll_arpi1;
	u32 ca_dll_arpi4;
	u32 ca_dll_arpi5;
	u32 ca_cmd2;
	u32 ca_cmd3;
	u32 ca_cmd4;
	u32 ca_cmd5;
	u32 ca_cmd6;
	u32 ca_cmd7;
	u32 ca_cmd8;
	u32 ca_cmd9;
	u32 ca_cmd10;
	u32 ca_cmd11;
	u32 ca_phy2;
	u32 ca_phy3;
	u32 ca_tx_mck;
	u32 rsvd_7[12];
	u32 misc_stbcal;
	u32 misc_stbcal1;
	u32 misc_stbcal2;
	u32 misc_cg_ctrl0;
	u32 misc_cg_ctrl1;
	u32 misc_cg_ctrl2;
	u32 misc_cg_ctrl3;
	u32 rsvd_8[1];
	u32 misc_cg_ctrl5;
	u32 misc_cg_ctrl7;
	u32 misc_cg_ctrl9;
	u32 misc_cg_ctrl10;
	u32 misc_dvfsctl;
	u32 misc_dvfsctl2;
	u32 misc_dvfsctl3;
	u32 misc_ckmux_sel;
	u32 misc_clk_ctrl;
	u32 misc_dqsg_retry1;
	u32 misc_rdsel_track;
	u32 misc_pre_tdqsck1;
	u32 misc_cdc_ctrl;
	u32 misc_lp_ctrl;
	u32 misc_rg_dfs_ctrl;
	u32 misc_ddr_reserve;
	u32 misc_imp_ctrl1;
	u32 misc_impcal;
	u32 misc_impcal1;
	u32 misc_impedamce_ctrl1;
	u32 misc_impedamce_ctrl2;
	u32 misc_impedamce_ctrl3;
	u32 misc_impedamce_ctrl4;
	u32 misc_peripher_ctrl2;
	u32 misc_apb;
	u32 misc_extlb0;
	u32 misc_extlb1;
	u32 misc_extlb2;
	u32 misc_extlb3;
	u32 misc_extlb4;
	u32 misc_extlb5;
	u32 misc_extlb6;
	u32 misc_extlb7;
	u32 misc_extlb8;
	u32 misc_extlb9;
	u32 misc_extlb10;
	u32 misc_extlb11;
	u32 misc_extlb12;
	u32 misc_extlb13;
	u32 misc_extlb14;
	u32 misc_extlb15;
	u32 misc_extlb16;
	u32 misc_extlb17;
	u32 misc_extlb18;
	u32 misc_extlb19;
	u32 misc_extlb20;
	u32 misc_extlb21;
	u32 misc_extlb22;
	u32 misc_extlb23;
	u32 misc_extlb_rx0;
	u32 misc_extlb_rx1;
	u32 misc_extlb_rx2;
	u32 misc_extlb_rx3;
	u32 misc_extlb_rx4;
	u32 misc_extlb_rx5;
	u32 misc_extlb_rx6;
	u32 misc_extlb_rx7;
	u32 misc_extlb_rx8;
	u32 misc_extlb_rx9;
	u32 misc_extlb_rx10;
	u32 misc_extlb_rx11;
	u32 misc_extlb_rx12;
	u32 misc_extlb_rx13;
	u32 misc_extlb_rx14;
	u32 misc_extlb_rx15;
	u32 misc_extlb_rx16;
	u32 misc_extlb_rx17;
	u32 misc_extlb_rx18;
	u32 misc_extlb_rx19;
	u32 misc_extlb_rx20;
	u32 misc_sram_dma0;
	u32 misc_sram_dma1;
	u32 misc_sram_dma2;
	u32 misc_dutyscan1;
	u32 misc_miock_jit_mtr;
	u32 misc_jmeter;
	u32 misc_dvfs_emi_clk;
	u32 misc_rx_in_gate_en_ctrl;
	u32 misc_rx_in_buff_en_ctrl;
	u32 misc_ctrl0;
	u32 misc_ctrl1;
	u32 misc_ctrl2;
	u32 misc_ctrl3;
	u32 misc_ctrl4;
	u32 misc_ctrl5;
	u32 misc_ctrl6;
	u32 misc_vref_ctrl;
	u32 misc_shu_opt;
	u32 misc_rxdvs0;
	u32 misc_rxdvs2;
	u32 misc_dqsien_autok_cfg0;
	u32 misc_dline_mon_cfg;
	u32 misc_rx_autok_cfg0;
	u32 misc_rx_autok_cfg1;
	u32 rsvd_9[2];
	u32 misc_dbg_irq_ctrl0;
	u32 misc_dbg_irq_ctrl1;
	u32 misc_dbg_irq_ctrl2;
	u32 misc_dbg_irq_ctrl3;
	u32 misc_dbg_irq_ctrl4;
	u32 misc_dbg_irq_ctrl5;
	u32 misc_dbg_irq_ctrl6;
	u32 misc_dbg_irq_ctrl7;
	u32 misc_dbg_irq_ctrl8;
	u32 misc_dbg_irq_ctrl9;
	u32 rsvd_10[2];
	u32 misc_dq_se_pinmux_ctrl0;
	u32 misc_dq_se_pinmux_ctrl1;
	u32 rsvd_11[2];
	u32 misc_bist_lpbk_ctrl0;
	u32 rsvd_12[15];
	u32 shu_phypll0;
	u32 shu_phypll1;
	u32 shu_phypll2;
	u32 shu_phypll3;
	u32 shu_phypll4;
	u32 shu_phypll5;
	u32 shu_phypll6;
	u32 shu_phypll7;
	u32 shu_clrpll0;
	u32 shu_clrpll1;
	u32 shu_clrpll2;
	u32 shu_clrpll3;
	u32 shu_clrpll4;
	u32 shu_clrpll5;
	u32 shu_clrpll6;
	u32 shu_clrpll7;
	u32 shu_pll0;
	u32 shu_pll1;
	u32 shu_pll2;
	u32 rsvd_13[5];
	struct phy_ao_shu_byte byte[BYTE_NUM];
	struct phy_ao_ca_rk ca_rk[RANK_MAX];
	u32 shu_ca_cmd0;
	u32 shu_ca_cmd3;
	u32 shu_ca_cmd4;
	u32 shu_ca_cmd5;
	u32 shu_ca_cmd6;
	u32 shu_ca_cmd1;
	u32 shu_ca_cmd2;
	u32 shu_ca_cmd10;
	u32 shu_ca_cmd11;
	u32 shu_ca_cmd7;
	u32 shu_ca_cmd8;
	u32 shu_ca_cmd9;
	u32 shu_ca_cmd12;
	u32 shu_ca_dll0;
	u32 shu_ca_dll1;
	u32 shu_ca_dll2;
	u32 shu_ca_rank_selph_ui_dly;
	u32 shu_ca_dll_arpi2;
	u32 shu_ca_dll_arpi3;
	u32 shu_ca_txduty;
	u32 shu_ca_vref;
	u32 shu_ca_cmd13;
	u32 shu_ca_cmd14;
	u32 ca_shu_midpi_ctrl;
	u32 rsvd_21[8];
	struct phy_ao_misc_rk misc_rk[RANK_MAX];
	u32 misc_shu_drving7;
	u32 misc_shu_drving8;
	u32 misc_shu_impedamce_offset1;
	u32 misc_shu_impedamce_offset2;
	u32 misc_shu_impedamce_offset3;
	u32 misc_shu_impedamce_offset4;
	u32 misc_shu_impedamce_offset5;
	u32 misc_shu_impedamce_offset6;
	u32 misc_shu_impedamce_offset7;
	u32 misc_shu_impedamce_offset8;
	u32 misc_shu_impedamce_offset9;
	u32 misc_shu_impedamce_upd_dis1;
	u32 shu_misc_sw_impcal;
	u32 misc_shu_stbcal;
	u32 misc_shu_stbcal1;
	u32 misc_shu_dvfsdll;
	u32 misc_shu_rankctl;
	u32 misc_shu_phy_rx_ctrl;
	u32 misc_shu_odtctrl;
	u32 misc_shu_rodtenstb;
	u32 misc_shu_rodtenstb1;
	u32 misc_shu_dqsg_retry1;
	u32 misc_shu_rdat;
	u32 misc_shu_rdat1;
	u32 shu_misc_clk_ctrl0;
	u32 shu_misc_impcal1;
	u32 shu_misc_drving1;
	u32 shu_misc_drving2;
	u32 shu_misc_drving3;
	u32 shu_misc_drving4;
	u32 shu_misc_drving5;
	u32 shu_misc_drving6;
	u32 shu_misc_duty_scan;
	u32 shu_misc_dma;
	u32 shu_misc_rvref;
	u32 shu_misc_rx_pipe_ctrl;
	u32 shu_misc_tx_pipe_ctrl;
	u32 shu_misc_emi_ctrl;
	u32 shu_misc_rank_sel_stb;
	u32 shu_misc_rdsel_track;
	u32 shu_misc_pre_tdqsck;
	u32 shu_misc_async_fifo_ctrl;
	u32 misc_shu_rx_selph_mode;
	u32 misc_shu_rank_sel_lat;
	u32 misc_shu_dline_mon_ctrl;
	u32 misc_shu_dline_mon_cnt;
	u32 misc_shu_midpi_ctrl;
	u32 rsvd_23[1];
	u32 misc_shu_rx_cg_ctrl;
	u32 misc_shu_cg_ctrl0;
	u32 rsvd_24[470];
	u32 misc_stberr_all;
	u32 misc_stberr_rk0_r;
	u32 misc_stberr_rk0_f;
	u32 misc_stberr_rk1_r;
	u32 misc_stberr_rk1_f;
	u32 rsvd_25[3];
	u32 misc_ddr_reserve_state;
	u32 rsvd_26[3];
	u32 misc_irq_status0;
	u32 misc_irq_status1;
	u32 misc_irq_status2;
	u32 rsvd_27[49];
	u32 misc_dbg_db_message0;
	u32 misc_dbg_db_message1;
	u32 misc_dbg_db_message2;
	u32 misc_dbg_db_message3;
	u32 misc_dbg_db_message4;
	u32 misc_dbg_db_message5;
	u32 misc_dbg_db_message6;
	u32 misc_dbg_db_message7;
};

struct emi_chn_regs {
	u32 cona;
	u32 rsvd_0[1];
	u32 conb;
	u32 rsvd_1[1];
	u32 conc;
	u32 rsvd_2[1];
	u32 mdct;
	u32 rsvd_3[1];
	u32 ebg_con;
	u32 rsvd_4[9];
	u32 testb;
	u32 rsvd_5[1];
	u32 testc;
	u32 rsvd_6[1];
	u32 testd;
	u32 rsvd_7[9];
	u32 md_pre_mask;
	u32 rsvd_8[1];
	u32 md_pre_mask_shf;
	u32 rsvd_9[1];
	u32 ap_early_cke;
	u32 rsvd_10[1];
	u32 dqfr;
	u32 rsvd_11[41];
	u32 arbi;
	u32 arbi_2nd;
	u32 arbj;
	u32 arbj_2nd;
	u32 arbk;
	u32 arbk_2nd;
	u32 slct;
	u32 arb_rff;
	u32 rsvd_12[3];
	u32 drs_mon0;
	u32 drs_mon1;
	u32 rsvd_13[15];
	u32 rkarb0;
	u32 rkarb1;
	u32 rkarb2;
	u32 rsvd_14[144];
	u32 eco3;
	u32 rsvd_15[1];
	u32 md_pre_mask_shf0;
	u32 md_pre_mask_shf1;
	u32 qos_mdr_shf0;
	u32 rsvd_16[192];
	u32 shf0;
};

struct emi_mpu_regs {
	u32 mpu_ctrl;
	u32 rsvd[511];
	u32 mpu_ctrl_d[16];
};

struct infra_ao_mem_regs {
	u32 rsvd_0[10];
	u32 emi_dcm_cfg0;
	u32 emi_dcm_cfg1;
	u32 emi_dcm_cfg2;
	u32 emi_dcm_cfg3;
	u32 top_ck_anchor_cfg;
	u32 rsvd_2[5];
	u32 emi_disph_cfg;
	u32 rsvd_3[43];
	u32 emi_idle_bit_en_0;
	u32 emi_idle_bit_en_1;
	u32 emi_idle_bit_en_2;
	u32 emi_idle_bit_en_3;
	u32 emi_m0m1_idle_bit_en_0;
	u32 emi_m0m1_idle_bit_en_1;
	u32 emi_m0m1_idle_bit_en_2;
	u32 emi_m0m1_idle_bit_en_3;
	u32 emi_m2m5_idle_bit_en_0;
	u32 emi_m2m5_idle_bit_en_1;
	u32 emi_m2m5_idle_bit_en_2;
	u32 emi_m2m5_idle_bit_en_3;
	u32 emi_m3_idle_bit_en_0;
	u32 emi_m3_idle_bit_en_1;
	u32 emi_m3_idle_bit_en_2;
	u32 emi_m3_idle_bit_en_3;
	u32 emi_m4_idle_bit_en_0;
	u32 emi_m4_idle_bit_en_1;
	u32 emi_m4_idle_bit_en_2;
	u32 emi_m4_idle_bit_en_3;
	u32 emi_m6m7_idle_bit_en_0;
	u32 emi_m6m7_idle_bit_en_1;
	u32 emi_m6m7_idle_bit_en_2;
	u32 emi_m6m7_idle_bit_en_3;
	u32 emi_sram_idle_bit_en_0;
	u32 emi_sram_idle_bit_en_1;
	u32 emi_sram_idle_bit_en_2;
	u32 emi_sram_idle_bit_en_3;
};

struct dramc_channel_regs {
	union {
		struct dramc_ao_regs ao;
		uint8_t raw_ao_regs[0x4000];
	};
	union {
		struct dramc_nao_regs nao;
		uint8_t raw_nao_regs[0x1000];
	};
	union {
		struct emi_chn_regs emi_chn;
		uint8_t raw_emi_regs[0x1000];
	};
	union {
		struct ddrphy_nao_regs phy_nao;
		uint8_t raw_ddrphy_nao_regs[0x2000];
	};
	union {
		struct ddrphy_ao_regs phy_ao;
		uint8_t raw_ddrphy_ao_regs[0x8000];
	};
};

static struct dramc_channel_regs *const ch = (void *)DRAMC_CHA_AO_BASE;
#endif /* __SOC_MEDIATEK_MT8192_DRAMC_REGISTER_H__ */
