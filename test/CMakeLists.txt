add_executable(Math-Test math.cpp)
target_link_libraries(Math-Test PRIVATE GTest::gtest_main math)
target_code_coverage(Math-Test AUTO ALL EXTERNAL)
