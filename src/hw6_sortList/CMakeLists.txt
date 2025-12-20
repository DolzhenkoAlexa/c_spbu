cmake_minimum_required(VERSION 4.0)
project(hw6_sortList C)

set(CMAKE_C_STANDARD 17)

include_directories(src/hw6_sortList)
add_executable(sortList src/hw6_sortList/sortList.c)
