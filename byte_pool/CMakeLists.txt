cmake_minimum_required(VERSION 3.10)
project(byte_pool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_executable(byte_pool
    main.c
    byte_pool.c
)
