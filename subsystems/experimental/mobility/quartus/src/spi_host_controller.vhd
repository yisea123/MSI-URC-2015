LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY spi_host_controller IS
  PORT(
	   clk50         : IN  STD_LOGIC;
	   clk5          : IN  STD_LOGIC;
		rst           : IN  STD_LOGIC;
	   err           : OUT INTEGER RANGE 0 TO 3;
	  
	   miso          : IN  STD_LOGIC;
	   mosi          : OUT STD_LOGIC;
	   sclk          : OUT STD_LOGIC;
	   ss_n          : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
		
	   current_sense : OUT uint8_vector10;
      pot_angles    : OUT uint16_vector8
	   );
END ENTITY;

ARCHITECTURE main OF spi_host_controller IS
BEGIN

END ARCHITECTURE;