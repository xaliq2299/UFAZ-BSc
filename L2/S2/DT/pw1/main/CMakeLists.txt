cmake_minimum_required(VERSION 3.0)
project(Sieve_method)

include_directories(../include)

add_executable(${PROJECT_NAME} main.c)
target_link_libraries(${PROJECT_NAME} shapes m)
