cmake_minimum_required(VERSION 3.0)
project(Sieve_method)

include_directories(../include)

set(SRC circle.c point.c rectangle.c)

add_library(shapes STATIC ${SRC})