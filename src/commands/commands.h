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

void executeCommand(const char *entry, Customer *customer);

void filter(Customer *customer, Command command);

void search(Customer *customer, Command command);

void sort(Customer *customer, Command command);

void edit(Customer *customer, Command command);

void save(Customer *customer, Command command);

#endif //CLIENT_MANAGER_S1_01_02_COMMANDS_H
