cmake_minimum_required(VERSION 3.25)
project(project)

set(CMAKE_CXX_STANDARD 23)

add_executable(project main.cpp matrix/matrix.cpp input/input.cpp)
