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

    printf("  ~~~ Client manager ~~~ \n");
    char *entry = "";
    Customer customers[10000];

    for (int i = 0; i < 10000; ++i) {
        customers[i].valid = false;
    }

    do {
        printf("Enter a command : \n");
        
        char c;
        size_t size = 1;

        do {
            c = (char) getchar();
            entry = realloc(entry, size);
            entry[size++ - 1] = c;
        } while (c != '\n');

        entry[--size - 1] = '\0';

        executeCommand(entry, customers);
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
