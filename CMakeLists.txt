cmake_minimum_required(VERSION 3.17)
project(BangoBango C)

set(CMAKE_C_STANDARD 99)

add_executable(BangoBango main.c bangoPlateGenerator.h bangoPlateGenerator.c)