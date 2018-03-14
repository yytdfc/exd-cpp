#include "exd.hpp"
#include <iostream>

int main(){
  std::cout << "";
  std::vector<int> aa {1, 3, 4};
  std::cout << aa << std::endl;
  std::vector<std::string> a {"af", "123"};
  std::cout << exd::join(a, "^")  << std::endl;
  std::cout << exd::split(std::string("fad af af")) << std::endl;
  std::string str = "One Two Three ...";
  std::cout << exd::join(exd::split(str), "#")  << std::endl;
  std::map<std::string, int> map1;
  map1["something"] = 69;
  map1["anything"] = 199;
  map1["that thing"] = 50;
  std::cout << map1 << std::endl;
}
