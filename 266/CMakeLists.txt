cmake_minimum_required(VERSION 3.5)
project(graph)

set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -std=c11")

set(SOURCE_FILES src/graph.c src/graph.h src/queue.h src/queue.c)
add_executable(graph ${SOURCE_FILES})

#LINK_DIRECTORIES(/home/andreas/workspace/dailyprogrammer/datastructures/lib/)
#include_directories(/home/andreas/workspace/dailyprogrammer/datastructures/src/)
#add_library(mylib STATIC IMPORTED)
#set_target_properties(mylib PROPERTIES IMPORTED_LOCATION /home/andreas/workspace/dailyprogrammer/datastructures/lib/libmylib.a)
#target_link_libraries(graph mylib)