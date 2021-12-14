/* In charge : NAUDTS Angelo */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "delete.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Deletes a customer from the list.
 * @param customer customer to delete.
 * @param command command to execute.
 */
void delete(Customer *customer, Command command) {
    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char city[CITY_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    char job[JOB_SIZE];
    char postalCode[6];

    createEmptyString(name, NAME_SIZE);
    createEmptyString(surname, SURNAME_SIZE);
    createEmptyString(city, CITY_SIZE);
    createEmptyString(phone, PHONE_SIZE);
    createEmptyString(email, EMAIL_SIZE);
    createEmptyString(job, JOB_SIZE);
    createEmptyString(postalCode, 6);

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
            copyString(postalCode, option.value, 6);
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
    Customer *before = customer;
    Customer *after;
    int i = 0;

    while (current != NULL && current->postalCode != -1) {

        if ((strlen(name) == 0 || matchName(current, name))
            && (strlen(surname) == 0 || matchSurname(current, surname))
            && (strlen(city) == 0 || matchCity(current, city))
            && (strlen(phone) == 0 || matchPhone(current, phone))
            && (strlen(email) == 0 || matchEmail(current, email))
            && (strlen(job) == 0 || matchJob(current, job))
            && (strlen(postalCode) == 0 || matchPostalCode(current, postalCode))) {
            after = current->next;
            before->next = after;
            ++i;

            if (before == current) {

                if (after == NULL) {
                    after = (Customer *) malloc(sizeof(Customer));
                    createCustomer(after);
                }

                *customer = *after;
            }

            current = before;
        }

        if (before != current) {
            before = before->next;
        }
        current = current->next;
    }

    if (i == 0) {
        printf("No customer found.\n");
        return;
    }

    printf("%d customers deleted successfully.\n", i);
}
