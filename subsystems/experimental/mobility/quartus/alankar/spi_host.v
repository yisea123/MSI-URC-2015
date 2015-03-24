/***********************************************
ADC SPI interface for MSI-URC Mobility Board
Alankar Kotwal <alankarkotwal13@gmail.com>
Continuously updates all values
Assumes the following:
SS[0]: first four channels are pots[0:3]
		 next four channels are curr_sense[0:3]
SS[1]: first four channels are pots[4:7]
		 next four channels are curr_sense[4:7]
SS[2]: first two channels are curr_sense[8:9]
************************************************/

// Resolve latches later

module spi_host(clk, rst, mosi, miso, sck, ss_adc, pots, curr_sense);

	input wire miso, clk, rst;
	output wire mosi, sck;
	output reg [2:0] ss_adc;
	
	output reg [15:0] pots [7:0];
	output reg [15:0] curr_sense [9:0];
	
	reg        start;
	reg  [1:0] ss_no;
	reg  [2:0] ch_no;
	reg  [3:0] host_state;
	reg  [7:0] data_out;
	
	wire [7:0] data_in;
	wire       busy;
	
	spi_host_base _spihostbase(.clk(clk), .rst(rst), .sck(sck), .mosi(mosi), .miso(miso), .start(start), .data_in(data_out), .data_out(data_in), .busy(busy));
	
	always@(host_state) begin
		case(host_state)
			0: begin
				ss_adc[ss_no] = 0;
				data_out = ch_no << 3;
			end
			1:  start = 1;
			2:	 start = 0;
			3:  start = 1;
			4:  start = 0;
			5:  start = 1;
			6:  start = 0;
			7:  start = 1;
			8:  start = 0;
			9:  ss_adc[ss_no] = 1;
			10: begin
				case(ss_no)
					0: begin
						if(ch_no == 7) begin
							ch_no = 0;
							ss_no = 1;
						end
						else begin
							ch_no = ch_no + 1;
						end
					end
					1: begin
						if(ch_no == 7) begin
							ch_no = 0;
							ss_no = 2;
						end
						else begin
							ch_no = ch_no + 1;
						end
					end
					2: begin
						if(ch_no == 1) begin
							ch_no = 0;
							ss_no = 0;
						end
						else begin
							ch_no = ch_no + 1;
						end
					end
					default: begin
						ss_no = 0;
						ch_no = 0;
					end
				endcase
			end
		endcase
	end
	
	always@(negedge clk) begin
		case(host_state)
			0: host_state = 1;
			1: host_state = 2;
			2: begin
				if(busy == 0) host_state = 3;
			end
			3: host_state = 4;
			4: begin
				if(busy == 0) host_state = 5;
			end
			5: host_state = 6;
			6: begin
				if(busy == 0) host_state = 7;
				case(ss_no)
					0: begin
						if(ch_no<4) begin
							pots[ch_no][15:8] = data_in;
						end
						else begin
							curr_sense[ch_no][15:8] = data_in;
						end
					end
					1: begin
						if(ch_no<4) begin
							pots[4+ch_no][15:8] = data_in;
						end
						else begin
							curr_sense[4+ch_no][15:8] = data_in;
						end
					end
					2: begin
						curr_sense[8+ch_no][15:8] = data_in;
					end
					default: begin end
				endcase
			end
			7: host_state = 8;
			8: begin
				if(busy == 0) host_state = 9;
				case(ss_no)
					0: begin
						if(ch_no<4) begin
							pots[ch_no][7:0] = data_in;
						end
						else begin
							curr_sense[ch_no][7:0] = data_in;
						end
					end
					1: begin
						if(ch_no<4) begin
							pots[4+ch_no][7:0] = data_in;
						end
						else begin
							curr_sense[4+ch_no][7:0] = data_in;
						end
					end
					2: begin
						curr_sense[8+ch_no][7:0] = data_in;
					end
					default: begin end
				endcase
			end
			9:  host_state = 10;
			10: host_state = 0;
		endcase
	end
	
endmodule 
