cmake_minimum_required(VERSION 3.0)

project(pol LANGUAGES C)


set (SRC numop.c polish.c stack.c
         numop.h polish.h stack.h)

add_library(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE ${SRC})
target_link_libraries(${PROJECT_NAME} PRIVATE m)
