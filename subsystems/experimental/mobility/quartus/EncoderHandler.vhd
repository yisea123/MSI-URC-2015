-- http://playground.arduino.cc/Main/RotaryEncoders

library ieee;
use ieee.std_logic_1164.all;
library work;
use work.mobility_types_pkg.all;

entity Encoder_Handler is
port(
	  clk      : in  std_ulogic;
	  error    : out integer range 0 to 3;
	  
	  pin_a    : in  std_ulogic_vector(9 downto 0);
	  pin_b    : in  std_ulogic_vector(9 downto 0);

	  velocity : out int8_vector10
    );
end entity Encoder_Handler;

architecture behavioral of Encoder_Handler is
signal rst : std_ulogic;
signal pose : int8_vector10;
begin
process (pin_a(0), rst)
begin
  if (rising_edge(rst)) then
    pose(0) <= 0;
  elsif (pin_a(0) = '1') then
    if (pin_b(0) = '1') then
	   pose(0) <= pose(0) + 1;
	 else
	   pose(0) <= pose(0) - 1;
	 end if;
  else
    if (pin_b(0) = '1') then
	   pose(0) <= pose(0) - 1;
	 else
	   pose(0) <= pose(0) + 1;
	 end if;
  end if;
end process;

process (pin_a(1), rst)
begin
  if (rising_edge(rst)) then
  pose(1) <= 0;
  elsif (pin_a(1) = '1') then
    if (pin_b(1) = '1') then
	   pose(1) <= pose(1) + 1;
	 else
	   pose(1) <= pose(1) - 1;
	 end if;
  else
    if (pin_b(1) = '1') then
	   pose(1) <= pose(1) - 1;
	 else
	   pose(1) <= pose(1) + 1;
	 end if;
  end if;
end process;

process (pin_a(2), rst)
begin
  if (rising_edge(rst)) then
  pose(2) <= 0;
  elsif (pin_a(2) = '1') then
    if (pin_b(2) = '1') then
	   pose(2) <= pose(2) + 1;
	 else
	   pose(2) <= pose(2) - 1;
	 end if;
  else
    if (pin_b(2) = '1') then
	   pose(2) <= pose(2) - 1;
	 else
	   pose(2) <= pose(2) + 1;
	 end if;
  end if;
end process;

process (pin_a(3), rst)
begin
  if (rising_edge(rst)) then
  pose(3) <= 0;
  elsif (pin_a(3) = '1') then
    if (pin_b(3) = '1') then
	   pose(3) <= pose(3) + 1;
	 else
	   pose(3) <= pose(3) - 1;
	 end if;
  else
    if (pin_b(3) = '1') then
	   pose(3) <= pose(3) - 1;
	 else
	   pose(3) <= pose(3) + 1;
	 end if;
  end if;
end process;

process (pin_a(4), rst)
begin
  if (rising_edge(rst)) then
  pose(4) <= 0;
  elsif (pin_a(4) = '1') then
    if (pin_b(4) = '1') then
	   pose(4) <= pose(4) + 1;
	 else
	   pose(4) <= pose(4) - 1;
	 end if;
  else
    if (pin_b(4) = '1') then
	   pose(4) <= pose(4) - 1;
	 else
	   pose(4) <= pose(4) + 1;
	 end if;
  end if;
end process;

process (pin_a(5), rst)
begin
  if (rising_edge(rst)) then
  pose(5) <= 0;
  elsif (pin_a(5) = '1') then
    if (pin_b(5) = '1') then
	   pose(5) <= pose(5) + 1;
	 else
	   pose(5) <= pose(5) - 1;
	 end if;
  else
    if (pin_b(5) = '1') then
	   pose(5) <= pose(5) - 1;
	 else
	   pose(5) <= pose(5) + 1;
	 end if;
  end if;
end process;

process (pin_a(6), rst)
begin
  if (rising_edge(rst)) then
  pose(6) <= 0;
  elsif (pin_a(6) = '1') then
    if (pin_b(6) = '1') then
	   pose(6) <= pose(6) + 1;
	 else
	   pose(6) <= pose(6) - 1;
	 end if;
  else
    if (pin_b(6) = '1') then
	   pose(6) <= pose(6) - 1;
	 else
	   pose(6) <= pose(6) + 1;
	 end if;
  end if;
end process;

process (pin_a(7), rst)
begin
  if (rising_edge(rst)) then
  pose(7) <= 0;
  elsif (pin_a(7) = '1') then
    if (pin_b(7) = '1') then
	   pose(7) <= pose(7) + 1;
	 else
	   pose(7) <= pose(7) - 1;
	 end if;
  else
    if (pin_b(7) = '1') then
	   pose(7) <= pose(7) - 1;
	 else
	   pose(7) <= pose(7) + 1;
	 end if;
  end if;
end process;

process (pin_a(8), rst)
begin
  if (rising_edge(rst)) then
  pose(8) <= 0;
  elsif (pin_a(8) = '1') then
    if (pin_b(8) = '1') then
	   pose(8) <= pose(8) + 1;
	 else
	   pose(8) <= pose(8) - 1;
	 end if;
  else
    if (pin_b(8) = '1') then
	   pose(8) <= pose(8) - 1;
	 else
	   pose(8) <= pose(8) + 1;
	 end if;
  end if;
end process;

process (pin_a(9), rst)
begin
  if (rising_edge(rst)) then
  pose(9) <= 0;
  elsif (pin_a(9) = '1') then
    if (pin_b(9) = '1') then
	   pose(9) <= pose(9) + 1;
	 else
	   pose(9) <= pose(9) - 1;
	 end if;
  else
    if (pin_b(9) = '1') then
	   pose(9) <= pose(9) - 1;
	 else
	   pose(9) <= pose(9) + 1;
	 end if;
  end if;
end process;
end behavioral;