LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY monitor IS
PORT(
     rst         : IN  STD_LOGIC;
	  status      : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
     err_uart    : IN  INTEGER RANGE 0 TO 3;
     err_i2c_h   : IN  INTEGER RANGE 0 TO 3;
     err_i2c_s   : IN  INTEGER RANGE 0 TO 3;
     err_spi_h   : IN  INTEGER RANGE 0 TO 3;
     err_spi_s   : IN  INTEGER RANGE 0 TO 3;
     err_ultr    : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
	  err_safety  : OUT STD_LOGIC;
	  pot_angles       : uint16_vector8;
	  current_sense    : uint8_vector10;
	  encoder_velocity : int16_vector10;
	  ultrsnic_map     : uint8_vector8
	 );
END ENTITY;

ARCHITECTURE mina OF monitor IS
BEGIN

END ARCHITECTURE;