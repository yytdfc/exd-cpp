cmake_minimum_required(VERSION 3.5)
project(exd-cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include include)

aux_source_directory(test      TEST)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test-exd test/test-exd.cc )
target_link_libraries(test-exd gtest_main gtest pthread glog)

add_test(test-exd test-exd)


