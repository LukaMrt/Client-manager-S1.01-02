#include <stdio.h>
#include <string.h>
#include "commands.h"

//Command parseCommand(const char *str, char c, char ***arr);

void add();

void delete();

void filter();

void search();

void sort();

void edit();

void save();

void load();

void executeCommand(const char *entry, size_t size) {

    int result = 0;

    for (int i = 0; i < size; ++i) {
        result += (int) entry[i];
    }

    printf("Commande %s => %d\n", entry, result);

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
            printf("Cette commande n'existe pas\n");
    }

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

// Found on https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
//Command parseCommand(const char *str, char c, char ***arr) {
//
//    int count = 1;
//    int token_len = 1;
//    int i = 0;
//    char *p;
//    char *t;
//
//    p = str;
//    while (*p != '\0') {
//        if (*p == c)
//            count++;
//        p++;
//    }
//
//    *arr = (char **) malloc(sizeof(char *) * count);
//    if (*arr == NULL)
//        exit(1);
//
//    p = str;
//    while (*p != '\0') {
//        if (*p == c) {
//            (*arr)[i] = (char *) malloc(sizeof(char) * token_len);
//            if ((*arr)[i] == NULL)
//                exit(1);
//
//            token_len = 0;
//            i++;
//        }
//        p++;
//        token_len++;
//    }
//    (*arr)[i] = (char *) malloc(sizeof(char) * token_len);
//    if ((*arr)[i] == NULL)
//        exit(1);
//
//    i = 0;
//    p = str;
//    t = ((*arr)[i]);
//    while (*p != '\0') {
//        if (*p != c && *p != '\0') {
//            *t = *p;
//            t++;
//        } else {
//            *t = '\0';
//            i++;
//            t = ((*arr)[i]);
//        }
//        p++;
//    }
//
//    return count;
//}

//Command parseCommand(char *entry) {
//    Command command;
//    bool commandFound = false;
//    int currentSize = 1;
//    int argumentCount = 0;
//    bool lastArgument = true;
//
//    for (int i = 1; *(entry + i - 1) != '\0'; ++i) {
//
//        ++currentSize;
//        char a = *(entry + i - 1);
//        char b = *(entry + i);
//
//        if (*(entry + i) == ' ' || *(entry + i) == '\0') {
//
//            if (!commandFound) {
//                commandFound = true;
//
//                for (int j = 0; j < currentSize; ++j) {
//                    command.name[j] = *(entry + j);
//                }
//
//                printf("La commande est : %s\n", command.name);
//                currentSize = -1;
//                continue;
//            }
//
//            if (*(entry + i - currentSize) == '-') {
//
//                if (lastArgument) {
//                    ++argumentCount;
//                }
//
//                realloc(command.arguments, sizeof(command.arguments[0]) * (argumentCount + 1));
//                for (int j = (i - currentSize); j < i; ++j) {
//                    command.arguments[argumentCount].name[j - i + currentSize] = *(entry + j);
//                }
//
//                printf("L'option est : %s\n", command.arguments[argumentCount].name);
//                currentSize = -1;
//                lastArgument = true;
//
//            } else {
//
//                realloc(command.arguments[argumentCount].argument, currentSize);
//                for (int j = (i - currentSize); j < i; ++j) {
//                    command.arguments[argumentCount].argument[j - i + currentSize] = *(entry + j);
//                }
//
//                printf("L'argument est : %s\n", command.arguments[argumentCount].argument);
//                ++argumentCount;
//                currentSize = -1;
//                lastArgument = false;
//            }
//
//        }
//
//    }
//
//    return command;
//}
