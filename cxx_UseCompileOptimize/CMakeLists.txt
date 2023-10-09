cmake_minimum_required(VERSION 3.15)
project(Use_CompileOptimize)
set(CMAKE_CXX_STANDARD 17)
find_package(Threads)
add_executable(test main.cpp
        cpp_name.h)
target_link_libraries(test Threads::Threads)