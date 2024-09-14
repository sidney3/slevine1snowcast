cmake_minimum_required(VERSION 3.3.0)

add_library(slib INTERFACE)


target_include_directories(slib INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/src)