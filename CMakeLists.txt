cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(nZEMAX VERSION 0.1 LANGUAGES CXX)

add_executable( nZEMAX
    src/main.cpp
    src/vector/vector.cpp
    src/csystem/coordinate_system.cpp
    src/sphere/sphere.cpp
)

find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

target_link_libraries(nZEMAX sfml-graphics)

# set(${CMAKE_CXX_FLAGS} -O2 -fsanitize=address -g3)
set(${CMAKE_CXX_FLAGS} -O2)
