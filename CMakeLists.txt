cmake_minimum_required(VERSION 3.24)
project(lab5 C)

set(CMAKE_C_STANDARD 11)

add_executable(lab5 main.c StringVectors.h StringVectors.c calc.h calc_stack.h calc_stack.c main_calc.c)