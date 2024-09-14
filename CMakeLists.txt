cmake_minimum_required(VERSION 3.3.0)

project(snowcast)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -std=c++23")

add_subdirectory(testExec)
add_subdirectory(slib)