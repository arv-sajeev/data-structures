cmake_minimum_required(VERSION 3.10)
project(MyProgram)

set(CMAKE_CXX_STANDARD 20)

find_package(GTest REQUIRED)

add_executable(dynamic_array_test tests.cpp dynamic_array.cpp)

enable_testing()
target_link_libraries(dynamic_array_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(dynamic_array_test)
