cmake_minimum_required(VERSION 3.5)
project(exd-cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(include include)

aux_source_directory(test      TEST)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


enable_testing()
foreach(i ${TEST})
  STRING(REGEX REPLACE ".+/(.+)\\..*" "\\1" CASE_NAME ${i})
  message(STATUS "Test case : ${CASE_NAME} - ${i}")
  add_executable(${CASE_NAME} ${i})
  target_link_libraries(${CASE_NAME} gtest_main gtest pthread glog)
  add_test(${CASE_NAME} ${CASE_NAME})
endforeach(i)



