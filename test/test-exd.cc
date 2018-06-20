#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "string.hpp"
#include "io.hpp"

TEST(exd, string) {
  // exd::split
  std::string s = ",,33,32s,";
  EXPECT_THAT(exd::split(s, ","),
              ::testing::ContainerEq(
                  std::vector<std::string>({"", "", "33", "32s", ""})));
  EXPECT_THAT(
      exd::split("1,2,3", ","),
      ::testing::ContainerEq(std::vector<std::string>({"1", "2", "3"})));
  EXPECT_EQ(exd::strip(s, ","), "33,32s");
  EXPECT_EQ(exd::strip("    ,"), ",");
  EXPECT_THAT(exd::split(std::string("good good study")),
              ::testing::ContainerEq(
                  std::vector<std::string>({"good", "good", "study"})));
  EXPECT_EQ(s, ",,33,32s,");

  // exd::join
  EXPECT_EQ(exd::join(std::vector<std::string>({"af", "123"}), "^"), "af^123");
  std::string str = "One Two Three ...";
  EXPECT_EQ(exd::join(exd::split(str), "#"), "One#Two#Three#...");
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
