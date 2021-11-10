#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../data.h"
#include "../commands.h"
#include "delete.h"

bool compareStrings(const char name[20], const char name1[20]);

void delete(Customer *customer, Command command) {

    char name[20];
    printf("Enter the name of the customer to delete : ");
    fgets(name, 20, stdin);

    Customer *current = customer;
    Customer *before = customer;
    Customer *after;

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

bool compareStrings(const char name[20], const char name1[20]) {

    int i;
    for (i = 0; i < 20 && name1[i] != '\n'; ++i) {
        if (name[i] != name1[i]) {
            return false;
        }
    }

    return true;
}
