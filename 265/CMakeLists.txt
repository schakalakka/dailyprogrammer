cmake_minimum_required(VERSION 3.5)
project(permutationsAndCombinations)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -std=c11 -g")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)

set(SOURCE_FILES src/permutationsandcombinations.c src/permutationsandcombinations.h)
add_executable(permutationsandcombinations ${SOURCE_FILES})