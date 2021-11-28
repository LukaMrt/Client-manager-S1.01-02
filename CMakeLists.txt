cmake_minimum_required(VERSION 3.20)
project(Client_manager_S1_01_02 C)

set(CMAKE_C_STANDARD 99)

add_executable(
        Customers_Manager
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
        src/commands/filter/filter.c
        src/commands/load/load.h
        src/commands/load/load.c
        src/commands/save/save.h
        src/commands/search/search.h
        src/commands/search/search.c
        src/commands/sort/sort.h
        src/commands/sort/sort.c
        src/commands/show/show.h
        src/commands/show/show.c
        src/utils/utils.h
        src/utils/utils.c
        src/commands/save/save.c
        src/utils/customersUtils.h
        src/utils/customersUtils.c
        src/commands/help/help.h
        src/commands/help/help.c
        src/commands/edit/edit.c
)
