LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.numeric_std.ALL;
LIBRARY work;

ENTITY uart IS
  GENERIC (
      DIVISOR: INTEGER RANGE 0 TO 255  -- DIVISOR = {CLK_FREQ / (16 x BAUD_RATE)} - 1
      );
  PORT(
      clk    : IN  STD_LOGIC;
      rst    : IN  STD_LOGIC;

      RxData : OUT STD_LOGIC_VECTOR(7 downto 0);
      RxEn   : OUT STD_LOGIC;
      TxData : IN  STD_LOGIC_VECTOR(7 downto 0);
      TxEn   : IN  STD_LOGIC;
      TxBusy : OUT STD_LOGIC;
      RxErr  : OUT STD_LOGIC;
	 
      rx     : IN  STD_LOGIC;
      tx     : OUT STD_LOGIC
      );
END ENTITY;

ARCHITECTURE main OF uart IS
SIGNAL Top16    : STD_LOGIC;
SIGNAL TopTx    : STD_LOGIC;
SIGNAL TopRx    : STD_LOGIC;
SIGNAL ClrDiv   : STD_LOGIC;
SIGNAL Div16    : INTEGER RANGE 0 TO 255;
SIGNAL ClkDiv   : INTEGER RANGE 0 TO 16;
SIGNAL RxDiv    : INTEGER RANGE 0 TO 7;

SIGNAL TxReg    : STD_LOGIC_VECTOR(9 DOWNTO 0);
SIGNAL TxBitCnt : INTEGER RANGE 0 TO 9;
SIGNAL TxFSM    : INTEGER RANGE 0 TO 3;
SIGNAL TxLat    : STD_LOGIC_VECTOR(7 DOWNTO 0);

SIGNAL RxReg    : STD_LOGIC_VECTOR(7 DOWNTO 0);
SIGNAL RxBitCnt : INTEGER RANGE 0 TO 8;
SIGNAL RxFSM    : INTEGER RANGE 0 TO 5;
SIGNAL RxRdy    : STD_LOGIC;
BEGIN
-- --------------------------
-- Clk16 Clock Generation
-- --------------------------
  PROCESS (rst, clk)
  BEGIN
    IF rst = '1' THEN
      Top16 <= '0';
      Div16 <= 0;
    ELSIF RISING_EDGE(clk) THEN
      Top16 <= '0';
      IF Div16 = DIVISOR THEN
        Div16 <= 0;
        Top16 <= '1';
      ELSE
        Div16 <= Div16 + 1;
      END IF;
    END IF;
  END PROCESS;
-- --------------------------
-- Tx Clock Generation
-- --------------------------
  PROCESS (rst, clk)
  BEGIN
    IF rst = '1' THEN
      TopTx <= '0';
      ClkDiv <= 0;
    ELSIF RISING_EDGE(clk) THEN
      TopTx <= '0';
      IF Top16='1' THEN
        ClkDiv <= ClkDiv + 1;
        IF ClkDiv = 15 THEN
          TopTx <= '1';
			 ClkDiv <= 0;
        END IF;
      END IF;
    END IF;
  END PROCESS;
-- ------------------------------
-- Rx Sampling Clock Generation
-- ------------------------------
  PROCESS (rst, clk)
  BEGIN
    IF rst = '1' THEN
      TopRx <= '0';
      RxDiv <= 0;
    ELSIF RISING_EDGE(clk) THEN
      TopRx <= '0';
		IF ClrDiv = '1' THEN
        RxDiv <= 0;
      ELSIF Top16 = '1' THEN
        IF RxDiv = 7 THEN
          RxDiv <= 0;
          TopRx <= '1';
        ELSE
          RxDiv <= RxDiv + 1;
        END IF;
      END IF;
    END IF;
  END PROCESS;
-- --------------------------
-- Transmit State Machine
-- --------------------------
  tx <= TxReg(0);
  PROCESS (rst, clk)
  BEGIN
    IF rst = '1' THEN
      TxReg        <= (others => '1');
      TxBitCnt     <= 0;
      TxFSM        <= 0;
      TxBusy       <= '0';
      TxLat        <= (others => '1');
    ELSIF RISING_EDGE(clk) THEN
      TxBusy       <= '1';
      CASE TxFSM IS
      WHEN 0 =>
        IF TxEn = '1' THEN
          TxLat    <= TxData;
          TxBusy   <= '1';
          TxFSM    <= 1;
        ELSE
          TxBusy   <= '0';
        END IF;
      WHEN 1 =>
        IF TopTx = '1' THEN
          TxFSM    <= 2;
          TxBitCnt <= 9; -- start + data
          TxReg    <= '1' & TxLat & '0';
        END IF;
		WHEN 2 =>
        IF TopTx = '1' THEN
          TxBitCnt <= TxBitCnt - 1;
          TxReg    <= '1' & TxReg(TxReg'high downto 1);
          IF TxBitCnt = 1 THEN
            TxFSM  <= 3;
          END IF;
        END IF;
      WHEN 3 =>
        IF TopTx = '1' THEN
          TxFSM    <= 0;
        END IF;
      WHEN OTHERS =>
        TxFSM      <= 0;
      END CASE;
    END IF;
  END PROCESS;
-- ------------------------
-- RECEIVE State Machine
-- ------------------------
  RxEn <= RxRdy;
  PROCESS (rst, clk)
  BEGIN
    IF rst = '1' THEN
      RxReg    <= (others => '0');
      RxData   <= (others => '0');
      RxBitCnt <= 0;
      RxFSM    <= 0;
      RxRdy   <= '0';
      ClrDiv   <= '0';
      RxErr    <= '0';
    ELSIF RISING_EDGE(clk) THEN
      ClrDiv   <= '0';
      IF RxRdy = '1' THEN
        RxErr  <= '0';
        RxRdy   <= '0';
      END IF;
      CASE RxFSM IS
      WHEN 0 => -- wait on start bit
        RxBitCnt <= 0;
        IF Top16 = '1' THEN
          IF rx = '0' THEN
            RxFSM  <= 1;
            ClrDiv <='1';
          END IF;
        END IF;
      WHEN 1 => -- wait on first data bit
        IF TopRx = '1' THEN
          IF rx = '1' THEN
            RxFSM <= 5;
          ELSE
            RxFSM <= 2;
          END IF;
        END IF;
      WHEN 2 => -- should be near Rx edge
        IF TopRx = '1' THEN
          RxFSM <= 3;
          IF RxBitCnt = 8 THEN
            RxFSM <= 4;
          ELSE
            RxFSM <= 3;
          END IF;
        END IF;
      WHEN 3 => -- sample data
        IF TopRx = '1' THEN
          RxBitCnt <= RxBitCnt + 1;
          RxReg    <= rx & RxReg (RxReg'high downto 1);
          RxFSM    <= 2;
        END IF;
      WHEN 4 => -- during Stop bit
        IF TopRx = '1' THEN
          RxData <= RxReg;
          RxRdy   <= '1';
          RxFSM  <=  0;
        END IF;
      WHEN 5 => -- Overflow / Error
        RxErr <= '1';
        IF rx = '1' THEN
          RxFSM <= 0;
        END IF;
      END CASE;
    END IF;
  END PROCESS;
END ARCHITECTURE;