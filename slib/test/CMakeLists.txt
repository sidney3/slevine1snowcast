cmake_minimum_required(VERSION 3.14)

enable_testing()

add_executable(
    slibTests 
    src/jthreadtest.cpp
)

target_link_libraries(slibTests
    slib
    GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(slibTests)