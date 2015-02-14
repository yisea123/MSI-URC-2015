library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity Motor_Driver is
port(
	  clk       : in  std_ulogic;
	  error_out : out integer range 0 to 3;
	  error_in  : in  integer range 0 to 3;
	  lock      : in  std_ulogic;
	  
	  en        : out std_ulogic_vector(9 downto 0);
	  pwm_f     : out std_ulogic_vector(9 downto 0);
	  pwm_r     : out std_ulogic_vector(9 downto 0);

	  directive : in int8_vector10
    );
end entity Motor_Driver;

architecture behavioral of Motor_Driver is
begin

end behavioral;