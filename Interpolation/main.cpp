#include <systemc.h>
#include "Interpolator.h"
#include "InterpolatorTest.h"

int sc_main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  Interpolator interpolator("interpolator");
  InterpolatorTest interpolator_test("interpolator_test");

  sc_clock s_clk("clk", 5, SC_NS);

  sc_signal<bool> s_reset("reset");
  sc_signal<sc_uint<8>> s_num("num");
  sc_signal<sc_uint<8>> s_output("output");
  sc_signal<sc_uint<8>> s_output_interpolated("output_interpolated");

  interpolator_test.clk(s_clk);
  interpolator_test.reset(s_reset);
  interpolator_test.num(s_num);
  interpolator_test.output(s_output);
  interpolator_test.output_interpolated(s_output_interpolated);

  interpolator.clk(s_clk);
  interpolator.reset(s_reset);
  interpolator.in(s_num);
  interpolator.out(s_output);
  interpolator.out_interpolated(s_output_interpolated);

  sc_trace_file *tf = sc_create_vcd_trace_file("interpolator");
  tf->set_time_unit(1, SC_PS);

  sc_trace(tf, s_clk, "clk");
  sc_trace(tf, s_reset, "reset");
  sc_trace(tf, s_num, "num");
  sc_trace(tf, s_output, "output");
  sc_trace(tf, s_output_interpolated, "output_interpolated");

  sc_start(20000, SC_NS);
  sc_close_vcd_trace_file(tf);
  return 0;
}
