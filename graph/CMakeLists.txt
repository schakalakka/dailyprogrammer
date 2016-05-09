cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -std=c11")

set(SOURCE_FILES graph.c graph.h)
add_executable(graph ${SOURCE_FILES})