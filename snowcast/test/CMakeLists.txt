cmake_minimum_required(VERSION 3.3.0)

add_executable(
    snowcastTests
    src/RadioStationTest.cpp
)

target_link_libraries(snowcastTests
    snowcast 
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(snowcastTests)