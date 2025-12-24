cmake_minimum_required(VERSION 4.0)
project(hw4_optimalSort  C)

set(CMAKE_C_STANDARD 17)

add_custom_command(
    OUTPUT sort.s
    COMMAND gcc -S -O2 sort.c -o sort.s
    DEPENDS sort.c
)

add_executable(hw4_optimalSort
    main.c
    sort.c

)
