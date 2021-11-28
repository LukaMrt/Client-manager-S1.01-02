#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "sort.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

void sort(Customer *customer, Command command) {

    Customer* head = customer;

    char sortField[15] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    bool revert = false;

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(removeNullCharacters(option.name), "-field") ||
            compareStrings(removeNullCharacters(option.name), "-f")) {
            copyString(sortField, option.value, 15);
        }

        if (compareStrings(removeNullCharacters(option.name), "-revert") ||
            compareStrings(removeNullCharacters(option.name), "-r")) {
            revert = true;
        }

    }

    while (strlen(sortField) == 0) {
        printf("Enter field to sort by: ");
        fgets(sortField, 15, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    removeNewLineCharacters(sortField);
    removeNullCharacters(sortField);

    if (compareStrings(sortField, "name")) {
        mergeSort(&head, &compareNames, revert);
    }

    if (compareStrings(sortField, "surname")) {
        mergeSort(&head, &compareSurnames, revert);
    }

    if (compareStrings(sortField, "city")) {
        mergeSort(&head, &compareCities, revert);
    }

    if (compareStrings(sortField, "postalCode")
        || compareStrings(sortField, "postal")
        || compareStrings(sortField, "postal_code")) {

        mergeSort(&head, &comparePostalCodes, revert);
    }

    if (compareStrings(sortField, "phone")) {
        mergeSort(&head, &comparePhones, revert);
    }

    if (compareStrings(sortField, "email")) {
        mergeSort(&head, &compareEmails, revert);
    }

    if (compareStrings(sortField, "job")) {
        mergeSort(&head, &compareJobs, revert);
    }

    Customer* temp = head;

    while (temp != customer && temp->next != customer) {
        temp = temp->next;
    }

    if (customer != head) {
        temp->next = (Customer *) malloc(sizeof(Customer));
        Customer newCustomer = createCustomer();

        copyString(newCustomer.name, customer->name, NAME_SIZE);
        copyString(newCustomer.surname, customer->surname, SURNAME_SIZE);
        copyString(newCustomer.city, customer->city, CITY_SIZE);
        newCustomer.postalCode = customer->postalCode;
        copyString(newCustomer.phone, customer->phone, PHONE_SIZE);
        copyString(newCustomer.email, customer->email, EMAIL_SIZE);
        copyString(newCustomer.job, customer->job, JOB_SIZE);
        newCustomer.next = customer->next;

        *(temp->next) = newCustomer;
        *customer = *head;
    }

    printf("Customers list sorted successfully by %s.\n", sortField);
}

void mergeSort(Customer **customer, int (*fieldComparator)(Customer *, Customer *), bool revert) {

    Customer *head = *customer;
    Customer *start;
    Customer *end;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    split(head, &start, &end);

    mergeSort(&start, fieldComparator, revert);
    mergeSort(&end, fieldComparator, revert);

    *customer = merge(start, end, fieldComparator, revert);
}

void split(Customer *source, Customer **start, Customer **end) {

    Customer *fast;
    Customer *slow;
    slow = source;
    fast = source->next;

    while (fast != NULL) {
        fast = fast->next;

        if (fast == NULL) {
            continue;
        }

        slow = slow->next;
        fast = fast->next;
    }

    *start = source;
    *end = slow->next;
    slow->next = NULL;
}

Customer *merge(Customer *start, Customer *end, int (*fieldComparator)(Customer *, Customer *), bool revert) {

    if (start == NULL) {
        return end;
    }

    if (end == NULL) {
        return start;
    }

    if ((revert ? fieldComparator(end, start) : fieldComparator(start, end)) <= 0) {
        start->next = merge(start->next, end, fieldComparator, revert);
        return start;
    }

    end->next = merge(start, end->next, fieldComparator, revert);
    return end;
}
