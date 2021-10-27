#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "commands/commands.h"

bool shouldStop(const char *entry);

//char *inputString() {
//    size_t size = 10;
//    size_t index = 0;
//    char *entry;
//    int entryChar;
//
//    entry = realloc(NULL, size);
//    if (!entry) {
//        return entry;
//    }
//
//    while ((entryChar = fgetc(stdin)) != '\n') {
//        entry[index++] = (char) entryChar;
//
//        if (index == size) {
//            entry = realloc(entry, size += 16);
//            if (!entry) {
//                return entry;
//            }
//        }
//
//    }
//
//    entry[index] = '\0';
//    return entry;
//}

int main() {

    printf("  ~~~ Lancement du Client manager ~~~ \n");
    char *entry = realloc(NULL, 1);

    do {
        printf("Entrez une commande : \n");
        
        char c;
        size_t size = 1;

        do {
            c = (char) getchar();
            entry = realloc(entry, size);
            entry[size++ - 1] = c;
        } while (c != '\n');

        entry[--size - 1] = '\0';

        executeCommand(entry, size);
    } while (!shouldStop(entry));

    return 0;
}

bool shouldStop(const char *entry) {

    char exit[] = {'e', 'x', 'i', 't'};

    for (int i = 0; i < 4; ++i) {

        if (entry[i] != exit[i]) {
            return false;
        }

    }

    return true;
}
