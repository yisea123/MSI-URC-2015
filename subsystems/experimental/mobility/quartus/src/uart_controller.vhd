LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY uart_controller IS
  GENERIC(
      baud_rate : INTEGER RANGE 9600 TO 115200
      );
  PORT(
	   clk50            : IN  STD_LOGIC;
	   rst              : IN  STD_LOGIC;
	   err              : OUT INTEGER RANGE 0 TO 3;
	  
	   rx               : IN  STD_LOGIC;
	   tx               : OUT STD_LOGIC;
	  
	   motor_directive  : IN  int9_vector10;
	   encoder_velocity : IN  int16_vector10;
	   current_sense    : IN  uint8_vector10;
	   pot_angles       : IN  uint16_vector8;
      ultrsnic_map     : IN  uint8_vector8
	   );
END ENTITY;

ARCHITECTURE main OF uart_controller IS
SIGNAL rx_data : STD_LOGIC_VECTOR(7 downto 0);
SIGNAL rx_en   : STD_LOGIC;
SIGNAL tx_data : STD_LOGIC_VECTOR(7 downto 0);
SIGNAL tx_en   : STD_LOGIC;
SIGNAL tx_busy : STD_LOGIC;
SIGNAL rx_err  : STD_LOGIC;
BEGIN
UART0 : ENTITY work.uart
  GENERIC MAP(
      DIVISOR => 26            -- DIVISOR = {CLK_FREQ / (16 x BAUD_RATE)} - 1
      )
  PORT MAP(
      clk    => clk50,
      rst    => rst,
      RxData => rx_data,
      RxEn   => rx_en,
      TxData => tx_data,
      TxEn   => tx_en,
      TxBusy => tx_busy,
      RxErr  => rx_err,
      rx     => rx,
      tx     => tx
      );
END ARCHITECTURE;