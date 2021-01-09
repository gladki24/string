cmake_minimum_required(VERSION 3.17)
project(string C)

set(CMAKE_C_STANDARD 11)

# TODO transform to library
add_executable(string main.c flowerpot_string.h flowerpot_string.c)