#include "Interpolator.h"

void Interpolator::on_tick()
{
  prev_num.write(0);
  is_first.write(true);
  out.write(0);
  out_interpolated.write(0);
  wait();

  while (true)
  {
    sc_uint<8> current = in.read();
    out.write(current);

    if (is_first.read())
    {
      out_interpolated.write(current);
      is_first.write(false);
    }
    else
    {
      out_interpolated.write((current + prev_num.read()) / 2);
    }

    prev_num.write(current);
    wait();
  }
}
