cmake_minimum_required(VERSION 3.29)
project(Homebrew C)
set(CMAKE_C_STANDARD 23)

add_subdirectory(homebrew)

add_executable(Homebrew
        tests.c
        unity.c
        unity_config.h
        cmake-build-debug/tests.h
)

target_link_libraries(Homebrew PUBLIC HomebrewLib)

target_include_directories(Homebrew PUBLIC
        "${PROJECT_BINARY_DIR}"
)

