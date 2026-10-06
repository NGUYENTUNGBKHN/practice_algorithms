cmake_minimum_required(VERSION 3.10)
project(byte_pool C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

add_executable(byte_pool
    main.c
    byte_pool.c
)

target_include_directories(byte_pool PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

if(MSVC)
    target_compile_options(byte_pool PRIVATE /W4)
else()
    target_compile_options(byte_pool PRIVATE -Wall -Wextra -Wpedantic)
endif()
