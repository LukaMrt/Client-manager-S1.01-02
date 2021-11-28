#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "show.h"
#include "../sort/sort.h"
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
    char *sortField = "";
    char *value = "";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(removeNullCharacters(option.name), "-filter", 8) ||
            compareStrings(removeNullCharacters(option.name), "-f", 3)) {
            filterField = removeNullCharacters(option.value);
        }

        if (compareStrings(removeNullCharacters(option.name), "-sort", 6) ||
            compareStrings(removeNullCharacters(option.name), "-s", 3)) {
            sortField = removeNullCharacters(option.value);
        }

        if (compareStrings(removeNullCharacters(option.name), "-value", 7) ||
            compareStrings(removeNullCharacters(option.name), "-v", 3)) {
            value = removeNullCharacters(option.value);
        }

        if (compareStrings(removeNullCharacters(option.name), "-incomplete", 12) ||
            compareStrings(removeNullCharacters(option.name), "-i", 3)) {
            showIncomplete(customer);
            return;
        }

        if (compareStrings(removeNullCharacters(option.name), "-complete", 10) ||
            compareStrings(removeNullCharacters(option.name), "-c", 3)) {
            showComplete(customer);
            return;
        }

    }

    if (strlen(filterField) != 0) {
        filterOption(customer, filterField, value);
        return;
    }

    if (strlen(sortField) != 0) {
        sortOption(customer, sortField);
        return;
    }

    showList(customer, "Here is the customers list :\n\n");
}

/**
 * Display customers list filtered by a field.
 * @param customer head of the customers list.
 * @param filterField field to filter by.
 * @param value value to filter by.
 */
void filterOption(Customer *customer, char *filterField, char *value) {

    while (strlen(value) == 0) {
        printf("Enter the value of the field %s for the filter : ", filterField);
        value = scanString();
    }

    if (compareStrings(filterField, "name", 6)) {
        showFilter(customer, value, &compareName);
        return;
    }

    if (compareStrings(filterField, "surname", 7)) {
        showFilter(customer, value, &compareSurname);
        return;
    }

    if (compareStrings(filterField, "city", 5)) {
        showFilter(customer, value, &compareCity);
        return;
    }

    if (compareStrings(filterField, "postalCode", 11)
        || compareStrings(filterField, "postal", 7)
        || compareStrings(filterField, "postal_code", 12)) {

        while (isNotNumber(value)) {
            printf("Enter the value of the field postalCode for the filter : ");
            value = scanString();
        }

        showFilter(customer, value, &comparePostalCode);
        return;
    }

    if (compareStrings(filterField, "phone", 6)) {
        showFilter(customer, value, &comparePhone);
        return;
    }

    if (compareStrings(filterField, "email", 6)) {
        showFilter(customer, value, &compareEmail);
        return;
    }

    if (compareStrings(filterField, "job", 4)) {
        showFilter(customer, value, &compareJob);
        return;
    }

    printf("The field %s doesn't exist.\n", filterField);
}

/**
 * Display customers list sorted by a field.
 * @param customer head of the customers list.
 * @param sortField field to sort by.
 * @param value value to sort by.
 */
void sortOption(Customer *customer, char *sortField) {

    if (compareStrings(sortField, "name", 6)) {
        showSort(customer, &compareNames);
        return;
    }

    if (compareStrings(sortField, "surname", 7)) {
        showSort(customer, &compareSurnames);
        return;
    }

    if (compareStrings(sortField, "city", 5)) {
        showSort(customer, &compareCities);
        return;
    }

    if (compareStrings(sortField, "postalCode", 11)
        || compareStrings(sortField, "postal", 7)
        || compareStrings(sortField, "postal_code", 12)) {

        showSort(customer, &comparePostalCodes);
        return;
    }

    if (compareStrings(sortField, "phone", 6)) {
        showSort(customer, &comparePhones);
        return;
    }

    if (compareStrings(sortField, "email", 6)) {
        showSort(customer, &compareEmails);
        return;
    }

    if (compareStrings(sortField, "job", 4)) {
        showSort(customer, &compareJobs);
        return;
    }

    printf("The field %s doesn't exist.\n", sortField);
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
 * Sort customers by given field.
 * @param customer head of the customers list.
 * @param fieldComparator function which compare customers fields.
 */
void showSort(Customer *customer, int (*fieldComparator)(Customer *, Customer *)) {

    if (customer == NULL || customer->postalCode == -1) {
        showList(customer, "");
        return;
    }

    Customer *copy = (Customer *) malloc(sizeof(Customer));
    *copy = createCustomer();

    Customer *current = customer;
    Customer *copyCurrent = copy;

    do {

        copyString(copyCurrent->name, current->name, NAME_SIZE);
        copyString(copyCurrent->surname, current->surname, SURNAME_SIZE);
        copyString(copyCurrent->city, current->city, CITY_SIZE);
        copyCurrent->postalCode = current->postalCode;
        copyString(copyCurrent->phone, current->phone, PHONE_SIZE);
        copyString(copyCurrent->email, current->email, EMAIL_SIZE);
        copyString(copyCurrent->job, current->job, JOB_SIZE);

        if (current->next != NULL) {
            copyCurrent->next = (Customer *) malloc(sizeof(Customer));
            *(copyCurrent->next) = createCustomer();
            copyCurrent = copyCurrent->next;
        }

    } while ((current = current->next) != NULL && current->postalCode != -1);

    mergeSort(&copy, fieldComparator);

    showList(copy, "Here is the filtered customers list :\n\n");
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
