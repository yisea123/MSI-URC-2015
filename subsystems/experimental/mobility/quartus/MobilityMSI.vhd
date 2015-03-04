LIBRARY ieee;
USE ieee.std_logic_1164.all;
LIBRARY work;
USE work.mobility_types_pkg.all;

ENTITY MobilityMSI IS
  GENERIC(
       PROTOCOL      : STD_LOGIC                           := '0'
  );
  PORT(
       clk50         : IN  STD_LOGIC                       := '1';
	    clk0_001      : IN  STD_LOGIC                       := '1';
	    rst_n         : IN  std_logic                       := '0';

	    lock          : IN  STD_LOGIC                       := '1';

	    status        : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)    := "00000000";
	  
	    scl_host      : OUT   STD_LOGIC                     := '1';
	    sda_host      : INOUT STD_LOGIC                     := '1';
	  
	    scl_slave     : IN    STD_LOGIC                     := '1';
	    sda_slave     : INOUT STD_LOGIC                     := '1';

	    miso_host     : IN  STD_LOGIC                       := '1';
	    mosi_host     : OUT STD_LOGIC                       := '1';
	    sclk_host     : OUT STD_LOGIC                       := '1';
	    ss_n_host     : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)    := "00000000";

	    miso_slave    : OUT STD_LOGIC                       := '1';
	    mosi_slave    : IN  STD_LOGIC                       := '1';
	    sclk_slave    : IN  STD_LOGIC                       := '1';
	    ss_n_slave    : IN  STD_LOGIC                       := '1';

	    uart_rx       : IN  STD_LOGIC                       := '1';
	    uart_tx       : OUT STD_LOGIC                       := '1';
	  
	    motors        : OUT motor_t                         := (OTHERS => "110");
	  
	    encoders      : IN  encoder_t                       := (OTHERS => "00");
	  
       ultrsnic_trig : OUT STD_LOGIC_VECTOR(7 DOWNTO 0)    := "00000000";
       ultrsnic_echo : IN  STD_LOGIC_VECTOR(7 DOWNTO 0)    := "00000000"
	 );
END ENTITY MobilityMSI;

ARCHITECTURE main OF MobilityMSI IS
  SIGNAL motor_directive     : int8_vector10;
  SIGNAL motor_directive_i2c : int8_vector10;
  SIGNAL motor_directive_spi : int8_vector10;
  SIGNAL encoder_velocity    : int16_vector10;
  SIGNAL current_sense       : uint8_vector10;
  SIGNAL pot_angles          : uint16_vector8;
  SIGNAL ultrsnic_map        : uint8_vector10;
  SIGNAL enc_velocity_rst    : STD_LOGIC;
  SIGNAL t_status            : STD_LOGIC_VECTOR(7 DOWNTO 0);

  SIGNAL err_uart            : INTEGER RANGE 0 to 3;
  SIGNAL err_i2c_h           : INTEGER RANGE 0 to 3;
  SIGNAL err_i2c_s           : INTEGER RANGE 0 to 3;
  SIGNAL err_spi_h           : INTEGER RANGE 0 to 3;
  SIGNAL err_spi_s           : INTEGER RANGE 0 to 3;
  SIGNAL err_mot             : INTEGER RANGE 0 to 3;
  SIGNAL err_enc             : INTEGER RANGE 0 to 3;
  SIGNAL err_ultr            : INTEGER RANGE 0 to 3;
  SIGNAL err_safety          : STD_LOGIC;
  
  SIGNAL clk0_1              : STD_LOGIC;
  SIGNAL clk5                : STD_LOGIC;
  SIGNAL t_clk0_1            : STD_LOGIC;
  SIGNAL t_clk5              : STD_LOGIC;
BEGIN

UART0 : ENTITY work.uart_controller
  GENERIC MAP(
      baud_rate => 115200
      )
  PORT MAP(
      clk50            => clk50,
		rst              => NOT rst_n,
	   err              => err_uart,
      rx               => uart_rx,
      tx               => uart_tx,
	   motor_directive  => motor_directive,
	   encoder_velocity => encoder_velocity,
	   current_sense    => current_sense,
	   pot_angles       => pot_angles,
      ultrsnic_map     => ultrsnic_map
      );

I2CHost : ENTITY work.i2c_host_controller
  PORT MAP(
      clk50  => clk50,
	   clk0_1 => clk0_1,
		rst    => NOT rst_n,
	   err    => err_i2c_h,
	   scl    => scl_host,
	   sda    => sda_host
      );

I2CSlave : ENTITY work.i2c_slave_controller
  GENERIC MAP(
      slave_addr => "0000101"
      )
  PORT MAP(
      clk50            => clk50,
		rst              => NOT rst_n,
	   err              => err_i2c_s,
	   scl              => scl_slave,
	   sda              => sda_slave,
	   motor_directive  => motor_directive_i2c,
	   encoder_velocity => encoder_velocity,
	   current_sense    => current_sense,
	   pot_angles       => pot_angles,
      ultrsnic_map     => ultrsnic_map,
		status           => t_status,
		enc_velocity_rst => enc_velocity_rst
      );

SPIHost : ENTITY work.spi_host_controller
  PORT MAP(
      clk50         => clk50,
	   clk5          => clk5,
		rst           => NOT rst_n,
	   err           => err_spi_h,
	   miso          => miso_host,
	   mosi          => mosi_host,
	   sclk          => sclk_host,
	   ss_n          => ss_n_host,
	   current_sense => current_sense,
	   pot_angles    => pot_angles
      );

SPISlave : ENTITY work.spi_slave_controller
  PORT MAP(
      clk50            => clk50,
		rst              => NOT rst_n,
	   err              => err_spi_s,
	   miso             => miso_slave,
	   mosi             => mosi_slave,
	   sclk             => sclk_slave,
	   ss_n             => ss_n_slave,
	   motor_directive  => motor_directive_spi,
	   encoder_velocity => encoder_velocity,
	   current_sense    => current_sense,
	   pot_angles       => pot_angles,
      ultrsnic_map    => ultrsnic_map,
		status           => t_status,
		enc_velocity_rst => enc_velocity_rst
      );

  status <= t_status;
  motor_directive <= motor_directive_i2c WHEN PROTOCOL = '0' ELSE motor_directive_spi;

  clk5 <= t_clk5;
  PROCESS (clk50, rst_n)
  VARIABLE count : INTEGER RANGE 0 TO 4 := 0;
  BEGIN
    IF rst_n = '0' THEN
	   t_clk5 <= '1';
		count  :=  0 ;
    ELSIF RISING_EDGE(clk50) THEN
	   IF count = 4 THEN
	     count  := 0;
	     t_clk5 <= NOT t_clk5;
	   ELSE
	     count  := count + 1;
	   END IF;
	 END IF;
  END PROCESS;

  clk0_1 <= t_clk0_1;
  PROCESS (clk5, rst_n)
  VARIABLE count : INTEGER RANGE 0 TO 24 :=  0 ;
  BEGIN
    IF rst_n = '0' THEN
	   t_clk0_1 <= '1';
		count    :=  0 ;
    ELSIF RISING_EDGE(clk5) THEN
	   IF count = 24 THEN
	     count    := 0;
	     t_clk0_1 <= NOT t_clk0_1;
	   ELSE
	     count    := count + 1;
	   END IF;
	 END IF;
  END PROCESS;
END ARCHITECTURE;