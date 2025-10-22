cmake_minimum_required(VERSION 3.10)
project(Percolation)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# заголовки
include_directories(include)

# cpp-файлы проекта
add_executable(percolation
    src/main.cpp
    src/grid.cpp
    src/dfs.cpp
)
