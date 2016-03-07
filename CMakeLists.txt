cmake_minimum_required(VERSION 3.3)
project(New_Alpha)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main/main.cpp)
add_executable(New_Alpha ${SOURCE_FILES})