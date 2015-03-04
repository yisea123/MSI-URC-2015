-- https://www.eewiki.net/display/LOGIC/Serial+Peripheral+Interface+%28SPI%29+Slave+%28VHDL%29

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity SPI_Slave is
port(
	  clk             : in  std_ulogic;
	  clk_comm        : in  std_ulogic;
	  error           : out integer range 0 to 3;
	  
	  miso            : out std_ulogic;
	  mosi            : in  std_ulogic;
	  sck             : in  std_ulogic;
	  ss              : in  std_ulogic;
	  
	  motor_directive : out int8_vector10;
	  encoder_velocity: in  int8_vector10;
	  current_sense   : in  uint8_vector10;
	  pot_angles      : in  int8_vector8;
     ultrasonic_dist : in  uint8_vector10
	 );
end entity SPI_Slave;

architecture behavioral of SPI_Slave is
begin

end behavioral;