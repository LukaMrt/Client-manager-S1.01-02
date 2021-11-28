#include <stdio.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "delete.h"
#include "../../utils/utils.h"

/**
 * Deletes a customer from the list.
 * @param customer customer to delete.
 * @param command command to execute.
 */
void delete(Customer *customer, Command command) {

    char name[20];
    printf("Enter the name of the customer to delete : ");
    fgets(name, 20, stdin);

    Customer *current = customer;
    Customer *before = customer;
    Customer *after;

    // TODO : select by id or by all fields

    while (!compareStrings(current->name, name) && current->next != NULL && current->postalCode != -1) {
        if (before != current) {
            before = before->next;
        }
        current = current->next;
    }

    if (!compareStrings(current->name, name)) {
        printf("Customer not found.\n");
        return;
    }

    after = current->next;
    before->next = after;

    Customer newCustomer = createCustomer();

    if (after == NULL) {
        after = &newCustomer;
    }

    if (before == current) {
        *customer = *after;
    }

    printf("Customer deleted successfully.\n");
}
