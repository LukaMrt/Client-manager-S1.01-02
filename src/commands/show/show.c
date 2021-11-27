#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "show.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Execute show command and display a customers list.
 * Displayed customers list can change with command options.
 * @param customer head of the customers list.
 * @param command command to execute.
 */
void show(Customer *customer, Command command) {

    char *filterField = "";
    char *filterValue = "";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(cleanString(option.name), "-field", 7) ||
            compareStrings(cleanString(option.name), "-f", 3)) {
            filterField = cleanString(option.value);
        }

        if (compareStrings(cleanString(option.name), "-value", 7) ||
            compareStrings(cleanString(option.name), "-v", 3)) {
            filterValue = cleanString(option.value);
        }

        if (compareStrings(cleanString(option.name), "-incomplete", 12) ||
            compareStrings(cleanString(option.name), "-i", 3)) {
            showIncomplete(customer);
            return;
        }

        if (compareStrings(cleanString(option.name), "-complete", 10) ||
            compareStrings(cleanString(option.name), "-c", 3)) {
            showComplete(customer);
            return;
        }

    }

    if (strlen(filterField) == 0) {
        showList(customer, "Here is the customers list :\n\n");
        return;
    }

    while (strlen(filterValue) == 0) {
        printf("Enter the value of the field %s for the fitler : ", filterField);
        filterValue = scanString();
    }

    if (compareStrings(filterField, "name", 6)) {
        showFilter(customer, filterValue, &compareName);
        return;
    }

    if (compareStrings(filterField, "surname", 7)) {
        showFilter(customer, filterValue, &compareSurname);
        return;
    }

    if (compareStrings(filterField, "city", 5)) {
        showFilter(customer, filterValue, &compareCity);
        return;
    }

    if (compareStrings(filterField, "postalCode", 11)
        || compareStrings(filterField, "postal", 7)
        || compareStrings(filterField, "postal_code", 12)) {

        while (isNotNumber(filterValue)) {
            printf("Enter the value of the field postalCode for the filter : ");
            filterValue = scanString();
        }

        showFilter(customer, filterValue, &comparePostalCode);
        return;
    }

    if (compareStrings(filterField, "phone", 6)) {
        showFilter(customer, filterValue, &comparePhone);
        return;
    }

    if (compareStrings(filterField, "email", 6)) {
        showFilter(customer, filterValue, &compareEmail);
        return;
    }

    if (compareStrings(filterField, "job", 4)) {
        showFilter(customer, filterValue, &compareJob);
        return;
    }

    printf("Le champs %s n'existe pas.", filterField);
}

/**
 * Format phoneNumber from int to string.
 * @param phoneNumber string variable.
 * @param phoneNumberInt original int variable.
 */
void showList(Customer *customer, char *sentence) {

    if (customer == NULL || customer->postalCode == -1) {
        printf("No customer found.\n");
        return;
    }

    printf("%s", sentence);
    printf("%-6s %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
           "",
           "Name",
           "Surname",
           "City",
           "Postal code",
           "Phone",
           "Email",
           "Job");

    int i = 1;

    do {

        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

        if (customer->postalCode != 0) {
            sprintf(postalCode, "%d", customer->postalCode);
        }

        printf("%-6d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
               i++,
               customer->name,
               customer->surname,
               customer->city,
               postalCode,
               customer->phone,
               customer->email,
               customer->job);

    } while ((customer = customer->next) != NULL && customer->postalCode != -1);

}

/**
 * Filter customers matching with given field.
 * @param customer head of the customers list.
 * @param value value to filter.
 * @param fieldComparator function which compare customer's field and value.
 */
void showFilter(Customer *customer, char *value, bool (*fieldComparator)(Customer *, char *)) {

    if (customer == NULL || customer->postalCode == -1) {
        showList(customer, "");
        return;
    }

    Customer *current = customer;
    Customer copy = createCustomer();
    Customer *copyCurrent = &copy;

    do {

        if (!fieldComparator(current, value)) {
            continue;
        }

        Customer newCustomer = createCustomer();
        copyCurrent->next = (Customer *) malloc(sizeof(Customer));
        *(copyCurrent->next) = newCustomer;
        strcpy(copyCurrent->name, current->name);
        strcpy(copyCurrent->surname, current->surname);
        strcpy(copyCurrent->city, current->city);
        copyCurrent->postalCode = current->postalCode;
        strcpy(copyCurrent->phone, current->phone);
        strcpy(copyCurrent->email, current->email);
        strcpy(copyCurrent->job, current->job);
        copyCurrent = copyCurrent->next;

    } while ((current = current->next) != NULL && current->postalCode != -1);

    showList(&copy, "Here is the filtered customers list :\n\n");
}

/**
 * Filter customers with missing value.
 * @param customer head of the customers list.
 */
void showIncomplete(Customer *customer) {

    int a = 0;
    int b = 0;

    if (customer == NULL || customer->postalCode == -1) {
        showList(customer, "");
        return;
    }

    Customer *current = customer;
    Customer copy = createCustomer();
    Customer *copyCurrent = &copy;

    do {

        ++b;

        if (!hasMissingData(current)) {
            continue;
        }

        ++a;

        Customer newCustomer = createCustomer();
        copyCurrent->next = (Customer *) malloc(sizeof(Customer));
        *(copyCurrent->next) = newCustomer;
        strcpy(copyCurrent->name, current->name);
        strcpy(copyCurrent->surname, current->surname);
        strcpy(copyCurrent->city, current->city);
        copyCurrent->postalCode = current->postalCode;
        strcpy(copyCurrent->phone, current->phone);
        strcpy(copyCurrent->email, current->email);
        strcpy(copyCurrent->job, current->job);
        copyCurrent = copyCurrent->next;

    } while ((current = current->next) != NULL && current->postalCode != -1);

    printf("%d customers have missing data (%.2f%%).\n", a, roundf((float)(a) * 10000 / (float)(b)) / 100);
    showList(&copy, "Here is the list of customers with missing values :\n\n");
}

/**
 * Filter customers without missing value.
 * @param customer head of the customers list.
 */
void showComplete(Customer *customer) {

    int a = 0;
    int b = 0;

    if (customer == NULL || customer->postalCode == -1) {
        showList(customer, "");
        return;
    }

    Customer *current = customer;
    Customer copy = createCustomer();
    Customer *copyCurrent = &copy;

    do {

        ++b;

        if (hasMissingData(current)) {
            continue;
        }

        ++a;

        Customer newCustomer = createCustomer();
        copyCurrent->next = (Customer *) malloc(sizeof(Customer));
        *(copyCurrent->next) = newCustomer;
        strcpy(copyCurrent->name, current->name);
        strcpy(copyCurrent->surname, current->surname);
        strcpy(copyCurrent->city, current->city);
        copyCurrent->postalCode = current->postalCode;
        strcpy(copyCurrent->phone, current->phone);
        strcpy(copyCurrent->email, current->email);
        strcpy(copyCurrent->job, current->job);
        copyCurrent = copyCurrent->next;

    } while ((current = current->next) != NULL && current->postalCode != -1);

    printf("%d customers have no missing data (%.2f%%).\n", a, roundf((float)(a) * 10000 / (float)(b)) / 100);
    showList(&copy, "Here is the list of customers without missing values :\n\n");
}
