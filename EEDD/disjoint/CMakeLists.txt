cmake_minimum_required(VERSION 3.24)
project(disjoint C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(disjoint
        disjoint.c
        disjoint.h
        prdisjoint.c)
