cmake_minimum_required(VERSION 3.0)
project("CMake-test")

add_library(f SHARED f.c)

#install(TARGETS f LIBRARY DESTINATION lib)