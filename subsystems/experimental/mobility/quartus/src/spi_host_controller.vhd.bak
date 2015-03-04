-- https://www.eewiki.net/display/LOGIC/Serial+Peripheral+Interface+%28SPI%29+Master+%28VHDL%29

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity SPI_Host is
port(
	  clk           : in  std_ulogic;
	  clk_comm      : in  std_ulogic;
	  error         : out integer range 0 to 3;
	  
	  miso          : in  std_ulogic;
	  mosi          : out std_ulogic;
	  sck           : out std_ulogic;
	  ss            : out std_ulogic_vector(7 downto 0);
	  current_sense : out uint8_vector10;
     pot_angles    : out int8_vector8
	 );
end entity SPI_Host;

architecture behavioral of SPI_Host is
begin

end behavioral;