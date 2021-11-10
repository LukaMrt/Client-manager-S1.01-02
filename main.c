#include <stdio.h>
#include "src/commands/commands.h"
#include "src/utils/utils.h"

int main() {

    printf("  ~~~ Client manager ~~~ \n");

    char *entry;
    Customer customer = createCustomer();

    do {

        printf("\n => Enter a command : ");
        entry = scanString();
        executeCommand(entry, &customer);

    } while (!compareStrings(entry, "exit", 20));

    return 0;
}
