add_subdirectory(math)


# add_library(util util.cpp)
# target_code_coverage(util AUTO ALL EXTERNAL)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE fmt::fmt-header-only util math)

target_code_coverage(main AUTO ALL EXTERNAL)
