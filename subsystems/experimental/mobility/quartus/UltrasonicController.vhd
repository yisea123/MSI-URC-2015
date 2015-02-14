-- http://www.micropik.com/PDF/HCSR04.pdf

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity Ultrasonic_Controller is
generic (
     number_of_sensors: integer range 0 to 8 := 0
    );
port(
	  clk   : in  std_ulogic;
	  error : out integer range 0 to 3;
	  
     trig  : out std_ulogic_vector(7 downto 0);
     echo  : in  std_ulogic_vector(7 downto 0);

	  dist  : out uint8_vector10
    );
end entity Ultrasonic_Controller;

architecture behavioral of Ultrasonic_Controller is
begin

end behavioral;