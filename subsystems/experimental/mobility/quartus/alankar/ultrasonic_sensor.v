/****************************************************
Ultrasonic sensor control for MSI-URC Mobility Board
Alankar Kotwal <alankarkotwal13@gmail.com>
Note that the counter should be able to time
range/330 sec. Make it sufficiently big.
Length in bits: ceil(log((range/330)*clk50_freq))
counter should be able to time 10us.
Length in bits: ceil(log(10us*clk50_freq))
****************************************************/

module ultrasonic_sensor(clk50, trig, sensor_echo, sensor_trig, distance, err, busy);
	
	input wire clk50, trig, sensor_echo;
	output reg [15:0] distance;
	output reg err, sensor_trig;
	output wire busy;
	
	reg [20:0] counter; // length?
	reg [2:0] state;
	
	assign busy = (state != 0);
	
	always@(state) begin
		case(state)
			0: begin 
				sensor_trig = 1'b0;
			end
			1: begin
				sensor_trig = 1'b1;
			end
			2: begin
				sensor_trig = 1'b0;
			end
			3: begin
				sensor_trig = 1'b0;
			end
			4: begin
				distance = counter;
				sensor_trig = 1'b0;
			end
			default: sensor_trig = 1'b0;
		endcase
	end
	
	always@(negedge clk50) begin
		counter = counter + 1;
		case(state) 
			0: begin 
				if(trig == 1'b1) begin
					state = 1;
					counter = 0;
				end
			end
			1: begin
				if(counter < 10) begin
					counter = counter + 1;
				end
				else begin
					state = 2;
					counter = 0;
				end
			end
			2: begin
				if(sensor_echo == 1'b1) begin
						state = 3;
						counter = 0;
				end
				else begin
					counter = counter + 1;
					if(counter == 18500) begin // Set this threshold, 18.5 ms
						state = 0;
						err = 1;
					end
				end
			end
			3: begin
				if(sensor_echo == 1'b0) begin
						state = 4;
				end
				else begin
					counter = counter + 1;
					if(counter == 65535) begin // Set this threshold, range/soundSpeed
						state = 0;
						err = 1;
					end
				end
			end
			4: begin
				state = 0;
				err = 0;
			end
		endcase
	end
	
endmodule 