-- http://esd.cs.ucr.edu/labs/uart/uart.html
-- http://www.inventus.org/posterous/file/2009/03/192538-alse_uart_us.pdf
-- http://www.asic-world.com/examples/vhdl/uart.html
-- https://github.com/pabennett/uart

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity UART is
generic (
     baud_rate : integer range 9600 to 115200
    );
port(
	  clk             : in  std_ulogic;
	  clk_comm        : in  std_ulogic;
	  error           : out integer range 0 to 3;
	  
	  rx              : in  std_ulogic;
	  tx              : out std_ulogic;
	  
	  motor_directive : in  int8_vector10;
	  encoder_velocity: in  int8_vector10;
	  current_sense   : in  uint8_vector10;
	  pot_angles      : in  int8_vector8;
     ultrasonic_dist : in  uint8_vector10
	 );
end entity UART;

architecture behavioral of UART is
begin

end behavioral;