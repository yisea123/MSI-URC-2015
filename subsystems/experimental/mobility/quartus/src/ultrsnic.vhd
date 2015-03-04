LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY ultrasonic_sensor IS
GENERIC (
     ENA   :     STD_LOGIC := '0'
    );
PORT(
	  clk50 : IN  STD_LOGIC;
	  clk0_1: IN  STD_LOGIC;
	  rst   : IN  STD_LOGIC;
	  err   : OUT STD_LOGIC;
	  
     trig  : OUT STD_LOGIC;
     echo  : IN  STD_LOGIC;

	  dist  : OUT INTEGER RANGE 0 TO 255
    );
END ENTITY;

ARCHITECTURE main OF ultrasonic_sensor IS
BEGIN

END ARCHITECTURE;