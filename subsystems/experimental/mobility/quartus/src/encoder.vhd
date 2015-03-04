LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY encoder IS
  PORT(
	   clk50    : IN  STD_LOGIC;
		rst      : IN  STD_LOGIC;
	   clr      : IN  STD_LOGIC;
		
	   encoder  : IN  STD_LOGIC_VECTOR(1 DOWNTO 0);
	   velocity : OUT INTEGER RANGE -3277 TO 3277
      );
END ENTITY;

ARCHITECTURE main OF encoder IS
BEGIN

END ARCHITECTURE;