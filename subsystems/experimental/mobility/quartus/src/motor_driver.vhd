LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY motor_driver IS
  PORT(
      clk     : IN  STD_LOGIC                    := '1';
		rst     : IN  STD_LOGIC                    := '0';
		
		err_in  : IN  STD_LOGIC                    := '0';
		
		lock    : IN  STD_LOGIC                    := '1';
		data    : IN  INTEGER RANGE -100 TO 100    :=  0 ;
		
      motor   : OUT STD_LOGIC_VECTOR(2 DOWNTO 0) := "011"
      );
END ENTITY;

ARCHITECTURE main OF motor_driver IS
BEGIN
  PROCESS (clk, rst, err_in)
  VARIABLE count : INTEGER RANGE 0 TO 100 :=  0 ;
  VARIABLE t_pwm : INTEGER RANGE 0 TO 100 :=  0 ;
  BEGIN
    IF rst = '1' THEN
      count    :=  0 ;
		t_pwm    :=  0 ;
	   motor(2) <= '0';
		motor(1) <= '1';
		motor(0) <= '1';
	 ELSIF RISING_EDGE(clk) THEN
	   motor(0) <= '1';
	   IF err_in  = '1' THEN
		  count    :=  0 ;
  		  t_pwm    :=  0 ;
		  motor(1) <= '1';
	     motor(2) <= '0';
		ELSIF lock <= '1' THEN
		  t_pwm    :=  0 ;
		ELSE
        IF count = 100 THEN
	       count    :=  0 ;
			 IF data >= 0 THEN
  		      t_pwm    :=  data;
   		   motor(1) <= '1';
			 ELSE
			   t_pwm    := -data;
		      motor(1) <= '0';
			 END IF;
        ELSIF count <= t_pwm THEN
	       count    := count + 1;
  	       motor(2) <= '1';
        ELSIF count > t_pwm THEN
	       count    := count + 1;
  	       motor(2) <= '0';
	     ELSE
  	       motor(2) <= '0';
	       count    :=  0 ;
        END IF;
		END IF;
    END IF;
  END PROCESS;
END ARCHITECTURE;