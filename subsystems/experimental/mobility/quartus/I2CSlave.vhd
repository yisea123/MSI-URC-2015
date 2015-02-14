-- https://openlab.citytech.cuny.edu/cet4982/fpga/mar-23-mar-29-researchwork-information/vhdl-i2c-example-2/
-- https://openlab.citytech.cuny.edu/cet4982/fpga/mar-23-mar-29-researchwork-information/vhdl-i2c-example/
-- http://www.fpga4fun.com/ExternalContributions/VHDL_i2cs_rx_CPLD.zip

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity I2C_Slave is
generic (
     slave_addr      : std_ulogic_vector(6 downto 0):= "0000000"
    );
port(
	  clk             : in  std_ulogic;
	  clk_comm        : in  std_ulogic;
	  error           : out integer range 0 to 3;
	  
	  scl             : in    std_ulogic;
	  sda             : inout std_ulogic;
	  
	  motor_directive : out int8_vector10;
	  encoder_velocity: in  int8_vector10;
	  current_sense   : in  uint8_vector10;
	  pot_angles      : in  int8_vector8;
     ultrasonic_dist : in  uint8_vector10
	 );
end entity I2C_Slave;

architecture behavioral of I2C_Slave is
begin

end behavioral;