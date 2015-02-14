-- https://www.eewiki.net/display/LOGIC/I2C+Master+%28VHDL%29

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity I2C_Host is
port(
	  clk             : in  std_ulogic;
	  clk_comm        : in  std_ulogic;
	  error           : out integer range 0 to 3;
	  
	  scl             : out   std_ulogic;
	  sda             : inout std_ulogic
	 );
end entity I2C_Host;

architecture behavioral of I2C_Host is
begin

end behavioral;