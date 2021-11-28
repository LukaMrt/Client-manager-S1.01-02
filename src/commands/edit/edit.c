#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"

void edit(Customer *customer, Command command) {

    int id = -1;
    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char city[CITY_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    char job[JOB_SIZE];
    int postalCode = 0;

    createEmptyString(name, NAME_SIZE);
    createEmptyString(surname, SURNAME_SIZE);
    createEmptyString(city, CITY_SIZE);
    createEmptyString(phone, PHONE_SIZE);
    createEmptyString(email, EMAIL_SIZE);
    createEmptyString(job, JOB_SIZE);

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(removeNullCharacters(option.name), "-id")
            || compareStrings(removeNullCharacters(option.name), "-i")) {
            id = atoi(option.value);
        }

        if (compareStrings(removeNullCharacters(option.name), "-name")
            || compareStrings(removeNullCharacters(option.name), "-n")) {
            copyString(name, option.value, NAME_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-surname")
            || compareStrings(removeNullCharacters(option.name), "-s")) {
            copyString(surname, option.value, SURNAME_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-city")
            || compareStrings(removeNullCharacters(option.name), "-c")) {
            copyString(city, option.value, CITY_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-postal")
            || compareStrings(removeNullCharacters(option.name), "-postalCode")
            || compareStrings(removeNullCharacters(option.name), "-po")) {
            postalCode = atoi(option.value);
        }

        if (compareStrings(removeNullCharacters(option.name), "-phone")
            || compareStrings(removeNullCharacters(option.name), "-ph")) {
            copyString(phone, option.value, PHONE_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-email")
            || compareStrings(removeNullCharacters(option.name), "-e")) {
            copyString(email, option.value, EMAIL_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-job")
            || compareStrings(removeNullCharacters(option.name), "-j")) {
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
        removeNewLineCharacters(phone);
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
    removeNewLineCharacters(name);
    removeNewLineCharacters(surname);
    removeNewLineCharacters(city);
    removeNewLineCharacters(phone);
    removeNewLineCharacters(email);
    removeNewLineCharacters(job);

    copyString(current->name, name, NAME_SIZE);
    copyString(current->surname, surname, SURNAME_SIZE);
    copyString(current->city, city, CITY_SIZE);
    current->postalCode = postalCode;
    copyString(current->phone, phone, PHONE_SIZE);
    copyString(current->email, email, EMAIL_SIZE);
    copyString(current->job, job, JOB_SIZE);
    printf("Customer edited successfully.\n");
}
