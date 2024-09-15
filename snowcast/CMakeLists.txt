cmake_minimum_required(VERSION 3.3.0)

add_library(snowcast 
    lib/RadioStation.cpp)
    
add_subdirectory(test)
target_include_directories(snowcast PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/lib)
target_link_libraries(snowcast PRIVATE slib)