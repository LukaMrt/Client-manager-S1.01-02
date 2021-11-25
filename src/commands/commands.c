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

/**
 * Executes the options given by the user.
 * @param entry the command given by the user.
 * @param customer head list of customers.
 */
void executeCommand(const char *entry, Customer *customer) {

    Command command = parseCommand(entry);

    int result = 0;

    for (int i = 0; command.name[i] != '\0'; ++i) {
        result += (int) command.name[i];
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

        case 758: // display
        case 449: // show
            show(customer, command);
            break;

        case 425:
            help(customer, command);
            break;

        case 442: // exit
        case 451: // quit
        case 454: // stop
        case 311: // end
        case 113: // q
            break;

        default:
            printf("La commande %s n'existe pas.\n", command.name);
            break;
    }
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
