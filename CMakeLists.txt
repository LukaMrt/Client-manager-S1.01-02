cmake_minimum_required(VERSION 3.20)
project(Client_manager_S1_01_02 C)

set(CMAKE_C_STANDARD 99)

add_executable(Client_manager_S1_01_02 main.c commands/commands.h commands/commands.c data.h)
