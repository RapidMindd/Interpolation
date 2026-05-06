#include "InterpolatorTest.h"

void InterpolatorTest::generate_nums()
{
  sc_uint<8> test_nums[] = {1, 10, 20, 30, 31};
  int test_count = 5;
  int index = 0;

  reset.write(1);
  check.write(0);
  num.write(0);
  expected_output = 0;
  expected_interpolated = 0;
  previous_num = 0;
  is_first = true;

  wait(10, SC_NS);
  wait();

  check.write(1);
  wait();
  check.write(0);

  reset.write(0);

  while (1)
  {
    expected_output = test_nums[index];

    if (is_first)
    {
      expected_interpolated = test_nums[index];
      is_first = false;
    }
    else
    {
      expected_interpolated = (test_nums[index] + previous_num) / 2;
    }

    num.write(test_nums[index]);
    previous_num = test_nums[index];

    index = (index + 1) % test_count;

    wait();

    check.write(1);
    wait(SC_ZERO_TIME);
    check.write(0);
  }
}

void InterpolatorTest::check_output()
{
  if (output.read() != expected_output || output_interpolated.read() != expected_interpolated)
  {
    std::cerr << "Error at " << sc_time_stamp() << ": generated out " << output.read()
      << " out_interpolated " << output_interpolated.read() << " when required out " << expected_output
      << " out_interpolated " << expected_interpolated << "\n";
  }
}
