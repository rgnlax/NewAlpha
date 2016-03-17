cmake_minimum_required(VERSION 3.3)
project(New_Alpha)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp server/server.cpp server/server.h server/server_conf.cpp server/server_conf.h)
add_executable(New_Alpha ${SOURCE_FILES})

target_link_libraries(New_Alpha config++)
target_link_libraries(New_Alpha ${CMAKE_THREAD_LIBS_INIT})


