#include <stdio.h>
#include <stdbool.h>
#include "src/commands/commands.h"
#include "src/utils/utils.h"

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

bool shouldStop(const char *entry) {

    char exit[] = {'e', 'x', 'i', 't'};

    for (int i = 0; i < 4; ++i) {

        if (entry[i] != exit[i]) {
            return false;
        }

    }

    return true;
}
