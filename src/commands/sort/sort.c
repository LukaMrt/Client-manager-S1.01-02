#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "sort.h"
#include "../../utils/utils.h"
#include "../../utils/customersUtils.h"

/**
 * Sorts the customers by the given field.
 * @param customer head of the customers list.
 * @param command command to be executed.
 */
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
        createCustomer(temp->next);
        temp = temp->next;

        copyString(temp->name, customer->name, NAME_SIZE);
        copyString(temp->surname, customer->surname, SURNAME_SIZE);
        copyString(temp->city, customer->city, CITY_SIZE);
        temp->postalCode = customer->postalCode;
        copyString(temp->phone, customer->phone, PHONE_SIZE);
        copyString(temp->email, customer->email, EMAIL_SIZE);
        copyString(temp->job, customer->job, JOB_SIZE);
        temp->next = customer->next;

        *customer = *head;
    }

    printf("Customers list sorted successfully by %s.\n", sortField);
}

/**
 * Sorts the customers by the given comparator.
 * @param customer head of the customers list.
 * @param fieldComparator comparator to be used.
 * @param revert true if the list should be reverted.
 */
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

/**
 * Splits the given list into two lists.
 * @param source head of the list to be split.
 * @param start head of the first list.
 * @param end head of the second list.
 */
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

/**
 * Merges two lists into a sorted one.
 * @param start head of the first list.
 * @param end head of the second list.
 * @param fieldComparator comparator to be used.
 * @param revert true if the list should be reverted.
 * @return head of the merged list.
 */
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
