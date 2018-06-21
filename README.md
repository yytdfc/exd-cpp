# *exd-cpp*

_**exd**_ is headers only extend C++ utilities compares to _**std**_.



- __*exd::random*__

``` c++
#include "exd/random.hpp"
int main(){
    // rand int in range [3,7)
    auto l = exd::random::randint(3, 7);
    // rand float/double in range [2.5, 7.5]
    auto l = exd::random::random(2.5, 7.5);
    // shuffle a container
    std::vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9};
    exd::random::shuffle(v);
    // set custom rand seed (default seed is from std::random_device)
    exd::random::seed(1);
}
```

- __*exd::string*__

``` c++
#include "exd/random.hpp"
int main(){
    // split string
    exd::string::split("1,2,3", ",");
    // join string
    exd::string::join(std::vector<std::string>({"af", "123"}), "^");
    // strip string
    exd::string::strip(" good good study ");
}
```


- __*exd::range*__

``` c++
#include "exd/range.hpp"
int main(){
  // python like range
  for (auto i : exd::range::range(0, 10, 2))
    std::cout << i << "  ";
  std::cout << std::endl;
  // return vector container
  for (auto i : exd::range::range(0, 10, 3).to_vector())
    std::cout << i << "  ";
  std::cout << std::endl;
}
```

- __*exd::io*__

``` c++
#include "exd/io.hpp"
TEST(exd, io) {
  // oss vector
  std::cout << std::vector<std::string>({"1", "2", "3"}) << std::endl;
  // oss map
  std::map<std::string, int> map1;
  map1["something"] = 69;
  map1["anything"] = 199;
  map1["that thing"] = 50;
  std::cout << map1 << std::endl;
}
```