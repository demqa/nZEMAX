cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(GraphicalLibrary VERSION 0.1 LANGUAGES CXX)

add_executable( GraphicalLibrary
    src/main.cpp
    src/vector/vector.cpp
)

set(${CMAKE_CXX_FLAGS} -O2 -fsanitize=address -g3)
