cmake_minimum_required(VERSION 3.15)
project(boost_timer)
find_package(Boost)
include_directories(${BOOST_INCLUDE_DIRS})
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} ${BOOST_LIBRARIES} -lpthread)