#include <gtest/gtest.h>
#include "io.hpp"
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
