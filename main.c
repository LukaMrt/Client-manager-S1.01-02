#include <stdio.h>
#include "src/commands/commands.h"
#include "src/utils/utils.h"

/**
 * Entry point of application
 * Retrieves commands from user
 * @return 0
 */
int main() {

    printf("  ~~~ Client manager ~~~ \n");

    char *entry;
    Customer customer = createCustomer();

    do {

        printf("\n => Enter a command : ");
        entry = scanString();
        executeCommand(entry, &customer);

    } while (!compareStrings(entry, "exit", 20)
             && !compareStrings(entry, "quit", 20)
             && !compareStrings(entry, "stop", 20)
             && !compareStrings(entry, "end", 20)
             && !compareStrings(entry, "q", 20));

    printf("  ~~~ Client manager ~~~ \n");

    return 0;
}
