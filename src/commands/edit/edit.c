#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"

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
    char searchPhone[PHONE_SIZE];
    char searchEmail[EMAIL_SIZE];
    char searchJob[JOB_SIZE];
    int searchPostalCode = 0;

    createEmptyString(name, NAME_SIZE);
    createEmptyString(surname, SURNAME_SIZE);
    createEmptyString(city, CITY_SIZE);
    createEmptyString(phone, PHONE_SIZE);
    createEmptyString(email, EMAIL_SIZE);
    createEmptyString(job, JOB_SIZE);

    createEmptyString(searchName, NAME_SIZE);
    createEmptyString(searchSurname, SURNAME_SIZE);
    createEmptyString(searchCity, CITY_SIZE);
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
            searchPostalCode = atoi(option.value);
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

    Customer *current = customer;

    while (current != NULL
           && current->postalCode != -1
           && (strlen(searchName) != 0 && !compareStrings(current->name, searchName)
               || strlen(searchSurname) != 0 && !compareStrings(current->surname, searchSurname)
               || strlen(searchCity) != 0 && !compareStrings(current->city, searchCity)
               || strlen(searchPhone) != 0 && !compareStrings(current->phone, searchPhone)
               || strlen(searchEmail) != 0 && !compareStrings(current->email, searchEmail)
               || strlen(searchJob) != 0 && !compareStrings(current->job, searchJob)
               || searchPostalCode != 0 && current->postalCode != postalCode)) {
        current = current->next;
    }

    if (current == NULL || current->postalCode == -1) {
        printf("Customer not found.\n");
        return;
    }

    if (strlen(name) == 0) {
        printf("Enter the name of the new customer to add (enter to keep current value) : ");
        fgets(name, NAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(name, "\n")) {
            copyString(name, current->name, NAME_SIZE);
        }
    }

    if (strlen(surname) == 0) {
        printf("Enter the surname of the new customer (enter to keep current value) : ");
        fgets(surname, SURNAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(surname, "\n")) {
            copyString(surname, current->surname, SURNAME_SIZE);
        }
    }

    if (strlen(city) == 0) {
        printf("Enter the city of the new customer (enter to keep current value) : ");
        fgets(city, CITY_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(city, "\n")) {
            copyString(city, current->city, CITY_SIZE);
        }
    }

    while (postalCode < 10000 || 99999 < postalCode) {
        printf("Enter the postal code of the new customer (enter to keep current value) : ");
        char tmp[10];
        createEmptyString(tmp, 10);
        fgets(tmp, 10, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(tmp, "\n")) {
            postalCode = current->postalCode;
            break;
        }
        postalCode = atoi(tmp); // TODO : check if postalCode is a number
    }

    while (strlen(phone) == 0 || !validPhoneNumber(phone)) {
        printf("Enter the phone number of the new customer (enter to keep current value) : ");
        fgets(phone, PHONE_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(phone, "\n")) {
            copyString(phone, current->phone, PHONE_SIZE);
        }
    }

    if (strlen(email) == 0) {
        printf("Enter the email of the new customer (enter to keep current value) : ");
        fgets(email, EMAIL_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(email, "\n")) {
            copyString(email, current->email, EMAIL_SIZE);
        }
    }

    if (strlen(job) == 0) {
        printf("Enter the job of the new customer (enter to keep current value) : ");
        fgets(job, JOB_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
        if (compareStrings(job, "\n")) {
            copyString(job, current->job, JOB_SIZE);
        }
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