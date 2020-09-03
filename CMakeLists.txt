project(learn_ds CXX)
cmake_minimum_required(VERSION 2.8)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++98")

add_executable(ex1 ex1.cpp)
add_executable(ex2 ex2.cpp)