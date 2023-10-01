cmake_minimum_required(VERSION 3.15)

project(GTEST_EXAMPLE)

set(CMAKE_CXX_STANDARD 17)
set(target_name gtest_example)
find_package(PkgConfig)
pkg_search_module(GTEST REQUIRED gtest_main)

add_executable(testapp)
target_sources(testapp PRIVATE main.cpp)
target_link_libraries(testapp PRIVATE ${GTEST_LDFLAGS})
target_compile_options(testapp PRIVATE ${GTEST_CFLAGS})

enable_testing()
add_test(first_and_only_test testapp)
include(GoogleTest)
gtest_discover_tests(testapp)
