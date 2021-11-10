cmake_minimum_required(VERSION 3.20)
project(Client_manager_S1_01_02 C)

set(CMAKE_C_STANDARD 99)

add_executable(
        Client_manager_S1_01_02
        main.c
        src/commands/commands.h
        src/commands/commands.c
        src/data.h
        src/commands/add/add.h
        src/commands/add/add.c
        src/commands/delete/delete.h
        src/commands/delete/delete.c
        src/commands/edit/edit.h
        src/commands/filter/filter.h
        src/commands/load/load.h
        src/commands/load/load.c
        src/commands/save/save.h
        src/commands/search/search.h
        src/commands/sort/sort.h
        src/commands/show/show.h
        src/commands/show/show.c
)
