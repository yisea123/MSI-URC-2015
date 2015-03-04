-- http://www.micropik.com/PDF/HCSR04.pdf
LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;
ENTITY ultrasonic_controller IS
GENERIC (
     SENSOR_0_ENA : STD_LOGIC    := '0';
	  SENSOR_1_ENA : STD_LOGIC    := '0';
	  SENSOR_2_ENA : STD_LOGIC    := '0';
	  SENSOR_3_ENA : STD_LOGIC    := '0';
	  SENSOR_4_ENA : STD_LOGIC    := '0';
	  SENSOR_5_ENA : STD_LOGIC    := '0';
	  SENSOR_6_ENA : STD_LOGIC    := '0';
	  SENSOR_7_ENA : STD_LOGIC    := '0'
    );
PORT(
	  clk50  : IN  STD_LOGIC;
	  clk0_1 : IN  STD_LOGIC;
	  rst    : IN  STD_LOGIC;
	  err    : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
	  
     trig   : OUT STD_LOGIC_VECTOR(7 DOWNTO 0);
     echo   : IN  STD_LOGIC_VECTOR(7 DOWNTO 0);
	  dist   : OUT uint8_vector8
    );
END ENTITY;
ARCHITECTURE main OF ultrasonic_controller IS
BEGIN
US_0: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_0_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(0),
	   trig  => trig(0),
	   echo  => echo(0),
	   dist  => dist(0)
      );

US_1: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_1_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(1),
	   trig  => trig(1),
	   echo  => echo(1),
	   dist  => dist(1)
      );

US_2: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_2_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(2),
	   trig  => trig(2),
	   echo  => echo(2),
	   dist  => dist(2)
      );

US_3: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_3_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(3),
	   trig  => trig(3),
	   echo  => echo(3),
	   dist  => dist(3)
      );

US_4: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_4_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(4),
	   trig  => trig(4),
	   echo  => echo(4),
	   dist  => dist(4)
      );

US_5: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_5_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(5),
	   trig  => trig(5),
	   echo  => echo(5),
	   dist  => dist(5)
      );

US_6: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_6_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(6),
	   trig  => trig(6),
	   echo  => echo(6),
	   dist  => dist(6)
      );

US_7: ENTITY work.ultrasonic_sensor
  GENERIC MAP(
      ENA => SENSOR_7_ENA
      )
  PORT MAP(
	   clk50  => clk50,
		clk0_1 => clk0_1,
		rst   => rst,
	   err   => err(7),
	   trig  => trig(7),
	   echo  => echo(7),
	   dist  => dist(7)
      );
END ARCHITECTURE;