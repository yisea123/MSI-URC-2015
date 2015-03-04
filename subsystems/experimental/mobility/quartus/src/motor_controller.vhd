LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY motor_controller IS
PORT(
	  clk50     : IN  STD_LOGIC;
	  clk0_001  : IN  STD_LOGIC;
	  rst       : IN  STD_LOGIC;
	  err_in    : IN  STD_LOGIC;
	  lock      : IN  STD_LOGIC;
	  
     motors    : OUT motors_t;
	  directive : IN  int8_vector10
    );
END ENTITY;

ARCHITECTURE main OF motor_controller IS
BEGIN
MOTOR_S_FL : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(0),
		lock     => lock,
		motor    => motors(0)
      );
MOTOR_S_RL : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(1),
		lock     => lock,
		motor    => motors(1)
      );
MOTOR_S_RR : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(2),
		lock     => lock,
		motor    => motors(2)
      );
MOTOR_S_FR : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(3),
		lock     => lock,
		motor    => motors(3)
      );

MOTOR_FL : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(4),
		lock     => lock,
		motor    => motors(4)
      );
MOTOR_ML : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(5),
		lock     => lock,
		motor    => motors(5)
      );
MOTOR_RL : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(6),
		lock     => lock,
		motor    => motors(6)
      );
MOTOR_RR : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(7),
		lock     => lock,
		motor    => motors(7)
      );
MOTOR_MR : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(8),
		lock     => lock,
		motor    => motors(8)
      );
MOTOR_FR : ENTITY work.motor_driver
  PORT MAP(
      clk      => clk0_001,
		rst      => rst,
		err_in   => err_in,
		data     => directive(9),
		lock     => lock,
		motor    => motors(9)
      );

END main;