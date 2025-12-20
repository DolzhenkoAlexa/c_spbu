cmake_minimum_required(VERSION 4.0)
project(hw5_stack C)

set(CMAKE_C_STANDARD 17)

include_directories(
    src/hw5_stack
)

add_executable(complex_parentheses
    src/hw5_stack/complexParenthese.c
    src/hw5_stack/complexParenthese.h
    src/hw5_stack/stack.c
    src/hw5_stack/stack.h
)
