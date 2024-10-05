cmake_minimum_required(VERSION 3.29)
project(CLibraries C)
set(CMAKE_C_STANDARD 23)

add_executable(CLibraries
        main.c
        vector/vector.c
        vector/vector.h
        vector/vectorTests.h
        vector/vectorTests.c
)
