-- http://playground.arduino.cc/Main/RotaryEncoders

LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY encoder_handler IS
  PORT(
	   clk50    : IN  STD_LOGIC;
		rst      : IN  STD_LOGIC;
	   clr      : IN  STD_LOGIC;
		
	   encoders : IN  encoders_t;
	   velocity : OUT int16_vector10
      );
END ENTITY;

ARCHITECTURE main OF encoder_handler IS
-- SIGNAL rst          : STD_LOGIC;
-- SIGNAL pose         : int8_vector10;
-- SIGNAL inc_pose_a   : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL inc_pose_b   : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL dec_pose_a   : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL dec_pose_b   : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL t_inc_pose_a : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL t_inc_pose_b : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL t_dec_pose_a : STD_LOGIC_VECTOR(9 DOWNTO 0);
-- SIGNAL t_dec_pose_b : STD_LOGIC_VECTOR(9 DOWNTO 0);
BEGIN
ENC_0 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(0),
	 velocity => velocity(0)
    );

ENC_1 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(1),
	 velocity => velocity(1)
    );

ENC_2 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(2),
	 velocity => velocity(2)
    );

ENC_3 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(3),
	 velocity => velocity(3)
    );

ENC_4 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(4),
	 velocity => velocity(4)
    );

ENC_5 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(5),
	 velocity => velocity(5)
    );

ENC_6 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(6),
	 velocity => velocity(6)
    );

ENC_7 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(7),
	 velocity => velocity(7)
    );

ENC_8 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(8),
	 velocity => velocity(8)
    );

ENC_9 : ENTITY work.encoder
  PORT MAP(
    clk50    => clk50,
	 rst      => rst,
	 clr      => clr,
	 encoder  => encoders(9),
	 velocity => velocity(9)
    );

--  PROCESS(clk0_01)
--  BEGIN
--  
--  END PROCESS;
--  
--  PROCESS (clk50)
--  BEGIN
--    t_inc_pose_a <= inc_pose_a;
--	 t_inc_pose_b <= inc_pose_b;
--	 t_dec_pose_a <= dec_pose_a;
--	 t_dec_pose_b <= dec_pose_b;
--  END PROCESS;
--
--  PROCESS (pin_a(0), rst)
--  BEGIN
--    IF rst = '0' THEN
--      pose(0) <= 0;
--    ELSIF RISING_EDGE(pin_a(0)) THEN
--      IF (pin_b(0) = '1') THEN
--	     inc_pose_a(0) <= NOT inc_pose_a(0);
--	   ELSE
--	     dec_pose_a(0) <= NOT dec_pose_a(0);
--	   END IF;
--    ELSIF FALLING_EDGE(pin_a(0)) THEN
--      IF (pin_b(0) = '0') THEN
--	     inc_pose_b(0) <= NOT inc_pose_b(0);
--	   ELSE
--	     dec_pose_b(0) <= NOT dec_pose_b(0);
--	   END IF;
--    END IF;
--  END PROCESS;
--
--  PROCESS(inc_pose_a(0), dec_pose_a(0), inc_pose_b(0), dec_pose_b(0))
--  BEGIN
--    IF inc_pose_a(0) /= t_inc_pose_a(0) THEN
--	   pose(0) <= pose(0) + 1;
--    ELSIF inc_pose_b(0) /= t_inc_pose_b(0) THEN
--	   pose(0) <= pose(0) + 1;
--    ELSIF dec_pose_a(0) /= t_dec_pose_a(0) THEN
--	   pose(0) <= pose(0) - 1;
--    ELSIF dec_pose_b(0) /= t_dec_pose_b(0) THEN
--	   pose(0) <= pose(0) - 1;
--	 ELSE
--	   pose(0) <= pose(0);
--	 END IF;
--  END PROCESS;
--
END ARCHITECTURE;