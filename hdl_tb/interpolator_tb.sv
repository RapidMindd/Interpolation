`timescale 1ns/1ps

module interpolator_tb;
  logic clk = 1'b0;
  logic reset = 1'b1;
  logic [7:0] in = 8'd0;
  logic [7:0] out;
  logic [7:0] out_interpolated;

  logic [7:0] test_nums [0:4];
  logic [7:0] expected_out;
  logic [7:0] expected_interpolated;
  logic [7:0] previous_num;
  bit is_first;
  int errors = 0;

  Interpolator dut (
    .clk(clk),
    .reset(reset),
    .in(in),
    .out(out),
    .out_interpolated(out_interpolated)
  );

  always #2.5 clk = ~clk;

  initial begin
    $dumpfile("build/interpolator_hdl.vcd");
    $dumpvars(0, interpolator_tb);

    test_nums[0] = 8'd1;
    test_nums[1] = 8'd10;
    test_nums[2] = 8'd20;
    test_nums[3] = 8'd30;
    test_nums[4] = 8'd31;

    expected_out = 8'd0;
    expected_interpolated = 8'd0;
    previous_num = 8'd0;
    is_first = 1'b1;

    #10;
    @(posedge clk);
    #1;
    check_outputs();

    reset = 1'b0;

    for (int i = 0; i < 20; i++) begin
      automatic logic [7:0] current = test_nums[i % 5];

      expected_out = current;
      if (is_first) begin
        expected_interpolated = current;
        is_first = 1'b0;
      end else begin
        expected_interpolated = (current + previous_num) / 2;
      end

      in = current;
      previous_num = current;

      @(posedge clk);
      #1;
      check_outputs();
    end

    if (errors == 0) begin
      $display("interpolator_tb: PASS");
    end else begin
      $display("interpolator_tb: FAIL, errors=%0d", errors);
      $fatal(1);
    end

    $finish;
  end

  task check_outputs;
    if (out !== expected_out || out_interpolated !== expected_interpolated) begin
      $display(
        "Error at %0t: generated out=%0d out_interpolated=%0d, expected out=%0d out_interpolated=%0d",
        $time,
        out,
        out_interpolated,
        expected_out,
        expected_interpolated
      );
      errors++;
    end
  endtask
endmodule
