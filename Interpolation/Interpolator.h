#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H

#include <systemc.h>

SC_MODULE(Interpolator)
{
  sc_in<bool> clk;
  sc_in<bool> reset;

  sc_in<sc_uint<8>> in;

  sc_out<sc_uint<8>> out;
  sc_out<sc_uint<8>> out_interpolated;

  sc_signal<sc_uint<8>> prev_num;
  sc_signal<bool> is_first;

  void on_tick();

  SC_CTOR(Interpolator)
  {
    SC_CTHREAD(on_tick, clk.pos());
    async_reset_signal_is(reset, true);
  }
};

#endif
