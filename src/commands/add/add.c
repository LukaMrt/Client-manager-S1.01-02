#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "add.h"
#include "../../utils/utils.h"

void format(char *name, int size);

void add(Customer *customer, Command command) {
    char name[25], surname[30], city[25], phone[15], email[50], job[35];
    int postalCode;

    printf("Enter the name of the new customer to add : ");
    fgets(name, 25, stdin);

    printf("Enter the surname of the new customer : ");
    fgets(surname, 30, stdin);

    printf("Enter the city of the new customer : ");
    fgets(city, 25, stdin);

    printf("Enter the postal code of the new customer : ");
    scanf("%d", &postalCode); // TODO : check if the postal code is valid
    getchar();

    printf("Enter the phone number of the new customer : ");
    fgets(phone, 15, stdin);

    printf("Enter the email of the new customer : ");
    fgets(email, 50, stdin);

    printf("Enter the job of the new customer : ");
    fgets(job, 35, stdin);

    Customer newCustomer = createCustomer();

    format(name, 25);
    format(surname, 30);
    format(city, 25);
    format(phone, 15);
    format(email, 50);
    format(job, 35);

    if (customer->postalCode == -1) {
        *customer = newCustomer;

        strcpy(customer->name, name);
        strcpy(customer->surname, surname);
        strcpy(customer->city, city);
        customer->postalCode = postalCode;
        strcpy(customer->phone, phone);
        strcpy(customer->email, email);
        strcpy(customer->job, job);

        printf("Customer has been added successfully\n");
        return;
    }


    Customer *next = customer;

    while (next->next != NULL) {
        next = next->next;
    }

    next->next = (Customer *) malloc(sizeof(Customer));
    *(next->next) = newCustomer;

    strcpy(next->next->name, name);
    strcpy(next->next->surname, surname);
    strcpy(next->next->city, city);
    next->next->postalCode = postalCode;
    strcpy(next->next->phone, phone);
    strcpy(next->next->email, email);
    strcpy(next->next->job, job);
    printf("Customer has been added successfully\n");
}

void format(char *name, int size) {

    for (int i = 0; i < size; ++i) {
        if (name[i] == '\n') {
            name[i] = '\0';
        }
    }

}
