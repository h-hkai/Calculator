cmake_minimum_required(VERSION 3.17)
project(calculator2)

set(CMAKE_CXX_STANDARD 11)

add_executable(calculator2 main.cpp BigInt.cpp BigInt.h String.cpp String.h Calculator.cpp Calculator.h)