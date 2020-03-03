cmake_minimum_required(VERSION 3.0)
project(string_manip LANGUAGES C)

set(PROJECT_TEST string_test)
add_subdirectory(string)

add_executable(${PROJECT_TEST} "")
target_sources(${PROJECT_TEST} PUBLIC test.c )
target_include_directories(${PROJECT_TEST} PUBLIC string)
target_link_libraries(${PROJECT_TEST} PUBLIC cunit string)


enable_testing()
add_test(String_Manipulation ${PROJECT_TEST})