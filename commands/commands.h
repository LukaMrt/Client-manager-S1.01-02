#ifndef CLIENT_MANAGER_S1_01_02_COMMANDS_H
#define CLIENT_MANAGER_S1_01_02_COMMANDS_H

#include "../data.h"

typedef struct option {
    char name[20];
    char value[20];
} Option;

typedef struct command {
    char name[20];
    int optionsCount;
    Option options[20];
} Command;

Command parseCommand(const char *entry);

void executeCommand(const char *entry, Customer *customers);

void add(Customer *customers);

void delete(Customer *customers);

void filter(Customer *customers);

void search(Customer *customers);

void sort(Customer *customers);

void edit(Customer *customers);

void save(Customer *customers);

void load(Customer *customers);

#endif //CLIENT_MANAGER_S1_01_02_COMMANDS_H
