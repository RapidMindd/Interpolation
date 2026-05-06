#include <systemc.h>

#include "Interpolator.h"

struct Tb : sc_module
{
  sc_in_clk clk{"clk"};
  sc_signal<bool> reset{"reset"};
  sc_signal<sc_uint<8>> in{"in"};
  sc_signal<sc_uint<8>> out{"out"};
  sc_signal<sc_uint<8>> out_interpolated{"out_interpolated"};

  Interpolator dut_inst{"dut_inst"};

  SC_CTOR(Tb)
  {
    dut_inst.clk(clk);
    dut_inst.reset(reset);
    dut_inst.in(in);
    dut_inst.out(out);
    dut_inst.out_interpolated(out_interpolated);
  }
};

int sc_main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;

  sc_clock clk{"clk", sc_time(1, SC_NS)};
  Tb tb{"tb"};
  tb.clk(clk);

  sc_start(SC_ZERO_TIME);
  return 0;
}
