cmake_minimum_required(VERSION 3.0)

project(polish LANGUAGES C)

set (PROJECT_TEST main_test)
set (PROJECT_CALC main_cal)

add_subdirectory(pol)

add_executable(${PROJECT_TEST} "")
target_sources(${PROJECT_TEST} PUBLIC main_test.c testing.h testing.c )
target_include_directories(${PROJECT_TEST} PUBLIC pol)
target_link_libraries(${PROJECT_TEST} PUBLIC pol cunit m)

add_executable(${PROJECT_CALC} "")
target_sources(${PROJECT_CALC} PUBLIC main_calc.c)
target_include_directories(${PROJECT_CALC} PUBLIC pol)
target_link_libraries(${PROJECT_CALC} PUBLIC pol m)


enable_testing()
add_test(TestPolishPW ${PROJECT_TEST})