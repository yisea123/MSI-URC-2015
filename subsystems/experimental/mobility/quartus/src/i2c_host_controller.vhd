LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY i2c_host_controller IS
  PORT(
	   clk50  : IN  STD_LOGIC;
	   clk0_1 : IN  STD_LOGIC;
		rst    : IN  STD_LOGIC;
	   err    : OUT INTEGER RANGE 0 TO 3;
	  
	   scl    : OUT   STD_LOGIC;
	   sda    : INOUT STD_LOGIC
	   );
END ENTITY;

ARCHITECTURE main OF i2c_host_controller IS
BEGIN

END ARCHITECTURE;