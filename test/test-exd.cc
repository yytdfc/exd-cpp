#include "exd.hpp"
#include <iostream>

int main(){
  // exd::split
  std::string s = ",,33,32s,";
  std::cout << exd::split(s,",") << std::endl;
  std::cout << exd::split("1,2,3",",") << std::endl;
  std::cout << exd::strip(s,",") << std::endl;
  std::cout << exd::strip("    ,") << std::endl;

  // exd::join
  std::vector<int> aa {1, 3, 4};
  std::cout << aa << std::endl;
  std::vector<std::string> a {"af", "123"};
  std::cout << exd::join(a, "^")  << std::endl;
  std::cout << exd::split(std::string("fad af af")) << std::endl;
  std::string str = "One Two Three ...";
  std::cout << exd::join(exd::split(str), "#")  << std::endl;

  // oss map
  std::map<std::string, int> map1;
  map1["something"] = 69;
  map1["anything"] = 199;
  map1["that thing"] = 50;
  std::cout << map1 << std::endl;
}
