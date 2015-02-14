library ieee;
use ieee.std_logic_1164.all;

package mobility_types_pkg is
	  type int8_vector10 is array(0 to 9) of integer range -127 to 127;
	  type uint8_vector10 is array(0 to 9) of integer range 0 to 255;
	  type int8_vector8  is array(0 to 7) of integer range -127 to 127;
end package mobility_types_pkg;