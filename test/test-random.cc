#include <iostream>
#include <gtest/gtest.h>
#include "random.hpp"
#include "io.hpp"
TEST(exd, random) {
  // randint
  for (auto i = 0; i != 32; ++i) {
    const auto lower = -3;
    const auto upper = 3;
    auto       l = exd::random::randint(lower, upper - 1);
    EXPECT_GE(l, lower);
    EXPECT_LT(l, upper - 1);
    auto u = exd::random::randint(l + 1, upper);
    EXPECT_GE(u, l + 1);
    EXPECT_LT(u, upper);
    auto r = exd::random::randint(l, u);
    EXPECT_GE(r, l);
    EXPECT_LT(r, u);
  }
  // random
  for (auto i = 0; i != 10; ++i) {
    auto r = exd::random::random();
    EXPECT_GE(r, 0);
    EXPECT_LE(r, 1);
  }
  // distribution
  auto dist = exd::random::distribution(std::normal_distribution<>(5, 2));
  for (auto i = 0; i != 10; ++i) {
    dist();
  }
  // shuffle vector
  std::vector<int> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
  exd::random::seed(1);
  exd::random::shuffle(a);
  std::vector<int> b{1, 2, 3, 4, 5, 6, 7, 8, 9};
  exd::random::seed(1);
  exd::random::shuffle(b);
  EXPECT_EQ(a, b);
  std::vector<int> c{1, 2, 3, 4, 5, 6, 7, 8, 9};
  exd::random::seed(2);
  exd::random::shuffle(c);
  std::cout << c;
  EXPECT_NE(a, c);
}
