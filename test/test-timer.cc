#include <gtest/gtest.h>
#include "exd/timer.hpp"
TEST(exd, io) {
  // oss vector
  exd::timer::tic();
  std::cout << exd::timer::toc() << std::endl;
  std::cout << exd::timer::info() << std::endl;
  auto timer = exd::timer::timer();
  std::cout << timer.toc() << std::endl;
  std::cout << timer.info() << std::endl;
}
