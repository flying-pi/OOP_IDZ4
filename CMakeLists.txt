cmake_minimum_required(VERSION 3.6)
project(OOP_IDZ4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp MyArray.cpp MyArray.h OutPrinter.cpp OutPrinter.h)
add_executable(OOP_IDZ4 ${SOURCE_FILES})