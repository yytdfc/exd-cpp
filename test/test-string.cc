#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "string.hpp"

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
