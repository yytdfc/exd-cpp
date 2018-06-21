#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "range.hpp"
TEST(exd, range) {
  for (auto i : exd::range::range(0, 10, 2))
    std::cout << i << "  ";
  std::cout << std::endl;
  for (auto i : exd::range::range(0, 10, 3).to_vector())
    std::cout << i << "  ";
  std::cout << std::endl;
}
