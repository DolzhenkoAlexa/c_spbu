cmake_minimum_required(VERSION 4.0)
project(hw5_stack C)

set(CMAKE_C_STANDARD 17)

include_directories(
    src/hw5_stack
)

add_executable(hw5_stack
    src/hw5_stack/sortingStation.c
    src/hw5_stack/sortingStation.h
    src/hw5_stack/stack.c
)
