cmake_minimum_required(VERSION 3.0)
project("CMake-test")

#include_directories(include) # not needed, mainly for header files
add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} f)
