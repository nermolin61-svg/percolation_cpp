cmake_minimum_required(VERSION 3.10)
project(Percolation)

set(CMAKE_CXX_STANDARD 17)  
set(CMAKE_CXX_STANDARD_REQUIRED ON)


include_directories(include)

add_executable(percolation
    src/main.cpp
    src/grid.cpp
    src/dfs.cpp
)

if(WIN32)
    target_link_libraries(percolation)
endif()
