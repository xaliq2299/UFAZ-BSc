cmake_minimum_required(VERSION 3.0)
project(Cunit-test LANGUAGES C)

add_executable(${PROJECT_NAME} main_test.c)
target_link_libraries(${PROJECT_NAME} oper cunit)