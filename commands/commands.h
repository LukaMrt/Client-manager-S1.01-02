#ifndef CLIENT_MANAGER_S1_01_02_COMMANDS_H
#define CLIENT_MANAGER_S1_01_02_COMMANDS_H

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

void executeCommand(const char *entry);void add();

void delete();

void filter();

void search();

void sort();

void edit();

void save();

void load();

#endif //CLIENT_MANAGER_S1_01_02_COMMANDS_H
