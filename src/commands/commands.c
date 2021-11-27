#include <stdio.h>
#include <stdbool.h>
#include "commands.h"
#include "add/add.h"
#include "show/show.h"
#include "load/load.h"
#include "delete/delete.h"
#include "filter/filter.h"
#include "search/search.h"
#include "save/save.h"
#include "help/help.h"
#include "edit/edit.h"
#include "sort/sort.h"
#include "../utils/utils.h"

/**
 * Executes the options given by the user.
 * @param entry the command given by the user.
 * @param customer head list of customers.
 */
void executeCommand(const char *entry, Customer *customer) {

    Command command = parseCommand(entry);

    if (compareStrings(command.name, "add", 4)) {
        add(customer, command);
        return;
    }

    if (compareStrings(command.name, "show", 5)
        || compareStrings(command.name, "display", 8)) {
        show(customer, command);
        return;
    }

    if (compareStrings(command.name, "load", 5)) {
        load(customer, command);
        return;
    }

    if (compareStrings(command.name, "delete", 7)) {
        delete(customer, command);
        return;
    }

    if (compareStrings(command.name, "filter", 7)) {
        filter(customer, command);
        return;
    }

    if (compareStrings(command.name, "search", 7)) {
        search(customer, command);
        return;
    }

    if (compareStrings(command.name, "save", 5)) {
        save(customer, command);
        return;
    }

    if (compareStrings(command.name, "help", 5)) {
        help(customer, command);
        return;
    }

    if (compareStrings(command.name, "edit", 5)) {
        edit(customer, command);
        return;
    }

    if (compareStrings(command.name, "sort", 5)) {
        sort(customer, command);
        return;
    }

    if (compareStrings(command.name, "exit", 5)
        || compareStrings(command.name, "quit", 5)
        || compareStrings(command.name, "q", 2)
        || compareStrings(command.name, "stop", 5)
        || compareStrings(command.name, "end", 4)) {
        return;
    }

    printf("Invalid command. Type 'help' for a list of commands.\n");
}

/**
 * Parses the command given by the user.
 * @param entry the command given by the user.
 * @return the command parsed with options.
 */
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
