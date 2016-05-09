cmake_minimum_required(VERSION 3.5)
project(askname)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11 -Wall -Wextra")

set(SOURCE_FILES main.c)
add_executable(askname ${SOURCE_FILES})