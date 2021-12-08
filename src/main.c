#include <stdio.h>
#include <stdlib.h>
#include "commands/commands.h"
#include "utils/utils.h"
#include "utils/customersUtils.h"

/**
 * Entry point of application
 * Retrieves commands from user
 * @return 0
 */
int main() {

    printf("  ~~~ Customers manager ~~~ \n");

    char *entry;
    Customer *customer = (Customer *) malloc(sizeof(Customer));
    createCustomer(customer);

    do {

        printf("\n => Enter a command : ");
        entry = scanString();
        executeCommand(entry, customer);

    } while (!compareStrings(entry, "exit")
             && !compareStrings(entry, "quit")
             && !compareStrings(entry, "stop")
             && !compareStrings(entry, "end")
             && !compareStrings(entry, "q"));

    printf("  ~~~ Customers manager ~~~ \n");

    return 0;
}
