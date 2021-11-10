#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../data.h"
#include "../commands.h"
#include "delete.h"
#include "../../utils/utils.h"

void delete(Customer *customer, Command command) {

    char name[20];
    printf("Enter the name of the customer to delete : ");
    fgets(name, 20, stdin);

    Customer *current = customer;
    Customer *before = customer;
    Customer *after;

    while (!compareStrings(current->name, name, 20) && current->next != NULL && current->postalCode != -1) {
        if (before != current) {
            before = before->next;
        }
        current = current->next;
    }

    if (!compareStrings(current->name, name, 20)) {
        printf("Customer not found.\n");
        return;
    }

    after = current->next;
    before->next = after;

    Customer newCustomer = {
            .name = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .surname = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .city = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .postalCode = -1,
            .phone = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .email = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .job = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            .next = NULL
    };

    if (after == NULL) {
        after = &newCustomer;
    }

    if (before == current) {
        *customer = *after;
    }

    printf("Customer deleted successfully.\n");
}
