#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "add.h"

void format(char name[20]);

void add(Customer *customer, Command command) {
    char name[20], surname[20], city[20], phone[20], email[20], job[20];
    int postalCode;

    printf("Enter the name of the new customer to add : ");
    fgets(name, 20, stdin);

    printf("Enter the surname of the new customer : ");
    fgets(surname, 20, stdin);

    printf("Enter the city of the new customer : ");
    fgets(city, 20, stdin);

    printf("Enter the postal code of the new customer : ");
    scanf("%d", &postalCode); // TODO : check if the postal code is valid
    getchar();

    printf("Enter the phone number of the new customer : ");
    fgets(phone, 20, stdin);

    printf("Enter the email of the new customer : ");
    fgets(email, 20, stdin);

    printf("Enter the job of the new customer : ");
    fgets(job, 20, stdin);

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

    format(name);
    format(surname);
    format(city);
    format(phone);
    format(email);
    format(job);

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

void format(char name[20]) {

    for (int i = 0; i < 20; ++i) {
        if (name[i] == '\n') {
            name[i] = '\0';
        }
    }

}
