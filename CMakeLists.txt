cmake_minimum_required (VERSION 2.6)

project (Neurone)


set(CMAKE_CXX_FLAGS "-O3 -std=c++11")



enable_testing()
add_subdirectory(gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable (Neurone Constants.hpp Neurone.cpp Network.cpp main.cpp)

add_executable(unittest Constants.hpp Neurone.cpp Network.cpp gtest.cpp)

target_link_libraries(unittest gtest gtest)
add_test(unittest unittest)
