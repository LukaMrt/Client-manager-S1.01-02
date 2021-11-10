#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../data.h"
#include "../commands.h"
#include "delete.h"

bool compareStrings(const char name[20], const char name1[20]);

void delete(Customer *customer, Command command) {

    char name[20];
    int i, n = 0;
    printf("Enter the name of the customer to delete : ");
    fgets(name, 20, stdin);

    Customer *next = customer;
    Customer *before = customer;
    Customer *now;
    Customer *after;
    Customer *last1;
    Customer *last;

    while (!compareStrings(next->name, name) && next->next != NULL && next->postalCode != -1) {
        if (before != next) {
            before = before->next;
        }
        next = next->next;
    }

    if (!compareStrings(next->name, name) && next->next == NULL) {
        printf("Customer not found.\n");
        return;
    }

    now = next;
    after = next->next;
    while (next->next != NULL && next->postalCode != -1) {
        next = next->next;
        n += 1;
    }

    last = next;
    next = now;
    for (i = 0; i < n - 1; i++) {
        next = next->next;
    }
    last1 = next;

    if (last == now) {
        last1 = before;
    }

    before->next = last;
    last->next = after;
    last1->next = NULL;

    if (last1 == now) {
        last->next = NULL;
    }

    if (now == customer) {
        *customer = *last;
    }

    if (before == last) {
        Customer newCustomer = {
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                -1,
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                NULL
        };
        *customer = newCustomer;
    }

    printf("Customer successfully deleted.\n");
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
