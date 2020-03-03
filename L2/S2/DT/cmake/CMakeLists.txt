cmake_minimum_required(VERSION 3.0)
project("CMake-test" LANGUAGES C)

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin) # bin will be created in src dir, bcz compilin' happens there

#include_directories(cmake/include) # include header files
add_subdirectory(src)
add_subdirectory(include)

#add_executable(${PROJECT_NAME} main.c)
