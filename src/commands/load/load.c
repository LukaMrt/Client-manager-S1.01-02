#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"
#include "load.h"
#include "../../utils/customersUtils.h"

bool shouldContinue(FILE *file, char *c);

/**
 * Loads customers from a file.
 * @param customer head of the customers list.
 * @param command command to execute.
 */
void load(Customer *customer, Command command) {

    char *fileName = "";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(removeNullCharacters(option.name), "-file") ||
            compareStrings(removeNullCharacters(option.name), "-f")) {
            fileName = removeNullCharacters(option.value);
        }

    }

    while (strlen(fileName) == 0) {
        printf("Enter the file where customers are stored : ");
        fileName = scanString();
    }
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    createCustomer(customer);

    Customer *last = customer;

    while (!feof(file)) {

        char c;

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
        int i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 24) {
                name[i++] = c;
            }
        }

        i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 29) {
                surname[i++] = c;
            }
        }

        i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 24) {
                city[i++] = c;
            }
        }

        while (shouldContinue(file, &c)) {
            postalCode *= 10;
            postalCode += atoi(&c);
        }

        i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 14) {
                phone[i++] = c;
            }
        }

        i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 49) {
                email[i++] = c;
            }
        }

        i = 0;
        while (shouldContinue(file, &c)) {
            if (i < 34) {
                job[i++] = c;
            }
        }

        if (name[0] == '\0'
            && surname[0] == '\0'
            && city[0] == '\0'
            && postalCode == 0
            && phone[0] == '\0'
            && email[0] == '\0'
            && job[0] == '\0') {
            continue;
        }


        if (last->postalCode == -1) {
            strcpy(last->name, name);
            strcpy(last->surname, surname);
            strcpy(last->city, city);
            last->postalCode = postalCode;
            strcpy(last->phone, phone);
            strcpy(last->email, email);
            strcpy(last->job, job);

            continue;
        }

        last->next = (Customer *) malloc(sizeof(Customer));
        createCustomer(last->next);

        strcpy(last->next->name, name);
        strcpy(last->next->surname, surname);
        strcpy(last->next->city, city);
        last->next->postalCode = postalCode;
        strcpy(last->next->phone, phone);
        strcpy(last->next->email, email);
        strcpy(last->next->job, job);
        last = last->next;
    }


    printf("Customers successfully loaded.\n");
    fclose(file);
}

/**
 * Checks if the file is at the end of the file.
 * @param file file to check.
 * @param c character to check.
 * @return false if the file is at the end of the file, true otherwise.
 */
bool shouldContinue(FILE *file, char *c) {
    *c = fgetc(file);
    return *c != ',' && !feof(file) && *c != '\0' && *c != '\n';
}
