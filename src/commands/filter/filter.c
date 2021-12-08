#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "filter.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Filters the customers by the given parameters.
 * @param customer head list of customers.
 * @param command command to execute.
 */
void filter(Customer *customer, Command command) {

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

    Customer *current = customer;
    Customer *copyCurrent = (Customer *) malloc(sizeof(Customer));
    createCustomer(copyCurrent);
    Customer *copy = copyCurrent;

    while (current != NULL) {

        char stringPostalCode[6];
        sprintf(stringPostalCode, "%d", current->postalCode);

        if (strlen(name) != 0 && !matchName(current, name)
            || strlen(surname) != 0 && !matchSurname(current, surname)
            || strlen(city) != 0 && !matchCity(current, city)
            || strlen(phone) != 0 && !matchPhone(current, phone)
            || strlen(email) != 0 && !matchEmail(current, email)
            || strlen(job) != 0 && !matchJob(current, job)
            || postalCode != 0 && !matchPostalCode(current, stringPostalCode)) {

            current = current->next;
            continue;
        }

        copyString(copyCurrent->name, current->name, NAME_SIZE);
        copyString(copyCurrent->surname, current->surname, SURNAME_SIZE);
        copyString(copyCurrent->city, current->city, CITY_SIZE);
        copyCurrent->postalCode = current->postalCode;
        copyString(copyCurrent->phone, current->phone, PHONE_SIZE);
        copyString(copyCurrent->email, current->email, EMAIL_SIZE);
        copyString(copyCurrent->job, current->job, JOB_SIZE);
        copyCurrent->next = (Customer *) malloc(sizeof(Customer));
        copyCurrent = copyCurrent->next;
        createCustomer(copyCurrent);
        current = current->next;
    }

    *customer = *copy;
    printf("Customer list successfully filtered.\n");
}
