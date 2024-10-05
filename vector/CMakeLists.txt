cmake_minimum_required(VERSION 3.29)
project(VectorTests C)
set(CMAKE_C_STANDARD 23)

add_executable(VectorTests vectorTests.c
        vector/vector.c
        vector/vector.h)
