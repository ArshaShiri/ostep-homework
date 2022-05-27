cmake_minimum_required(VERSION 3.2)
project(memory_api)

#set(CMAKE_C_FLAGS "-g")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(p1 1-null.c)
add_executable(p4 4-malloc.c)
add_executable(p5 5-array.c)
add_executable(p6 6-array.c)

target_compile_options (p1 PRIVATE -g)
target_compile_options (p4 PRIVATE -g)
target_compile_options (p5 PRIVATE -g)
