#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "sort.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

void sort(Customer *customer, Command command) {

    Customer* head = &(*customer);

    char sortField[15] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(cleanString(option.name), "-field", 6) ||
            compareStrings(cleanString(option.name), "-f", 3)) {
            copyString(sortField, option.value, 15);
        }

    }

    while (strlen(sortField) == 0) {
        printf("Enter field to sort by: ");
        fgets(sortField, 15, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    formatString(sortField, 15);
    cleanString(sortField);

    if (compareStrings(sortField, "name", 6)) {
        mergeSort(&head, &compareNames);
    }

    if (compareStrings(sortField, "surname", 7)) {
        mergeSort(&head, &compareSurnames);
    }

    if (compareStrings(sortField, "city", 5)) {
        mergeSort(&head, &compareCities);
    }

    if (compareStrings(sortField, "postalCode", 11)
        || compareStrings(sortField, "postal", 7)
        || compareStrings(sortField, "postal_code", 12)) {

        mergeSort(&head, &comparePostalCodes);
    }

    if (compareStrings(sortField, "phone", 6)) {
        mergeSort(&head, &comparePhones);
    }

    if (compareStrings(sortField, "email", 6)) {
        mergeSort(&head, &compareEmails);
    }

    if (compareStrings(sortField, "job", 4)) {
        mergeSort(&head, &compareJobs);
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

void mergeSort(Customer **customer, int (*fieldComparator)(Customer *, Customer *)) {

    Customer *head = *customer;
    Customer *start;
    Customer *end;

    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    split(head, &start, &end);

    mergeSort(&start, fieldComparator);
    mergeSort(&end, fieldComparator);

    *customer = merge(start, end, fieldComparator);
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

Customer *merge(Customer *start, Customer *end, int (*fieldComparator)(Customer *, Customer *)) {

    if (start == NULL) {
        return end;
    }

    if (end == NULL) {
        return start;
    }

    if (fieldComparator(start, end) <= 0) {
        start->next = merge(start->next, end, fieldComparator);
        return start;
    }

    end->next = merge(start, end->next, fieldComparator);
    return end;
}
