cmake_minimum_required(VERSION 3.24)
project(RGR C)

set(CMAKE_C_STANDARD 11)

add_executable(RGR main.c create_and_shake.h create_and_shake.c game.h game.c save.h save.c open.h open.c)
