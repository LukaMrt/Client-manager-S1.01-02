#include <stdio.h>
#include <stdbool.h>
#include "commands.h"

void executeCommand(const char *entry) {

    Command command = parseCommand(entry);

    int result = 0;

    for (char *i = command.name; *i != '\0'; ++i) {
        result += (int) *i;
    }

//    printf("Commande %s => %d\n", command.name, result);

    switch (result) {

        case 297:
            add();
            break;

        case 630:
            search();
            break;

        case 646:
            filter();
            break;

        case 627:
            delete();
            break;

        case 456:
            sort();
            break;

        case 422:
            edit();
            break;

        case 431:
            save();
            break;

        case 416:
            load();
            break;

        case 442: // exit
            break;

        default:
//            printf("Cette commande n'existe pas\n");
            break;
    }

}

Command parseCommand(const char *entry) {
    Command command = { "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", 0};
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

            Option option = { "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0", "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"};
            command.options[command.optionsCount - 1] = option;

            for (int j = (i - currentSize); j < i; ++j) {
                command.options[command.optionsCount - 1].name[j - i + currentSize] = entry[j];
            }

            currentSize = -1;
            continue;
        }

        command.options[command.optionsCount - 1].hasValue = true;

        for (int j = (i - currentSize); j < i; ++j) {
            command.options[command.optionsCount - 1].value[j - i + currentSize] = entry[j];
        }

        currentSize = -1;
    }

    return command;
}

void add() {
    printf("Entrez le nom du client à ajouter : \n");
}

void delete() {
    printf("Entrez le nom du client à supprimer : \n");
}

void filter() {
    printf("Entrez le champ selon lequel le filtre sera effectué : \n");
}

void search() {
    printf("Entrez le champ selon lequel la recherche sera effectuée : \n");
}

void sort() {
    printf("Entrez le champ selon lequel le tri sera effectué : \n");
}

void edit() {
    printf("Entrez le nom du client à modifier : \n");
}

void save() {
    printf("Entrez le nom du fichier dans lequel seront enregistrées les données : \n");
}

void load() {
    printf("Entrez le nom du fichier depuis lequel seront chargées les données : \n");
}
