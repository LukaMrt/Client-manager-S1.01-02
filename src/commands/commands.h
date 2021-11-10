#ifndef CLIENT_MANAGER_S1_01_02_COMMANDS_H
#define CLIENT_MANAGER_S1_01_02_COMMANDS_H

#include "../data.h"

/**
 * The Options class.
 */
typedef struct option {
    char name[20];
    char value[50];
} Option;

/**
 * The Command class is the base class for all commands.
 */
typedef struct command {
    char name[20];
    int optionsCount;
    Option options[20];
} Command;

void executeCommand(const char *entry, Customer *customer);

Command parseCommand(const char *entry);

void search(Customer *customer, Command command);

void sort(Customer *customer, Command command);

void edit(Customer *customer, Command command);

void save(Customer *customer, Command command);

#endif //CLIENT_MANAGER_S1_01_02_COMMANDS_H
