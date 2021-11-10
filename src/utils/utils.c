#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

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

char *reformatString(const char *entry) {
    size_t size = 10;
    size_t index = 0;
    char *output;
    char entryChar;

    output = realloc(NULL, size);
    if (!output) {
        return output;
    }

    while ((entryChar = entry[index]) != '\0') {
        output[index++] = entryChar;

        if (index == size) {
            output = realloc(output, size += 16);
            if (!output) {
                return output;
            }
        }

    }

    output[index] = '\0';
    return output;
}

bool compareStrings(const char *name, const char *name1, int size) {

    int i;
    for (i = 0; i < size && name1[i] != '\n' && name1[i] != '\0'; ++i) {
        if (name[i] != name1[i]) {
            return false;
        }
    }

    return true;
}

Customer createCustomer() {
    Customer defaultCustomer = {
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            -1,
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            NULL
    };
    return defaultCustomer;
}
