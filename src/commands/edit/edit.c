/* In charge : MARET Luka */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Edits a customer's data.
 * @param customer customer to edit.
 * @param command command to execute.
 */
void edit(Customer *customer, Command command) {

    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char city[CITY_SIZE];
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    char job[JOB_SIZE];
    int postalCode = 0;

    char searchName[NAME_SIZE];
    char searchSurname[SURNAME_SIZE];
    char searchCity[CITY_SIZE];
    char searchPostalCode[6];
    char searchPhone[PHONE_SIZE];
    char searchEmail[EMAIL_SIZE];
    char searchJob[JOB_SIZE];

    createEmptyString(name, NAME_SIZE);
    createEmptyString(surname, SURNAME_SIZE);
    createEmptyString(city, CITY_SIZE);
    createEmptyString(phone, PHONE_SIZE);
    createEmptyString(email, EMAIL_SIZE);
    createEmptyString(job, JOB_SIZE);

    createEmptyString(searchName, NAME_SIZE);
    createEmptyString(searchSurname, SURNAME_SIZE);
    createEmptyString(searchCity, CITY_SIZE);
    createEmptyString(searchPostalCode, 6);
    createEmptyString(searchPhone, PHONE_SIZE);
    createEmptyString(searchEmail, EMAIL_SIZE);
    createEmptyString(searchJob, JOB_SIZE);

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

        if (compareStrings(removeNullCharacters(option.name), "-sname")
            || compareStrings(removeNullCharacters(option.name), "-sn")) {
            copyString(searchName, option.value, NAME_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-ssurname")
            || compareStrings(removeNullCharacters(option.name), "-ss")) {
            copyString(searchSurname, option.value, SURNAME_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-scity")
            || compareStrings(removeNullCharacters(option.name), "-sc")) {
            copyString(searchCity, option.value, CITY_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-spostal")
            || compareStrings(removeNullCharacters(option.name), "-spostalCode")
            || compareStrings(removeNullCharacters(option.name), "-spo")) {
            copyString(searchJob, option.value, 6);
        }

        if (compareStrings(removeNullCharacters(option.name), "-sphone")
            || compareStrings(removeNullCharacters(option.name), "-sph")) {
            copyString(searchPhone, option.value, PHONE_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-semail")
            || compareStrings(removeNullCharacters(option.name), "-se")) {
            copyString(searchEmail, option.value, EMAIL_SIZE);
        }

        if (compareStrings(removeNullCharacters(option.name), "-sjob")
            || compareStrings(removeNullCharacters(option.name), "-sj")) {
            copyString(searchJob, option.value, JOB_SIZE);
        }

    }

    if (strlen(name) == 0) {
        printf("Enter the new name of the customer (enter to keep current value) : ");
        fgets(name, NAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(name, "\n")) {
            name[0] = '\0';
        }
    }

    if (strlen(surname) == 0) {
        printf("Enter the new surname of the customer (enter to keep current value) : ");
        fgets(surname, SURNAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(surname, "\n")) {
            surname[0] = '\0';
        }
    }

    if (strlen(city) == 0) {
        printf("Enter the new city of the customer (enter to keep current value) : ");
        fgets(city, CITY_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(city, "\n")) {
            city[0] = '\0';
        }
    }

    while (postalCode < 10000 || 99999 < postalCode) {
        printf("Enter the new postal code of the customer (enter to keep current value) : ");
        char tmp[10];
        createEmptyString(tmp, 10);
        fgets(tmp, 10, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(tmp, "\n")) {
            postalCode = -1;
            break;
        }
        if (!isNotNumber(tmp)) {
            postalCode = atoi(tmp);
        }
    }

    while (strlen(phone) == 0 || !validPhoneNumber(phone)) {
        printf("Enter the new phone number of the customer (enter to keep current value) : ");
        fgets(phone, PHONE_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(phone, "\n")) {
            phone[0] = '\0';
            break;
        }
    }

    if (strlen(email) == 0) {
        printf("Enter the new email of the customer (enter to keep current value) : ");
        fgets(email, EMAIL_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(email, "\n")) {
            email[0] = '\0';
        }
    }

    if (strlen(job) == 0) {
        printf("Enter the new job of the customer (enter to keep current value) : ");
        fgets(job, JOB_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(job, "\n")) {
            job[0] = '\0';
        }
    }

    char newName[NAME_SIZE];
    char newSurname[SURNAME_SIZE];
    char newCity[CITY_SIZE];
    char newPhone[PHONE_SIZE];
    char newEmail[EMAIL_SIZE];
    char newJob[JOB_SIZE];
    int newPostalCode = 0;

    copyString(newName, name, NAME_SIZE);
    copyString(newSurname, surname, SURNAME_SIZE);
    copyString(newCity, city, CITY_SIZE);
    copyString(newPhone, phone, PHONE_SIZE);
    copyString(newEmail, email, EMAIL_SIZE);
    copyString(newJob, job, JOB_SIZE);

    Customer *current = customer;
    int i = 0;

    while (current != NULL && current->postalCode != -1) {

        if ((strlen(searchName) == 0 || matchName(current, searchName))
             && (strlen(searchSurname) == 0 || matchSurname(current, searchSurname))
             && (strlen(searchCity) == 0 || matchCity(current, searchCity))
             && (strlen(searchPhone) == 0 || matchPhone(current, searchPhone))
             && (strlen(searchEmail) == 0 || matchEmail(current, searchEmail))
             && (strlen(searchJob) == 0 || matchJob(current, searchJob))
             && (strlen(searchPostalCode) == 0 || matchPostalCode(current, searchPostalCode))) {

            i++;

            if (strlen(name) == 0) {
                copyString(newName, current->name, NAME_SIZE);
            }

            if (strlen(surname) == 0) {
                copyString(newSurname, current->surname, SURNAME_SIZE);
            }

            if (strlen(city) == 0) {
                copyString(newCity, current->city, CITY_SIZE);
            }

            if (strlen(phone) == 0) {
                copyString(newPhone, current->phone, PHONE_SIZE);
            }

            if (strlen(email) == 0) {
                copyString(newEmail, current->email, EMAIL_SIZE);
            }

            if (strlen(job) == 0) {
                copyString(newJob, current->job, JOB_SIZE);
            }

            if (postalCode == -1) {
                newPostalCode = current->postalCode;
            }

            toUpperCase(newCity);
            removeNewLineCharacters(newName);
            removeNewLineCharacters(newSurname);
            removeNewLineCharacters(newCity);
            removeNewLineCharacters(newPhone);
            removeNewLineCharacters(newEmail);
            removeNewLineCharacters(newJob);

            copyString(current->name, newName, NAME_SIZE);
            copyString(current->surname, newSurname, SURNAME_SIZE);
            copyString(current->city, newCity, CITY_SIZE);
            current->postalCode = newPostalCode;
            copyString(current->phone, newPhone, PHONE_SIZE);
            copyString(current->email, newEmail, EMAIL_SIZE);
            copyString(current->job, newJob, JOB_SIZE);
        }

        current = current->next;
    }

    if (i == 0) {
        printf("No customer found.\n");
        return;
    }

    printf("%d customers edited successfully.\n", i);
}