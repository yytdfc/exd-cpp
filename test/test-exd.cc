#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "string.hpp"
#include "io.hpp"
#include "random.hpp"
#include "range.hpp"

TEST(exd, string) {
  // exd::split
  std::string s = ",,33,32s,";
  EXPECT_THAT(exd::string::split(s, ","),
              ::testing::ContainerEq(
                  std::vector<std::string>({"", "", "33", "32s", ""})));
  EXPECT_THAT(
      exd::string::split("1,2,3", ","),
      ::testing::ContainerEq(std::vector<std::string>({"1", "2", "3"})));
  EXPECT_EQ(exd::string::strip(s, ","), "33,32s");
  EXPECT_EQ(exd::string::strip("    ,"), ",");
  EXPECT_THAT(exd::string::split(std::string("good good study")),
              ::testing::ContainerEq(
                  std::vector<std::string>({"good", "good", "study"})));
  EXPECT_EQ(s, ",,33,32s,");

  // exd::join
  EXPECT_EQ(exd::string::join(std::vector<std::string>({"af", "123"}), "^"),
            "af^123");
  std::string str = "One Two Three ...";
  EXPECT_EQ(exd::string::join(exd::string::split(str), "#"),
            "One#Two#Three#...");
}

TEST(exd, io) {
  // oss vector
  std::vector<int> aa{1, 3, 4};
  std::cout << aa << std::endl;
  // oss map
  std::map<std::string, int> map1;
  map1["something"] = 69;
  map1["anything"] = 199;
  map1["that thing"] = 50;
  std::cout << map1 << std::endl;
}

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
  // shuffle vector
  std::vector<int> aa{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::cout << "Before shuffle: " << aa << std::endl;
  exd::random::shuffle(aa);
  std::cout << "After shuffle:  " << aa << std::endl;
  exd::random::shuffle(aa);
  std::cout << "After shuffle:  " << aa << std::endl;
}

TEST(exd, range) {
  for (auto i : exd::range::range(0, 10, 2))
    std::cout << i << "  ";
  std::cout << std::endl;
  std::cout << exd::range::range(0, 10, 3).to_vector() << std::endl;
}

int main(int argc, char* argv[]) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
