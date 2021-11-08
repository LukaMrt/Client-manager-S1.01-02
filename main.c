#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "src/commands/commands.h"

char *scanString();

bool shouldStop(const char *entry);

int main() {

    printf("  ~~~ Client manager ~~~ \n");
    char *entry;

    Customer customer = {
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            -1,
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            NULL
    };

    do {

        printf("\n => Enter a command : ");
        entry = scanString();
        executeCommand(entry, &customer);

    } while (!shouldStop(entry));

    return 0;
}

char *scanString() {
    size_t size = 10;
    size_t index = 0;
    char *entry;
    int entryChar;

    entry = realloc(NULL, size);
    if (!entry) {
        return entry;
    }

    while ((entryChar = fgetc(stdin)) != '\n') {
        entry[index++] = (char) entryChar;

        if (index == size) {
            entry = realloc(entry, size += 16);
            if (!entry) {
                return entry;
            }
        }

    }

    entry[index] = '\0';
    return entry;
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
