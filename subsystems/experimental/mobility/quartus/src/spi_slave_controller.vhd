LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY spi_slave_controller IS
  port(
	   clk50           : IN  STD_LOGIC;
		clk0_001        : IN  STD_LOGIC;
	   rst             : IN  STD_LOGIC;
	   err             : OUT INTEGER RANGE 0 TO 3;
	  
	   miso            : OUT STD_LOGIC;
	   mosi            : IN  STD_LOGIC;
	   sclk            : IN  STD_LOGIC;
	   ss_n            : IN  STD_LOGIC;
	  
	   motor_directive : OUT int8_vector10;
	   encoder_velocity: IN  int16_vector10;
	   current_sense   : IN  uint8_vector10;
	   pot_angles      : IN  uint16_vector8;
      ultrsnic_map    : IN  uint8_vector8;
		status          : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
		enc_velocity_rst: OUT STD_LOGIC
	   );
END ENTITY;

ARCHITECTURE main OF spi_slave_controller IS
BEGIN

END ARCHITECTURE;