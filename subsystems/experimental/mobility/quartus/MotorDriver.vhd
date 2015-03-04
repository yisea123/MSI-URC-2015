LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY motor_controller IS
PORT(
	  clk50     : IN  STD_LOGIC;
	  clk0_1    : IN  STD_LOGIC;
	  rst       : IN  STD_LOGIC;
	  err_out   : OUT INTEGER RANGE 0 TO 3;
	  err_in    : IN  STD_LOGIC;
	  lock      : IN  STD_LOGIC;
	  free      : IN  STD_LOGIC;
	  
	  ena       : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);
	  pwm       : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);
	  dir       : OUT STD_LOGIC_VECTOR(9 DOWNTO 0);

	  directive : IN int8_vector10
    );
END ENTITY;

ARCHITECTURE main OF motor_controller IS
SIGNAL t_err_out : uint2_vector10;
BEGIN
PWM_F_0 : ENTITY work.motor_driver
  PORT MAP(
      clk0_1  => clk0_1,
		rst     => rst,
		err_in  => err_in,
		err_out => t_err_out(0),
		data    => directive(0),
		lock    => lock,
		free    => free,
		ena      => ena(0),
		pwm     => pwm(0),
		dir     => dir(0)
      );
END main;