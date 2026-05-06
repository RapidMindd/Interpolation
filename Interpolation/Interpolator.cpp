#include "Interpolator.h"

void Interpolator::on_tick()
{
  if (reset.read())
  {
    prev_num.write(0);
    is_first.write(true);
    out.write(0);
    out_interpolated.write(0);
    return;
  }

  out.write(in.read());

  if (is_first.read())
  {
    out_interpolated.write(in.read());
    is_first.write(false);
  }
  else
  {
    out_interpolated.write((in.read() + prev_num.read()) / 2);
  }

  prev_num.write(in.read());
}
