cmake_minimum_required(VERSION 4.0)
project(hw5_stack C)

set(CMAKE_C_STANDARD 17)

add_executable(sortingStation
    sortingStation.c
    stack.c
)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(hw5_stack PRIVATE -Wall -Wextra -Wpedantic)
endif()
