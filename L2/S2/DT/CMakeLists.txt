cmake_minimum_required(VERSION 3.0)
project(mylib LANGUAGES C)
add_library(${PROJECT_NAME} lib_src1.c lib_src2.c) // can be SHARED or STATIC
target_sources(${PROJECT_NAME} PUBLIC mylib.h)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

add_subdirectory(mylib_dir)
add_executable(${PROJECT_NAME} source.c)
target_link_libraries(${PROJECT_NAME} mylib cunit) // smtms PUBLIC PRIVATE can be important; inclusion of m, cunit, etc.

add_library(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})

add_executable(${PROJECT_TEST} "")
target_sources(${PROJECT_TEST} PUBLIC main_test.c testing.h testing.c )
target_include_directories(${PROJECT_TEST} PUBLIC pol)
target_link_libraries(${PROJECT_TEST} PUBLIC pol cunit m)

enable_testing()
add_test(name ${PROJECT_TEST}})






CMAKE_SOURCE_DIR
PROJECT_SOURCE_DIR
CMAKE_CURRENT_SOURCE_DIR
CMAKE_PROJECT_NAME
PROJECT_NAME

CMAKE_INSTALL_PREFIX
CMAKE_PREFIX_PATH