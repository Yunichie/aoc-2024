cmake_minimum_required(VERSION 3.30)
project(AOC_2024 C)

set(CMAKE_C_STANDARD 11)

file(GLOB SOURCES
        *.h
        *.c
)

add_executable(AOC_2024 main.c)
add_executable(day1 day1/day1.c)
