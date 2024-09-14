cmake_minimum_required(VERSION 3.3.0)

add_executable(exec1 src/main.cpp)

target_link_libraries(exec1 PRIVATE slib)
