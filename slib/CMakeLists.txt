cmake_minimum_required(VERSION 3.3.0)

add_library(slib 
    src/TCPStream.cpp
    src/UDPStream.cpp)

add_subdirectory(test)

target_include_directories(slib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)