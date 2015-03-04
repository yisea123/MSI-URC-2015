-- http://playground.arduino.cc/Main/RotaryEncoders

LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY Encoder_Handler IS
  PORT(
	   clk50    : IN  STD_LOGIC;
	   clk0_01  : IN  STD_LOGIC;
	  
	   pin_a    : IN  STD_LOGIC_VECTOR(9 downto 0);
	   pin_b    : IN  STD_LOGIC_VECTOR(9 downto 0);

	   velocity : OUT int8_vector10
      );
END ENTITY Encoder_Handler;

ARCHITECTURE main OF Encoder_Handler IS
SIGNAL rst          : STD_LOGIC;
SIGNAL pose         : int8_vector10;
SIGNAL inc_pose_a   : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL inc_pose_b   : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL dec_pose_a   : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL dec_pose_b   : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL t_inc_pose_a : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL t_inc_pose_b : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL t_dec_pose_a : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL t_dec_pose_b : STD_LOGIC_VECTOR(9 DOWNTO 0);
BEGIN
  PROCESS(clk0_01)
  BEGIN
  
  END PROCESS;
  
  PROCESS (clk50)
  BEGIN
    t_inc_pose_a <= inc_pose_a;
	 t_inc_pose_b <= inc_pose_b;
	 t_dec_pose_a <= dec_pose_a;
	 t_dec_pose_b <= dec_pose_b;
  END PROCESS;

  PROCESS (pin_a(0), rst)
  BEGIN
    IF rst = '0' THEN
      pose(0) <= 0;
    ELSIF RISING_EDGE(pin_a(0)) THEN
      IF (pin_b(0) = '1') THEN
	     inc_pose_a(0) <= NOT inc_pose_a(0);
	   ELSE
	     dec_pose_a(0) <= NOT dec_pose_a(0);
	   END IF;
    ELSIF FALLING_EDGE(pin_a(0)) THEN
      IF (pin_b(0) = '0') THEN
	     inc_pose_b(0) <= NOT inc_pose_b(0);
	   ELSE
	     dec_pose_b(0) <= NOT dec_pose_b(0);
	   END IF;
    END IF;
  END PROCESS;

  PROCESS(inc_pose_a(0), dec_pose_a(0), inc_pose_b(0), dec_pose_b(0))
  BEGIN
    IF inc_pose_a(0) /= t_inc_pose_a(0) THEN
	   pose(0) <= pose(0) + 1;
    ELSIF inc_pose_b(0) /= t_inc_pose_b(0) THEN
	   pose(0) <= pose(0) + 1;
    ELSIF dec_pose_a(0) /= t_dec_pose_a(0) THEN
	   pose(0) <= pose(0) - 1;
    ELSIF dec_pose_b(0) /= t_dec_pose_b(0) THEN
	   pose(0) <= pose(0) - 1;
	 ELSE
	   pose(0) <= pose(0);
	 END IF;
  END PROCESS;

END ARCHITECTURE;