library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity Status_Poll is
port(
	  status      : out std_ulogic_vector(7 downto 0);
     error_uart  : integer range 0 to 3;
     error_i2ch  : integer range 0 to 3;
     error_i2cs  : integer range 0 to 3;
     error_spih  : integer range 0 to 3;
     error_spis  : integer range 0 to 3;
     error_motd  : integer range 0 to 3;
     error_ench  : integer range 0 to 3;
     error_ultr  : integer range 0 to 3
	 );
end entity Status_Poll;

architecture behavioral of Status_Poll is
begin

end behavioral;