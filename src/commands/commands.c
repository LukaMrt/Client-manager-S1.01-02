#include <stdio.h>
#include <stdbool.h>
#include "commands.h"
#include "add/add.h"
#include "show/show.h"
#include "load/load.h"

void executeCommand(const char *entry, Customer *customer) {

    Command command = parseCommand(entry);

    int result = 0;

    for (int i = 0; entry[i] != '\0'; ++i) {
        result += (int) entry[i];
    }

//    printf("Commande %s => %d\n", command.name, result);

    switch (result) {

        case 297:
            add(customer, command);
            break;

        case 630:
            search(customer, command);
            break;

        case 646:
            filter(customer, command);
            break;

        case 627:
            delete(customer, command);
            break;

        case 456:
            sort(customer, command);
            break;

        case 422:
            edit(customer, command);
            break;

        case 431:
            save(customer, command);
            break;

        case 416:
            load(customer, command);
            break;

        case 449:
            show(customer, command);
            break;

        case 442: // exit
            printf("  ~~~ Client manager ~~~ \n");
            break;

        default:
            printf("Cette commande n'existe pas\n");
            break;
    }
}

Command parseCommand(const char *entry) {
    Command command = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 0};
    bool commandFound = false;
    int currentSize = 1;

    for (int i = 1; entry[i - 1] != '\0'; ++i) {

        ++currentSize;

        if (entry[i] != ' ' && entry[i] != '\0') {
            continue;
        }

        if (!commandFound) {
            commandFound = true;

            for (int j = (i - currentSize); j < currentSize - 1; ++j) {
                command.name[j] = entry[j];
            }

            currentSize = -1;
            continue;
        }

        if (entry[i - currentSize] == '-') {

            ++command.optionsCount;

            Option option = {"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
            command.options[command.optionsCount - 1] = option;

            for (int j = (i - currentSize); j < i; ++j) {
                command.options[command.optionsCount - 1].name[j - i + currentSize] = entry[j];
            }

            currentSize = -1;
            continue;
        }

        for (int j = (i - currentSize); j < i; ++j) {
            command.options[command.optionsCount - 1].value[j - i + currentSize] = entry[j];
        }

        currentSize = -1;
    }

    return command;
}

void delete(Customer *customer, Command command) {
    printf("Enter the name of the client to remove : ");
}

void filter(Customer *customer, Command command) {
    printf("Enter the field which will used to process the filter : ");
}

void search(Customer *customer, Command command) {
    printf("Enter the field which will used to process the research : ");
}

void sort(Customer *customer, Command command) {
    printf("Enter the field which will used to process the sort : ");
}

void edit(Customer *customer, Command command) {
    printf("Enter the name of the customer to edit : ");
}

void save(Customer *customer, Command command) {
    printf("Enter the file where customers will be stored : ");
}