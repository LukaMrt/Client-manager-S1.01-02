/* In charge : NAUDTS Angelo */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "add.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Adds new Customer to list.
 * @param customer head of customers list.
 * @param command command to execute.
 */
void add(Customer *customer, Command command) {

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

    while (strlen(name) == 0) {
        printf("Enter the name of the new customer to add : ");
        fgets(name, NAME_SIZE, stdin);
        removeNewLineCharacters(name);
        fseek(stdin, 0, SEEK_END);
    }

    while (strlen(surname) == 0) {
        printf("Enter the surname of the new customer : ");
        fgets(surname, SURNAME_SIZE, stdin);
        removeNewLineCharacters(surname);
        fseek(stdin, 0, SEEK_END);
    }

    while (strlen(city) == 0) {
        printf("Enter the city of the new customer : ");
        fgets(city, CITY_SIZE, stdin);
        removeNewLineCharacters(city);
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

    while (strlen(email) == 0) {
        printf("Enter the email of the new customer : ");
        fgets(email, EMAIL_SIZE, stdin);
        removeNewLineCharacters(email);
        fseek(stdin, 0, SEEK_END);
    }

    while (strlen(job) == 0) {
        printf("Enter the job of the new customer : ");
        fgets(job, JOB_SIZE, stdin);
        removeNewLineCharacters(job);
        fseek(stdin, 0, SEEK_END);
    }

    toUpperCase(city);
    removeNewLineCharacters(name);
    removeNewLineCharacters(surname);
    removeNewLineCharacters(city);
    removeNewLineCharacters(phone);
    removeNewLineCharacters(email);
    removeNewLineCharacters(job);

    Customer *newCustomer = (Customer *) malloc(sizeof(Customer));
    createCustomer(newCustomer);

    strcpy(newCustomer->name, name);
    strcpy(newCustomer->surname, surname);
    strcpy(newCustomer->city, city);
    newCustomer->postalCode = postalCode;
    strcpy(newCustomer->phone, phone);
    strcpy(newCustomer->email, email);
    strcpy(newCustomer->job, job);
    newCustomer->next = NULL;

    if (customer->postalCode != -1) {
        newCustomer->next = (Customer *) malloc(sizeof(Customer));
        *newCustomer->next = *customer;
    }

    *customer = *newCustomer;

    printf("Customer has been added successfully\n");
}
