cmake_minimum_required(VERSION 3.22)
project(cmathematics C)

set(CMAKE_C_STANDARD 11)

add_executable(cmathematics
        cmathematics/main.c cmathematics/vec.h cmathematics/cmathematics.h cmathematics/vec.c)
