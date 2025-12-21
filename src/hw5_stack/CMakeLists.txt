cmake_minimum_required(VERSION 3.16)
project(hw5_stack C)

set(CMAKE_C_STANDARD 17)

add_executable(complexParenthese
    complexParenthese.c
    stack.c
)

if(CMAKE_C_COMPILER_ID STREQUAL "GNU")
    target_compile_options(hw5_stack PRIVATE -Wall -Wextra -Wpedantic)
endif()
