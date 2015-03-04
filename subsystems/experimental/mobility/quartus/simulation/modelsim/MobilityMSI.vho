-- Copyright (C) 1991-2014 Altera Corporation. All rights reserved.
-- Your use of Altera Corporation's design tools, logic functions 
-- and other software and tools, and its AMPP partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Altera Program License 
-- Subscription Agreement, the Altera Quartus II License Agreement,
-- the Altera MegaCore Function License Agreement, or other 
-- applicable license agreement, including, without limitation, 
-- that your use is for the sole purpose of programming logic 
-- devices manufactured by Altera and sold by Altera or its 
-- authorized distributors.  Please refer to the applicable 
-- agreement for further details.

-- VENDOR "Altera"
-- PROGRAM "Quartus II 64-Bit"
-- VERSION "Version 14.0.0 Build 200 06/17/2014 SJ Web Edition"

-- DATE "03/04/2015 22:20:33"

-- 
-- Device: Altera 5M1270ZT144C5 Package TQFP144
-- 

-- 
-- This VHDL file should be used for ModelSim-Altera (VHDL) only
-- 

LIBRARY IEEE;
LIBRARY MAXV;
LIBRARY WORK;
USE IEEE.STD_LOGIC_1164.ALL;
USE MAXV.MAXV_COMPONENTS.ALL;
USE WORK.MOBILITY_TYPES_PKG.ALL;

ENTITY 	MobilityMSI IS
    PORT (
	clk50 : IN std_logic;
	clk0_001 : IN std_logic;
	rst_n : IN std_logic;
	lock : IN std_logic;
	status : OUT std_logic_vector(7 DOWNTO 0);
	scl_host : OUT std_logic;
	sda_host : INOUT std_logic;
	scl_slave : IN std_logic;
	sda_slave : INOUT std_logic;
	miso_host : IN std_logic;
	mosi_host : OUT std_logic;
	sclk_host : OUT std_logic;
	ss_n_host : OUT std_logic_vector(7 DOWNTO 0);
	miso_slave : OUT std_logic;
	mosi_slave : IN std_logic;
	sclk_slave : IN std_logic;
	ss_n_slave : IN std_logic;
	uart_rx : IN std_logic;
	uart_tx : OUT std_logic;
	motors : OUT WORK.MOBILITY_TYPES_PKG.motors_t;
	encoders : IN WORK.MOBILITY_TYPES_PKG.encoders_t;
	ultrsnic_trig : OUT std_logic_vector(7 DOWNTO 0);
	ultrsnic_echo : IN std_logic_vector(7 DOWNTO 0)
	);
END MobilityMSI;

-- Design Ports Information
-- clk0_001	=>  Location: PIN_118,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- lock	=>  Location: PIN_12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- status[0]	=>  Location: PIN_32,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[1]	=>  Location: PIN_31,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[2]	=>  Location: PIN_30,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[3]	=>  Location: PIN_29,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[4]	=>  Location: PIN_28,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[5]	=>  Location: PIN_27,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[6]	=>  Location: PIN_6,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- status[7]	=>  Location: PIN_39,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- scl_host	=>  Location: PIN_66,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- scl_slave	=>  Location: PIN_8,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- miso_host	=>  Location: PIN_72,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- mosi_host	=>  Location: PIN_84,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- sclk_host	=>  Location: PIN_91,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[0]	=>  Location: PIN_137,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[1]	=>  Location: PIN_104,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[2]	=>  Location: PIN_123,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[3]	=>  Location: PIN_139,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[4]	=>  Location: PIN_1,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[5]	=>  Location: PIN_49,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[6]	=>  Location: PIN_74,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ss_n_host[7]	=>  Location: PIN_71,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- miso_slave	=>  Location: PIN_3,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- mosi_slave	=>  Location: PIN_4,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- sclk_slave	=>  Location: PIN_80,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ss_n_slave	=>  Location: PIN_108,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- uart_rx	=>  Location: PIN_24,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- uart_tx	=>  Location: PIN_23,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[9][0]	=>  Location: PIN_45,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[9][1]	=>  Location: PIN_53,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[9][2]	=>  Location: PIN_15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[8][0]	=>  Location: PIN_103,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[8][1]	=>  Location: PIN_73,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[8][2]	=>  Location: PIN_16,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[7][0]	=>  Location: PIN_37,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[7][1]	=>  Location: PIN_110,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[7][2]	=>  Location: PIN_96,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[6][0]	=>  Location: PIN_105,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[6][1]	=>  Location: PIN_75,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[6][2]	=>  Location: PIN_57,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[5][0]	=>  Location: PIN_89,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[5][1]	=>  Location: PIN_88,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[5][2]	=>  Location: PIN_114,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[4][0]	=>  Location: PIN_48,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[4][1]	=>  Location: PIN_144,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[4][2]	=>  Location: PIN_52,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[3][0]	=>  Location: PIN_40,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[3][1]	=>  Location: PIN_63,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[3][2]	=>  Location: PIN_106,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[2][0]	=>  Location: PIN_69,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[2][1]	=>  Location: PIN_94,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[2][2]	=>  Location: PIN_143,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[1][0]	=>  Location: PIN_140,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[1][1]	=>  Location: PIN_13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[1][2]	=>  Location: PIN_112,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[0][0]	=>  Location: PIN_127,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[0][1]	=>  Location: PIN_107,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- motors[0][2]	=>  Location: PIN_119,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- encoders[9][0]	=>  Location: PIN_120,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[9][1]	=>  Location: PIN_138,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[8][0]	=>  Location: PIN_85,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[8][1]	=>  Location: PIN_142,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[7][0]	=>  Location: PIN_125,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[7][1]	=>  Location: PIN_122,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[6][0]	=>  Location: PIN_124,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[6][1]	=>  Location: PIN_14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[5][0]	=>  Location: PIN_129,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[5][1]	=>  Location: PIN_51,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[4][0]	=>  Location: PIN_5,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[4][1]	=>  Location: PIN_97,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[3][0]	=>  Location: PIN_134,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[3][1]	=>  Location: PIN_22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[2][0]	=>  Location: PIN_111,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[2][1]	=>  Location: PIN_95,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[1][0]	=>  Location: PIN_81,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[1][1]	=>  Location: PIN_121,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[0][0]	=>  Location: PIN_38,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- encoders[0][1]	=>  Location: PIN_109,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_trig[0]	=>  Location: PIN_133,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[1]	=>  Location: PIN_86,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[2]	=>  Location: PIN_98,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[3]	=>  Location: PIN_50,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[4]	=>  Location: PIN_41,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[5]	=>  Location: PIN_101,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[6]	=>  Location: PIN_42,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_trig[7]	=>  Location: PIN_93,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- ultrsnic_echo[0]	=>  Location: PIN_62,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[1]	=>  Location: PIN_61,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[2]	=>  Location: PIN_87,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[3]	=>  Location: PIN_2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[4]	=>  Location: PIN_76,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[5]	=>  Location: PIN_77,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[6]	=>  Location: PIN_21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- ultrsnic_echo[7]	=>  Location: PIN_79,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- sda_host	=>  Location: PIN_67,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- sda_slave	=>  Location: PIN_7,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
-- clk50	=>  Location: PIN_18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
-- rst_n	=>  Location: PIN_20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default


ARCHITECTURE structure OF MobilityMSI IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_clk50 : std_logic;
SIGNAL ww_clk0_001 : std_logic;
SIGNAL ww_rst_n : std_logic;
SIGNAL ww_lock : std_logic;
SIGNAL ww_status : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_scl_host : std_logic;
SIGNAL ww_scl_slave : std_logic;
SIGNAL ww_miso_host : std_logic;
SIGNAL ww_mosi_host : std_logic;
SIGNAL ww_sclk_host : std_logic;
SIGNAL ww_ss_n_host : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_miso_slave : std_logic;
SIGNAL ww_mosi_slave : std_logic;
SIGNAL ww_sclk_slave : std_logic;
SIGNAL ww_ss_n_slave : std_logic;
SIGNAL ww_uart_rx : std_logic;
SIGNAL ww_uart_tx : std_logic;
SIGNAL ww_motors : WORK.MOBILITY_TYPES_PKG.motors_t;
SIGNAL ww_encoders : WORK.MOBILITY_TYPES_PKG.encoders_t;
SIGNAL ww_ultrsnic_trig : std_logic_vector(7 DOWNTO 0);
SIGNAL ww_ultrsnic_echo : std_logic_vector(7 DOWNTO 0);
SIGNAL \clk50~combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~30_combout\ : std_logic;
SIGNAL \rst_n~combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~32\ : std_logic;
SIGNAL \UART0|UART0|Add0~32COUT1_48\ : std_logic;
SIGNAL \UART0|UART0|Add0~20_combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~22\ : std_logic;
SIGNAL \UART0|UART0|Add0~22COUT1_50\ : std_logic;
SIGNAL \UART0|UART0|Add0~25_combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~27\ : std_logic;
SIGNAL \UART0|UART0|Add0~27COUT1_52\ : std_logic;
SIGNAL \UART0|UART0|Add0~15_combout\ : std_logic;
SIGNAL \UART0|UART0|Equal0~1\ : std_logic;
SIGNAL \UART0|UART0|Add0~37\ : std_logic;
SIGNAL \UART0|UART0|Add0~37COUT1_56\ : std_logic;
SIGNAL \UART0|UART0|Add0~5_combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~7\ : std_logic;
SIGNAL \UART0|UART0|Add0~7COUT1_58\ : std_logic;
SIGNAL \UART0|UART0|Add0~0_combout\ : std_logic;
SIGNAL \UART0|UART0|Equal0~0\ : std_logic;
SIGNAL \UART0|UART0|Equal0~2\ : std_logic;
SIGNAL \UART0|UART0|Add0~17\ : std_logic;
SIGNAL \UART0|UART0|Add0~17COUT1_54\ : std_logic;
SIGNAL \UART0|UART0|Add0~10_combout\ : std_logic;
SIGNAL \UART0|UART0|Add0~12\ : std_logic;
SIGNAL \UART0|UART0|Add0~35_combout\ : std_logic;
SIGNAL \UART0|UART0|Top16~regout\ : std_logic;
SIGNAL \UART0|UART0|Add1~0_combout\ : std_logic;
SIGNAL \UART0|UART0|Add1~2\ : std_logic;
SIGNAL \UART0|UART0|Add1~2COUT1_31\ : std_logic;
SIGNAL \UART0|UART0|Add1~15_combout\ : std_logic;
SIGNAL \UART0|UART0|Add1~17\ : std_logic;
SIGNAL \UART0|UART0|Add1~17COUT1_33\ : std_logic;
SIGNAL \UART0|UART0|Add1~10_combout\ : std_logic;
SIGNAL \UART0|UART0|Add1~12\ : std_logic;
SIGNAL \UART0|UART0|Add1~12COUT1_35\ : std_logic;
SIGNAL \UART0|UART0|Add1~7\ : std_logic;
SIGNAL \UART0|UART0|Add1~7COUT1_37\ : std_logic;
SIGNAL \UART0|UART0|Add1~20_combout\ : std_logic;
SIGNAL \UART0|UART0|Add1~5_combout\ : std_logic;
SIGNAL \UART0|UART0|Equal1~0\ : std_logic;
SIGNAL \UART0|UART0|TopTx~regout\ : std_logic;
SIGNAL \UART0|UART0|TxReg[0]~1_combout\ : std_logic;
SIGNAL \UART0|UART0|Add3~0_combout\ : std_logic;
SIGNAL \UART0|UART0|Mux10~0_combout\ : std_logic;
SIGNAL \UART0|UART0|TxBitCnt\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \UART0|UART0|ClkDiv\ : std_logic_vector(4 DOWNTO 0);
SIGNAL \UART0|UART0|TxReg\ : std_logic_vector(9 DOWNTO 0);
SIGNAL \UART0|UART0|TxFSM\ : std_logic_vector(1 DOWNTO 0);
SIGNAL \UART0|UART0|Div16\ : std_logic_vector(7 DOWNTO 0);
SIGNAL \ALT_INV_rst_n~combout\ : std_logic;
SIGNAL \UART0|UART0|ALT_INV_TxReg\ : std_logic_vector(0 DOWNTO 0);

BEGIN

ww_clk50 <= clk50;
ww_clk0_001 <= clk0_001;
ww_rst_n <= rst_n;
ww_lock <= lock;
status <= ww_status;
scl_host <= ww_scl_host;
ww_scl_slave <= scl_slave;
ww_miso_host <= miso_host;
mosi_host <= ww_mosi_host;
sclk_host <= ww_sclk_host;
ss_n_host <= ww_ss_n_host;
miso_slave <= ww_miso_slave;
ww_mosi_slave <= mosi_slave;
ww_sclk_slave <= sclk_slave;
ww_ss_n_slave <= ss_n_slave;
ww_uart_rx <= uart_rx;
uart_tx <= ww_uart_tx;
motors <= ww_motors;
ww_encoders <= encoders;
ultrsnic_trig <= ww_ultrsnic_trig;
ww_ultrsnic_echo <= ultrsnic_echo;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_rst_n~combout\ <= NOT \rst_n~combout\;
\UART0|UART0|ALT_INV_TxReg\(0) <= NOT \UART0|UART0|TxReg\(0);

-- Location: PIN_18,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\clk50~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_clk50,
	combout => \clk50~combout\);

-- Location: LC_X2_Y5_N0
\UART0|UART0|Add0~30\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~30_combout\ = ((!\UART0|UART0|Div16\(0)))
-- \UART0|UART0|Add0~32\ = CARRY(((\UART0|UART0|Div16\(0))))
-- \UART0|UART0|Add0~32COUT1_48\ = CARRY(((\UART0|UART0|Div16\(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "33cc",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|Div16\(0),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~30_combout\,
	cout0 => \UART0|UART0|Add0~32\,
	cout1 => \UART0|UART0|Add0~32COUT1_48\);

-- Location: PIN_20,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\rst_n~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_rst_n,
	combout => \rst_n~combout\);

-- Location: LC_X1_Y5_N6
\UART0|UART0|Div16[0]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(0) = DFFEAS((((\UART0|UART0|Add0~30_combout\ & !\UART0|UART0|Equal0~2\))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "00f0",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add0~30_combout\,
	datad => \UART0|UART0|Equal0~2\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(0));

-- Location: LC_X2_Y5_N1
\UART0|UART0|Add0~20\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~20_combout\ = (\UART0|UART0|Div16\(1) $ ((\UART0|UART0|Add0~32\)))
-- \UART0|UART0|Add0~22\ = CARRY(((!\UART0|UART0|Add0~32\) # (!\UART0|UART0|Div16\(1))))
-- \UART0|UART0|Add0~22COUT1_50\ = CARRY(((!\UART0|UART0|Add0~32COUT1_48\) # (!\UART0|UART0|Div16\(1))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|Div16\(1),
	cin0 => \UART0|UART0|Add0~32\,
	cin1 => \UART0|UART0|Add0~32COUT1_48\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~20_combout\,
	cout0 => \UART0|UART0|Add0~22\,
	cout1 => \UART0|UART0|Add0~22COUT1_50\);

-- Location: LC_X2_Y5_N9
\UART0|UART0|Div16[1]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(1) = DFFEAS((((!\UART0|UART0|Equal0~2\ & \UART0|UART0|Add0~20_combout\))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0f00",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Equal0~2\,
	datad => \UART0|UART0|Add0~20_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(1));

-- Location: LC_X2_Y5_N2
\UART0|UART0|Add0~25\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~25_combout\ = (\UART0|UART0|Div16\(2) $ ((!\UART0|UART0|Add0~22\)))
-- \UART0|UART0|Add0~27\ = CARRY(((\UART0|UART0|Div16\(2) & !\UART0|UART0|Add0~22\)))
-- \UART0|UART0|Add0~27COUT1_52\ = CARRY(((\UART0|UART0|Div16\(2) & !\UART0|UART0|Add0~22COUT1_50\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|Div16\(2),
	cin0 => \UART0|UART0|Add0~22\,
	cin1 => \UART0|UART0|Add0~22COUT1_50\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~25_combout\,
	cout0 => \UART0|UART0|Add0~27\,
	cout1 => \UART0|UART0|Add0~27COUT1_52\);

-- Location: LC_X1_Y5_N7
\UART0|UART0|Div16[2]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Equal0~1\ = (!\UART0|UART0|Div16\(0) & (\UART0|UART0|Div16\(3) & (!N1_Div16[2] & \UART0|UART0|Div16\(1))))
-- \UART0|UART0|Div16\(2) = DFFEAS(\UART0|UART0|Equal0~1\, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , \UART0|UART0|Add0~25_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0400",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|Div16\(0),
	datab => \UART0|UART0|Div16\(3),
	datac => \UART0|UART0|Add0~25_combout\,
	datad => \UART0|UART0|Div16\(1),
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Equal0~1\,
	regout => \UART0|UART0|Div16\(2));

-- Location: LC_X2_Y5_N3
\UART0|UART0|Add0~15\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~15_combout\ = (\UART0|UART0|Div16\(3) $ ((\UART0|UART0|Add0~27\)))
-- \UART0|UART0|Add0~17\ = CARRY(((!\UART0|UART0|Add0~27\) # (!\UART0|UART0|Div16\(3))))
-- \UART0|UART0|Add0~17COUT1_54\ = CARRY(((!\UART0|UART0|Add0~27COUT1_52\) # (!\UART0|UART0|Div16\(3))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|Div16\(3),
	cin0 => \UART0|UART0|Add0~27\,
	cin1 => \UART0|UART0|Add0~27COUT1_52\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~15_combout\,
	cout0 => \UART0|UART0|Add0~17\,
	cout1 => \UART0|UART0|Add0~17COUT1_54\);

-- Location: LC_X1_Y5_N2
\UART0|UART0|Div16[3]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(3) = DFFEAS((((\UART0|UART0|Add0~15_combout\ & !\UART0|UART0|Equal0~2\))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "00f0",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add0~15_combout\,
	datad => \UART0|UART0|Equal0~2\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(3));

-- Location: LC_X2_Y5_N5
\UART0|UART0|Add0~35\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~35_combout\ = \UART0|UART0|Div16\(5) $ ((((\UART0|UART0|Add0~12\))))
-- \UART0|UART0|Add0~37\ = CARRY(((!\UART0|UART0|Add0~12\)) # (!\UART0|UART0|Div16\(5)))
-- \UART0|UART0|Add0~37COUT1_56\ = CARRY(((!\UART0|UART0|Add0~12\)) # (!\UART0|UART0|Div16\(5)))

-- pragma translate_off
GENERIC MAP (
	cin_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|Div16\(5),
	cin => \UART0|UART0|Add0~12\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~35_combout\,
	cout0 => \UART0|UART0|Add0~37\,
	cout1 => \UART0|UART0|Add0~37COUT1_56\);

-- Location: LC_X2_Y5_N6
\UART0|UART0|Add0~5\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~5_combout\ = \UART0|UART0|Div16\(6) $ ((((!(!\UART0|UART0|Add0~12\ & \UART0|UART0|Add0~37\) # (\UART0|UART0|Add0~12\ & \UART0|UART0|Add0~37COUT1_56\)))))
-- \UART0|UART0|Add0~7\ = CARRY((\UART0|UART0|Div16\(6) & ((!\UART0|UART0|Add0~37\))))
-- \UART0|UART0|Add0~7COUT1_58\ = CARRY((\UART0|UART0|Div16\(6) & ((!\UART0|UART0|Add0~37COUT1_56\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|Div16\(6),
	cin => \UART0|UART0|Add0~12\,
	cin0 => \UART0|UART0|Add0~37\,
	cin1 => \UART0|UART0|Add0~37COUT1_56\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~5_combout\,
	cout0 => \UART0|UART0|Add0~7\,
	cout1 => \UART0|UART0|Add0~7COUT1_58\);

-- Location: LC_X1_Y5_N5
\UART0|UART0|Div16[6]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(6) = DFFEAS(GND, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , \UART0|UART0|Add0~5_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add0~5_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(6));

-- Location: LC_X1_Y5_N0
\UART0|UART0|Div16[7]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Equal0~0\ = (!\UART0|UART0|Div16\(6) & (((!N1_Div16[7]))))
-- \UART0|UART0|Div16\(7) = DFFEAS(\UART0|UART0|Equal0~0\, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , \UART0|UART0|Add0~0_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0505",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|Div16\(6),
	datac => \UART0|UART0|Add0~0_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Equal0~0\,
	regout => \UART0|UART0|Div16\(7));

-- Location: LC_X2_Y5_N7
\UART0|UART0|Add0~0\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~0_combout\ = (((!\UART0|UART0|Add0~12\ & \UART0|UART0|Add0~7\) # (\UART0|UART0|Add0~12\ & \UART0|UART0|Add0~7COUT1_58\) $ (\UART0|UART0|Div16\(7))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	cin_used => "true",
	lut_mask => "0ff0",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datad => \UART0|UART0|Div16\(7),
	cin => \UART0|UART0|Add0~12\,
	cin0 => \UART0|UART0|Add0~7\,
	cin1 => \UART0|UART0|Add0~7COUT1_58\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~0_combout\);

-- Location: LC_X1_Y5_N1
\UART0|UART0|Top16\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Equal0~2\ = (!\UART0|UART0|Div16\(5) & (\UART0|UART0|Div16\(4) & (\UART0|UART0|Equal0~1\ & \UART0|UART0|Equal0~0\)))
-- \UART0|UART0|Top16~regout\ = DFFEAS(\UART0|UART0|Equal0~2\, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "4000",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|Div16\(5),
	datab => \UART0|UART0|Div16\(4),
	datac => \UART0|UART0|Equal0~1\,
	datad => \UART0|UART0|Equal0~0\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Equal0~2\,
	regout => \UART0|UART0|Top16~regout\);

-- Location: LC_X2_Y5_N4
\UART0|UART0|Add0~10\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add0~10_combout\ = \UART0|UART0|Div16\(4) $ ((((!\UART0|UART0|Add0~17\))))
-- \UART0|UART0|Add0~12\ = CARRY((\UART0|UART0|Div16\(4) & ((!\UART0|UART0|Add0~17COUT1_54\))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "a50a",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|Div16\(4),
	cin0 => \UART0|UART0|Add0~17\,
	cin1 => \UART0|UART0|Add0~17COUT1_54\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add0~10_combout\,
	cout => \UART0|UART0|Add0~12\);

-- Location: LC_X1_Y5_N9
\UART0|UART0|Div16[4]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(4) = DFFEAS(((!\UART0|UART0|Equal0~2\ & ((\UART0|UART0|Add0~10_combout\)))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "3300",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datab => \UART0|UART0|Equal0~2\,
	datad => \UART0|UART0|Add0~10_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(4));

-- Location: LC_X2_Y5_N8
\UART0|UART0|Div16[5]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Div16\(5) = DFFEAS(GND, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , \UART0|UART0|Add0~35_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add0~35_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|Div16\(5));

-- Location: LC_X1_Y4_N5
\UART0|UART0|Add1~0\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add1~0_combout\ = ((!\UART0|UART0|ClkDiv\(0)))
-- \UART0|UART0|Add1~2\ = CARRY(((\UART0|UART0|ClkDiv\(0))))
-- \UART0|UART0|Add1~2COUT1_31\ = CARRY(((\UART0|UART0|ClkDiv\(0))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "33cc",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|ClkDiv\(0),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add1~0_combout\,
	cout0 => \UART0|UART0|Add1~2\,
	cout1 => \UART0|UART0|Add1~2COUT1_31\);

-- Location: LC_X1_Y4_N0
\UART0|UART0|ClkDiv[0]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|ClkDiv\(0) = DFFEAS(GND, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|Top16~regout\, \UART0|UART0|Add1~0_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add1~0_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	ena => \UART0|UART0|Top16~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|ClkDiv\(0));

-- Location: LC_X1_Y4_N6
\UART0|UART0|Add1~15\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add1~15_combout\ = \UART0|UART0|ClkDiv\(1) $ ((((\UART0|UART0|Add1~2\))))
-- \UART0|UART0|Add1~17\ = CARRY(((!\UART0|UART0|Add1~2\)) # (!\UART0|UART0|ClkDiv\(1)))
-- \UART0|UART0|Add1~17COUT1_33\ = CARRY(((!\UART0|UART0|Add1~2COUT1_31\)) # (!\UART0|UART0|ClkDiv\(1)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "5a5f",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|ClkDiv\(1),
	cin0 => \UART0|UART0|Add1~2\,
	cin1 => \UART0|UART0|Add1~2COUT1_31\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add1~15_combout\,
	cout0 => \UART0|UART0|Add1~17\,
	cout1 => \UART0|UART0|Add1~17COUT1_33\);

-- Location: LC_X1_Y4_N4
\UART0|UART0|ClkDiv[1]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|ClkDiv\(1) = DFFEAS(GND, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|Top16~regout\, \UART0|UART0|Add1~15_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add1~15_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	ena => \UART0|UART0|Top16~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|ClkDiv\(1));

-- Location: LC_X1_Y4_N7
\UART0|UART0|Add1~10\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add1~10_combout\ = (\UART0|UART0|ClkDiv\(2) $ ((!\UART0|UART0|Add1~17\)))
-- \UART0|UART0|Add1~12\ = CARRY(((\UART0|UART0|ClkDiv\(2) & !\UART0|UART0|Add1~17\)))
-- \UART0|UART0|Add1~12COUT1_35\ = CARRY(((\UART0|UART0|ClkDiv\(2) & !\UART0|UART0|Add1~17COUT1_33\)))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "c30c",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|ClkDiv\(2),
	cin0 => \UART0|UART0|Add1~17\,
	cin1 => \UART0|UART0|Add1~17COUT1_33\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add1~10_combout\,
	cout0 => \UART0|UART0|Add1~12\,
	cout1 => \UART0|UART0|Add1~12COUT1_35\);

-- Location: LC_X1_Y4_N1
\UART0|UART0|ClkDiv[2]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|ClkDiv\(2) = DFFEAS(GND, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|Top16~regout\, \UART0|UART0|Add1~10_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0000",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|Add1~10_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	ena => \UART0|UART0|Top16~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|ClkDiv\(2));

-- Location: LC_X1_Y4_N8
\UART0|UART0|Add1~5\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add1~5_combout\ = (\UART0|UART0|ClkDiv\(3) $ ((\UART0|UART0|Add1~12\)))
-- \UART0|UART0|Add1~7\ = CARRY(((!\UART0|UART0|Add1~12\) # (!\UART0|UART0|ClkDiv\(3))))
-- \UART0|UART0|Add1~7COUT1_37\ = CARRY(((!\UART0|UART0|Add1~12COUT1_35\) # (!\UART0|UART0|ClkDiv\(3))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "3c3f",
	operation_mode => "arithmetic",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datab => \UART0|UART0|ClkDiv\(3),
	cin0 => \UART0|UART0|Add1~12\,
	cin1 => \UART0|UART0|Add1~12COUT1_35\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add1~5_combout\,
	cout0 => \UART0|UART0|Add1~7\,
	cout1 => \UART0|UART0|Add1~7COUT1_37\);

-- Location: LC_X1_Y4_N9
\UART0|UART0|Add1~20\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add1~20_combout\ = ((\UART0|UART0|Add1~7\ $ (!\UART0|UART0|ClkDiv\(4))))

-- pragma translate_off
GENERIC MAP (
	cin0_used => "true",
	cin1_used => "true",
	lut_mask => "f00f",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "cin",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datad => \UART0|UART0|ClkDiv\(4),
	cin0 => \UART0|UART0|Add1~7\,
	cin1 => \UART0|UART0|Add1~7COUT1_37\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add1~20_combout\);

-- Location: LC_X1_Y4_N3
\UART0|UART0|ClkDiv[4]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|ClkDiv\(4) = DFFEAS(((\UART0|UART0|Add1~20_combout\ & ((!\UART0|UART0|Equal1~0\) # (!\UART0|UART0|ClkDiv\(0))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|Top16~regout\, , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0ccc",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datab => \UART0|UART0|Add1~20_combout\,
	datac => \UART0|UART0|ClkDiv\(0),
	datad => \UART0|UART0|Equal1~0\,
	aclr => \ALT_INV_rst_n~combout\,
	ena => \UART0|UART0|Top16~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|ClkDiv\(4));

-- Location: LC_X1_Y4_N2
\UART0|UART0|ClkDiv[3]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Equal1~0\ = (\UART0|UART0|ClkDiv\(1) & (\UART0|UART0|ClkDiv\(2) & (N1_ClkDiv[3] & !\UART0|UART0|ClkDiv\(4))))
-- \UART0|UART0|ClkDiv\(3) = DFFEAS(\UART0|UART0|Equal1~0\, GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|Top16~regout\, \UART0|UART0|Add1~5_combout\, , , VCC)

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0080",
	operation_mode => "normal",
	output_mode => "reg_and_comb",
	register_cascade_mode => "off",
	sum_lutc_input => "qfbk",
	synch_mode => "on")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|ClkDiv\(1),
	datab => \UART0|UART0|ClkDiv\(2),
	datac => \UART0|UART0|Add1~5_combout\,
	datad => \UART0|UART0|ClkDiv\(4),
	aclr => \ALT_INV_rst_n~combout\,
	sload => VCC,
	ena => \UART0|UART0|Top16~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Equal1~0\,
	regout => \UART0|UART0|ClkDiv\(3));

-- Location: LC_X1_Y6_N3
\UART0|UART0|TopTx\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TopTx~regout\ = DFFEAS((\UART0|UART0|Top16~regout\ & (\UART0|UART0|ClkDiv\(0) & (\UART0|UART0|Equal1~0\))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "8080",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|Top16~regout\,
	datab => \UART0|UART0|ClkDiv\(0),
	datac => \UART0|UART0|Equal1~0\,
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TopTx~regout\);

-- Location: LC_X1_Y6_N4
\UART0|UART0|TxReg[0]~1\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxReg[0]~1_combout\ = (\UART0|UART0|TopTx~regout\ & (\UART0|UART0|TxFSM\(1) $ (((\UART0|UART0|TxFSM\(0))))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "2288",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|TopTx~regout\,
	datab => \UART0|UART0|TxFSM\(1),
	datad => \UART0|UART0|TxFSM\(0),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|TxReg[0]~1_combout\);

-- Location: LC_X1_Y6_N0
\UART0|UART0|TxBitCnt[0]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxBitCnt\(0) = DFFEAS((((!\UART0|UART0|TxFSM\(1)) # (!\UART0|UART0|TxBitCnt\(0)))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|TxReg[0]~1_combout\, , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0fff",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datac => \UART0|UART0|TxBitCnt\(0),
	datad => \UART0|UART0|TxFSM\(1),
	aclr => \ALT_INV_rst_n~combout\,
	ena => \UART0|UART0|TxReg[0]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxBitCnt\(0));

-- Location: LC_X1_Y6_N8
\UART0|UART0|TxBitCnt[1]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxBitCnt\(1) = DFFEAS(((\UART0|UART0|TxFSM\(1) & (\UART0|UART0|TxBitCnt\(0) $ (!\UART0|UART0|TxBitCnt\(1))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|TxReg[0]~1_combout\, , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "c00c",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datab => \UART0|UART0|TxFSM\(1),
	datac => \UART0|UART0|TxBitCnt\(0),
	datad => \UART0|UART0|TxBitCnt\(1),
	aclr => \ALT_INV_rst_n~combout\,
	ena => \UART0|UART0|TxReg[0]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxBitCnt\(1));

-- Location: LC_X1_Y6_N7
\UART0|UART0|TxBitCnt[2]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxBitCnt\(2) = DFFEAS((\UART0|UART0|TxFSM\(1) & (\UART0|UART0|TxBitCnt\(2) $ (((!\UART0|UART0|TxBitCnt\(1) & !\UART0|UART0|TxBitCnt\(0)))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|TxReg[0]~1_combout\, , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "e100",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|TxBitCnt\(1),
	datab => \UART0|UART0|TxBitCnt\(0),
	datac => \UART0|UART0|TxBitCnt\(2),
	datad => \UART0|UART0|TxFSM\(1),
	aclr => \ALT_INV_rst_n~combout\,
	ena => \UART0|UART0|TxReg[0]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxBitCnt\(2));

-- Location: LC_X1_Y6_N5
\UART0|UART0|Add3~0\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Add3~0_combout\ = (((\UART0|UART0|TxBitCnt\(0)) # (\UART0|UART0|TxBitCnt\(1))))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "fff0",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	datac => \UART0|UART0|TxBitCnt\(0),
	datad => \UART0|UART0|TxBitCnt\(1),
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Add3~0_combout\);

-- Location: LC_X1_Y6_N6
\UART0|UART0|TxBitCnt[3]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxBitCnt\(3) = DFFEAS((\UART0|UART0|TxBitCnt\(3) $ (((!\UART0|UART0|TxBitCnt\(2) & !\UART0|UART0|Add3~0_combout\)))) # (!\UART0|UART0|TxFSM\(1)), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , \UART0|UART0|TxReg[0]~1_combout\, , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "bbb7",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|TxBitCnt\(3),
	datab => \UART0|UART0|TxFSM\(1),
	datac => \UART0|UART0|TxBitCnt\(2),
	datad => \UART0|UART0|Add3~0_combout\,
	aclr => \ALT_INV_rst_n~combout\,
	ena => \UART0|UART0|TxReg[0]~1_combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxBitCnt\(3));

-- Location: LC_X1_Y6_N9
\UART0|UART0|Mux10~0\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|Mux10~0_combout\ = (!\UART0|UART0|TxBitCnt\(1) & (!\UART0|UART0|TxBitCnt\(2) & (!\UART0|UART0|TxBitCnt\(3) & \UART0|UART0|TopTx~regout\)))

-- pragma translate_off
GENERIC MAP (
	lut_mask => "0100",
	operation_mode => "normal",
	output_mode => "comb_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	dataa => \UART0|UART0|TxBitCnt\(1),
	datab => \UART0|UART0|TxBitCnt\(2),
	datac => \UART0|UART0|TxBitCnt\(3),
	datad => \UART0|UART0|TopTx~regout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	combout => \UART0|UART0|Mux10~0_combout\);

-- Location: LC_X1_Y6_N2
\UART0|UART0|TxFSM[0]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxFSM\(0) = DFFEAS((\UART0|UART0|TxFSM\(0) & (!\UART0|UART0|TopTx~regout\)) # (!\UART0|UART0|TxFSM\(0) & (((\UART0|UART0|Mux10~0_combout\ & \UART0|UART0|TxBitCnt\(0))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "55c0",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|TopTx~regout\,
	datab => \UART0|UART0|Mux10~0_combout\,
	datac => \UART0|UART0|TxBitCnt\(0),
	datad => \UART0|UART0|TxFSM\(0),
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxFSM\(0));

-- Location: LC_X1_Y5_N8
\UART0|UART0|TxFSM[1]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxFSM\(1) = DFFEAS((\UART0|UART0|TxFSM\(1) $ (((\UART0|UART0|TopTx~regout\ & \UART0|UART0|TxFSM\(0))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "3ccc",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	datab => \UART0|UART0|TxFSM\(1),
	datac => \UART0|UART0|TopTx~regout\,
	datad => \UART0|UART0|TxFSM\(0),
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxFSM\(1));

-- Location: LC_X1_Y6_N1
\UART0|UART0|TxReg[0]\ : maxv_lcell
-- Equation(s):
-- \UART0|UART0|TxReg\(0) = DFFEAS((\UART0|UART0|TopTx~regout\ & ((\UART0|UART0|TxFSM\(1) & (\UART0|UART0|TxReg\(0) & \UART0|UART0|TxFSM\(0))) # (!\UART0|UART0|TxFSM\(1) & ((\UART0|UART0|TxReg\(0)) # (\UART0|UART0|TxFSM\(0)))))) # 
-- (!\UART0|UART0|TopTx~regout\ & (((\UART0|UART0|TxReg\(0))))), GLOBAL(\clk50~combout\), GLOBAL(\rst_n~combout\), , , , , , )

-- pragma translate_off
GENERIC MAP (
	lut_mask => "f270",
	operation_mode => "normal",
	output_mode => "reg_only",
	register_cascade_mode => "off",
	sum_lutc_input => "datac",
	synch_mode => "off")
-- pragma translate_on
PORT MAP (
	clk => \clk50~combout\,
	dataa => \UART0|UART0|TopTx~regout\,
	datab => \UART0|UART0|TxFSM\(1),
	datac => \UART0|UART0|TxReg\(0),
	datad => \UART0|UART0|TxFSM\(0),
	aclr => \ALT_INV_rst_n~combout\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	regout => \UART0|UART0|TxReg\(0));

-- Location: PIN_118,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\clk0_001~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_clk0_001);

-- Location: PIN_12,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\lock~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_lock);

-- Location: PIN_32,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(0));

-- Location: PIN_31,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(1));

-- Location: PIN_30,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(2));

-- Location: PIN_29,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(3));

-- Location: PIN_28,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(4));

-- Location: PIN_27,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(5));

-- Location: PIN_6,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[6]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(6));

-- Location: PIN_39,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\status[7]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_status(7));

-- Location: PIN_66,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\scl_host~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_scl_host);

-- Location: PIN_8,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\scl_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_scl_slave);

-- Location: PIN_72,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\miso_host~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_miso_host);

-- Location: PIN_84,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\mosi_host~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_mosi_host);

-- Location: PIN_91,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\sclk_host~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_sclk_host);

-- Location: PIN_137,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(0));

-- Location: PIN_104,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(1));

-- Location: PIN_123,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(2));

-- Location: PIN_139,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(3));

-- Location: PIN_1,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(4));

-- Location: PIN_49,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(5));

-- Location: PIN_74,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[6]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(6));

-- Location: PIN_71,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ss_n_host[7]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ss_n_host(7));

-- Location: PIN_3,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\miso_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_miso_slave);

-- Location: PIN_4,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\mosi_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_mosi_slave);

-- Location: PIN_80,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\sclk_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_sclk_slave);

-- Location: PIN_108,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ss_n_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ss_n_slave);

-- Location: PIN_24,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\uart_rx~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_uart_rx);

-- Location: PIN_23,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\uart_tx~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => \UART0|UART0|ALT_INV_TxReg\(0),
	oe => VCC,
	padio => ww_uart_tx);

-- Location: PIN_45,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[9][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(9)(0));

-- Location: PIN_53,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[9][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(9)(1));

-- Location: PIN_15,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[9][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(9)(2));

-- Location: PIN_103,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[8][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(8)(0));

-- Location: PIN_73,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[8][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(8)(1));

-- Location: PIN_16,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[8][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(8)(2));

-- Location: PIN_37,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[7][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(7)(0));

-- Location: PIN_110,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[7][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(7)(1));

-- Location: PIN_96,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[7][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(7)(2));

-- Location: PIN_105,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[6][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(6)(0));

-- Location: PIN_75,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[6][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(6)(1));

-- Location: PIN_57,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[6][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(6)(2));

-- Location: PIN_89,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[5][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(5)(0));

-- Location: PIN_88,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[5][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(5)(1));

-- Location: PIN_114,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[5][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(5)(2));

-- Location: PIN_48,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[4][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(4)(0));

-- Location: PIN_144,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[4][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(4)(1));

-- Location: PIN_52,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[4][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(4)(2));

-- Location: PIN_40,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[3][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(3)(0));

-- Location: PIN_63,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[3][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(3)(1));

-- Location: PIN_106,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[3][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(3)(2));

-- Location: PIN_69,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[2][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(2)(0));

-- Location: PIN_94,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[2][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(2)(1));

-- Location: PIN_143,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[2][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(2)(2));

-- Location: PIN_140,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[1][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(1)(0));

-- Location: PIN_13,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[1][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(1)(1));

-- Location: PIN_112,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[1][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(1)(2));

-- Location: PIN_127,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[0][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(0)(0));

-- Location: PIN_107,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[0][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => ww_motors(0)(1));

-- Location: PIN_119,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\motors[0][2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_motors(0)(2));

-- Location: PIN_120,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[9][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(9)(0));

-- Location: PIN_138,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[9][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(9)(1));

-- Location: PIN_85,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[8][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(8)(0));

-- Location: PIN_142,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[8][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(8)(1));

-- Location: PIN_125,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[7][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(7)(0));

-- Location: PIN_122,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[7][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(7)(1));

-- Location: PIN_124,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[6][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(6)(0));

-- Location: PIN_14,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[6][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(6)(1));

-- Location: PIN_129,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[5][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(5)(0));

-- Location: PIN_51,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[5][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(5)(1));

-- Location: PIN_5,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[4][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(4)(0));

-- Location: PIN_97,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[4][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(4)(1));

-- Location: PIN_134,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[3][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(3)(0));

-- Location: PIN_22,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[3][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(3)(1));

-- Location: PIN_111,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[2][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(2)(0));

-- Location: PIN_95,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[2][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(2)(1));

-- Location: PIN_81,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[1][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(1)(0));

-- Location: PIN_121,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[1][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(1)(1));

-- Location: PIN_38,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[0][0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(0)(0));

-- Location: PIN_109,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\encoders[0][1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_encoders(0)(1));

-- Location: PIN_133,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(0));

-- Location: PIN_86,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(1));

-- Location: PIN_98,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(2));

-- Location: PIN_50,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(3));

-- Location: PIN_41,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(4));

-- Location: PIN_101,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(5));

-- Location: PIN_42,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[6]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(6));

-- Location: PIN_93,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\ultrsnic_trig[7]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "output")
-- pragma translate_on
PORT MAP (
	datain => GND,
	oe => VCC,
	padio => ww_ultrsnic_trig(7));

-- Location: PIN_62,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[0]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(0));

-- Location: PIN_61,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[1]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(1));

-- Location: PIN_87,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[2]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(2));

-- Location: PIN_2,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[3]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(3));

-- Location: PIN_76,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[4]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(4));

-- Location: PIN_77,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[5]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(5));

-- Location: PIN_21,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[6]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(6));

-- Location: PIN_79,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: Default
\ultrsnic_echo[7]~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	operation_mode => "input")
-- pragma translate_on
PORT MAP (
	oe => GND,
	padio => ww_ultrsnic_echo(7));

-- Location: PIN_67,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\sda_host~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	open_drain_output => "true",
	operation_mode => "bidir")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => sda_host);

-- Location: PIN_7,	 I/O Standard: 3.3-V LVTTL,	 Current Strength: 16mA
\sda_slave~I\ : maxv_io
-- pragma translate_off
GENERIC MAP (
	open_drain_output => "true",
	operation_mode => "bidir")
-- pragma translate_on
PORT MAP (
	datain => VCC,
	oe => VCC,
	padio => sda_slave);
END structure;


