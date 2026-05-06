#ifndef INTERPOLATORTEST_H
#define INTERPOLATORTEST_H

#include <iostream>
#include <systemc.h>

SC_MODULE(InterpolatorTest)
{
  sc_in<bool> clk;
  sc_out<bool> reset;
  sc_out<sc_uint<8>> num;
  sc_in<sc_uint<8>> output;
  sc_in<sc_uint<8>> output_interpolated;

  sc_signal<bool> check;

  sc_uint<8> expected_output;
  sc_uint<8> expected_interpolated;
  sc_uint<8> previous_num;
  bool is_first;

  void generate_nums();
  void check_output();

  SC_CTOR(InterpolatorTest):
    expected_output(0),
    expected_interpolated(0),
    previous_num(0),
    is_first(true)
  {
    SC_THREAD(generate_nums);
    sensitive << clk.pos();

    SC_METHOD(check_output);
    dont_initialize();
    sensitive << check.posedge_event();
  }
};

#endif
