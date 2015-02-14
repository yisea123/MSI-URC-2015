library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity MobilityMSI is
port(
     clk             : in  std_ulogic;
	  clk_comm        : in  std_ulogic;
	  
	  lock            : in  std_ulogic;
	  proto_select    : in  std_ulogic;
	  
	  status          : out std_ulogic_vector(7 downto 0);
	  
	  scl_host        : out   std_ulogic;
	  sda_host        : inout std_ulogic;
	  
	  scl_slave       : in    std_ulogic;
	  sda_slave       : inout std_ulogic;

	  miso_host_0     : in  std_ulogic;
	  mosi_host_0     : out std_ulogic;
	  sck_host_0      : out std_ulogic;

	  miso_host_1     : in  std_ulogic;
	  mosi_host_1     : out std_ulogic;
	  sck_host_1      : out std_ulogic;

	  ss_host         : out std_ulogic_vector(7 downto 0);

	  miso_slave      : out std_ulogic;
	  mosi_slave      : in  std_ulogic;
	  sck_slave       : in  std_ulogic;
	  ss_slave        : in  std_ulogic;

	  uart_rx         : in  std_ulogic;
	  uart_tx         : out std_ulogic;
	  
	  motor_en        : out std_ulogic_vector(9 downto 0);
	  motor_pwm_f     : out std_ulogic_vector(9 downto 0);
	  motor_pwm_r     : out std_ulogic_vector(9 downto 0);
	  
	  encoder_a       : in  std_ulogic_vector(9 downto 0);
	  encoder_b       : in  std_ulogic_vector(9 downto 0);
	  
     ultrasonic_trig : out std_ulogic_vector(7 downto 0);
     ultrasonic_echo : in  std_ulogic_vector(7 downto 0)
	 );
end entity MobilityMSI;

architecture behavioral of MobilityMSI is
signal motor_directive     : int8_vector10;
signal motor_directive_i2c : int8_vector10;
signal motor_directive_spi : int8_vector10;
signal encoder_velocity    : int8_vector10;
signal current_sense       : uint8_vector10;
signal pot_angles          : int8_vector8;
signal ultrasonic_dist     : uint8_vector10;
signal error_uart          : integer range 0 to 3;
signal error_i2ch          : integer range 0 to 3;
signal error_i2cs          : integer range 0 to 3;
signal error_spih          : integer range 0 to 3;
signal error_spis          : integer range 0 to 3;
signal error_motd          : integer range 0 to 3;
signal error_ench          : integer range 0 to 3;
signal error_ultr          : integer range 0 to 3;
signal miso_host           : std_ulogic;
signal mosi_host           : std_ulogic;
signal sck_host            : std_ulogic;
begin

UART0 : entity work.UART
generic map(
     baud_rate => 115200
    )
port map(
	  clk      => clk,
	  clk_comm => clk_comm,
	  error    => error_uart,
     rx       => uart_rx,
     tx       => uart_tx,
	  motor_directive  => motor_directive,
	  encoder_velocity => encoder_velocity,
	  current_sense    => current_sense,
	  pot_angles       => pot_angles,
     ultrasonic_dist  => ultrasonic_dist
    );
I2CHost : entity work.I2C_Host
port map(
	  clk      => clk,
	  clk_comm => clk_comm,
	  error    => error_i2ch,
	  scl      => scl_host,
	  sda      => sda_host
    );
I2CSlave : entity work.I2C_Slave
generic map(
     slave_addr => "0000101"
    )
port map(
	  clk      => clk,
	  clk_comm => clk_comm,
	  error    => error_i2cs,
	  scl      => scl_slave,
	  sda      => sda_slave,
	  motor_directive  => motor_directive_i2c,
	  encoder_velocity => encoder_velocity,
	  current_sense    => current_sense,
	  pot_angles       => pot_angles,
     ultrasonic_dist  => ultrasonic_dist
    );
SPIHost : entity work.SPI_Host
port map(
	  clk      => clk,
	  clk_comm => clk_comm,
	  error    => error_spih,
	  miso     => miso_host,
	  mosi     => mosi_host,
	  sck      => sck_host,
	  ss       => ss_host,
	  current_sense => current_sense,
	  pot_angles => pot_angles
    );
SPISlave : entity work.SPI_Slave
port map(
	  clk      => clk,
	  clk_comm => clk_comm,
	  error    => error_spis,
	  miso     => miso_slave,
	  mosi     => mosi_slave,
	  sck      => sck_slave,
	  ss       => ss_slave,
	  motor_directive  => motor_directive_spi,
	  encoder_velocity => encoder_velocity,
	  current_sense    => current_sense,
	  pot_angles       => pot_angles,
     ultrasonic_dist  => ultrasonic_dist
    );
MotorDriver : entity work.Motor_Driver
port map(
	  clk       => clk,
	  error_out => error_motd,
	  error_in  => error_spih,
	  lock      => lock,
	  en        => motor_en,
	  pwm_f     => motor_pwm_f,
	  pwm_r     => motor_pwm_r,
	  directive => motor_directive
    );
EncoderHandler : entity work.Encoder_Handler
port map(
	  clk      => clk,
	  error    => error_ench,
	  pin_a    => encoder_a,
	  pin_b    => encoder_b,
	  velocity => encoder_velocity
    );
UltrasonicController : entity work.Ultrasonic_Controller
generic map (
     number_of_sensors => 3
    )
port map (
	  clk   => clk,
	  error => error_ultr,
	  trig  => ultrasonic_trig,
	  echo  => ultrasonic_echo,
	  dist  => ultrasonic_dist
    );
StatusPoll : entity work.Status_Poll
port map (
     status => status,
	  error_uart => error_uart,
	  error_i2ch => error_i2ch,
	  error_i2cs => error_i2cs,
	  error_spih => error_spih,
	  error_spis => error_spis,
	  error_motd => error_motd,
	  error_ench => error_ench,
	  error_ultr => error_ultr
    );
	 
motor_directive <= motor_directive_i2c when proto_select = '1' else motor_directive_spi;
--process (miso_host_0)
--begin
--miso_host <= miso_host_0
--end process;
--
--process (miso_host_1)
--begin
--miso_host <= miso_host_1
--end process;

process (mosi_host)
begin
mosi_host_0 <= mosi_host;
mosi_host_1 <= mosi_host;
end process;

process (sck_host)
begin
sck_host_0 <= sck_host;
sck_host_1 <= sck_host;
end process;

end behavioral;