LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY motor_driver IS
  PORT(
      clk0_1  : IN  STD_LOGIC                 := '1';
		rst     : IN  STD_LOGIC                 := '0';
		
		err_in  : IN  STD_LOGIC                 := '0';
		err_out : OUT INTEGER RANGE 0 TO 3      :=  0 ;
		
		lock    : IN  STD_LOGIC                 := '1';
		free    : IN  STD_LOGIC                 := '0';
		data    : IN  INTEGER RANGE -100 TO 100 :=  0 ;
		
		ena     : OUT STD_LOGIC                 := '1';
		pwm     : OUT STD_LOGIC                 := '0';
		dir     : OUT STD_LOGIC                 := '1'
      );
END ENTITY;

ARCHITECTURE main OF motor_driver IS
BEGIN
  PROCESS (clk0_1, rst, err_in)
  VARIABLE count : INTEGER RANGE 0 TO 100 :=  0 ;
  VARIABLE t_pwm : INTEGER RANGE 0 TO 100 :=  0 ;
  BEGIN
    IF rst = '0' THEN
	   pwm       <= '0';
      count     :=  0 ;
		t_pwm     :=  0 ;
		dir       <= '1';
		ena       <= '1';
	 ELSIF RISING_EDGE(clk0_1) THEN
	   ena       <= '1';
	   IF err_in  = '1' THEN
		  err_out <=  1 ;
		  count   :=  0 ;
  		  t_pwm   :=  0 ;
		  dir     <= '1';
	     pwm     <= '0';
	   ELSIF count > 100 THEN
		  err_out <=  2 ;
		  count   :=  0 ;
  		  t_pwm   :=  0 ;
		  dir     <= '1';
	     pwm     <= '0';
		ELSIF t_pwm > 100 THEN
		  err_out <=  3 ;
		  count   :=  0 ;
  		  t_pwm   :=  0 ;
		  dir     <= '1';
	     pwm     <= '0';
		ELSIF lock <= '1' THEN
		  t_pwm   :=  0 ;
		ELSIF free <= '1' THEN
		  ena     <= '0';
		ELSE
		  err_out <=  0 ;
        IF count = 100 THEN
	       count :=  0 ;
			 IF data >= 0 THEN
  		      t_pwm :=  data;
				dir   <= '1';
			 ELSE
			   t_pwm := -data;
				dir   <= '0';
			 END IF;
        ELSIF count <= t_pwm THEN
	       count := count + 1;
 		    pwm   <= '1';
        ELSIF count > t_pwm THEN
	       count := count + 1;
			 pwm   <= '0';
	     ELSE
	       pwm   <= '0';
	       count :=  0 ;
        END IF;
		END IF;
    END IF;
  END PROCESS;
END ARCHITECTURE;