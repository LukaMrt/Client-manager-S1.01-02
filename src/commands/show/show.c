#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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

        if (compareStrings(reformatString(option.name), "-filterField", 50) ||
            compareStrings(reformatString(option.name), "-f", 50)) {
            filterField = reformatString(option.value);
        }

        if (compareStrings(reformatString(option.name), "-filterValue", 50) ||
            compareStrings(reformatString(option.name), "-v", 50)) {
            filterValue = reformatString(option.value);
        }

    }

    if (strlen(filterField) == 0) {
        showList(customer, "");
        return;
    }

    while (strlen(filterValue) == 0) {
        printf("Enter the filterValue of the field %s for the filterField : ", filterField);
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
            printf("Enter the filterValue of the field postalCode for the filterField : ");
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
void showList(Customer *customer, char *word) {

    if (customer == NULL || customer->postalCode == -1) {
        printf("No customer found.\n");
        return;
    }

    printf("Here is the %s customers list :\n\n", word);
    printf("%-5s %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
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

        printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
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

    showList(&copy, "filtered");
}
