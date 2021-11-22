#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"

void edit(Customer *customer, Command command) {

    int id = -1;
    char name[NAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char surname[SURNAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char city[CITY_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char phone[PHONE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char email[EMAIL_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char job[JOB_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int postalCode = 0;

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(cleanString(option.name), "-id", 4)
            || compareStrings(cleanString(option.name), "-i", 3)) {
            id = atoi(option.value);
        }

        if (compareStrings(cleanString(option.name), "-name", 6)
            || compareStrings(cleanString(option.name), "-n", 3)) {
            copyString(name, option.value, NAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-surname", 9)
            || compareStrings(cleanString(option.name), "-s", 3)) {
            copyString(surname, option.value, SURNAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-city", 6)
            || compareStrings(cleanString(option.name), "-c", 3)) {
            copyString(city, option.value, CITY_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-postal", 8)
            || compareStrings(cleanString(option.name), "-postalCode", 12)
            || compareStrings(cleanString(option.name), "-po", 4)) {
            postalCode = atoi(option.value);
        }

        if (compareStrings(cleanString(option.name), "-phone", 7)
            || compareStrings(cleanString(option.name), "-ph", 4)) {
            copyString(phone, option.value, PHONE_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-email", 7)
            || compareStrings(cleanString(option.name), "-e", 3)) {
            copyString(email, option.value, EMAIL_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-job", 5)
            || compareStrings(cleanString(option.name), "-j", 3)) {
            copyString(job, option.value, JOB_SIZE);
        }

    }

    while (id < 0) {
        printf("Enter the id of the customer to edit : ");
        scanf("%d", &id);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(name) == 0) {
        printf("Enter the name of the new customer to add : ");
        fgets(name, NAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(surname) == 0) {
        printf("Enter the surname of the new customer : ");
        fgets(surname, SURNAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(city) == 0) {
        printf("Enter the city of the new customer : ");
        fgets(city, CITY_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    while (postalCode < 10000 || 99999 < postalCode) {
        printf("Enter the postal code of the new customer : ");
        scanf("%d", &postalCode);
        fseek(stdin, 0, SEEK_END);
    }

    while (strlen(phone) == 0 || !validPhoneNumber(phone)) {
        printf("Enter the phone number of the new customer : ");
        fgets(phone, PHONE_SIZE, stdin);
        formatString(phone, 15);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(email) == 0) {
        printf("Enter the email of the new customer : ");
        fgets(email, EMAIL_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(job) == 0) {
        printf("Enter the job of the new customer : ");
        fgets(job, JOB_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    --id;
    Customer *current = customer;

    for (; 0 < id; --id) {

        if (current->next == NULL) {
            printf("Customer not found.\n");
            return;
        }

        current = current->next;
    }

    toUpperCase(city);
    formatString(name, NAME_SIZE);
    formatString(surname, SURNAME_SIZE);
    formatString(city, CITY_SIZE);
    formatString(phone, PHONE_SIZE);
    formatString(email, EMAIL_SIZE);
    formatString(job, JOB_SIZE);

    copyString(current->name, name, NAME_SIZE);
    copyString(current->surname, surname, SURNAME_SIZE);
    copyString(current->city, city, CITY_SIZE);
    current->postalCode = postalCode;
    copyString(current->phone, phone, PHONE_SIZE);
    copyString(current->email, email, EMAIL_SIZE);
    copyString(current->job, job, JOB_SIZE);
    printf("Customer edited successfully.\n");
}
