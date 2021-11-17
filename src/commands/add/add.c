#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../../data.h"
#include "../commands.h"
#include "add.h"
#include "../../utils/utils.h"

bool validPhoneNumber(char phone[15]);

/**
 * Adds new Customer to list.
 * @param customer head of customers list.
 * @param command command to execute.
 */
void add(Customer *customer, Command command) {
    char name[NAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char surname[SURNAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char city[CITY_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char phone[PHONE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char email[EMAIL_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char job[JOB_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int postalCode = 0;

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(cleanString(option.name), "-name", 50) ||
            compareStrings(cleanString(option.name), "-n", 50)) {
            copyString(name, option.value, NAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-surname", 50) ||
            compareStrings(cleanString(option.name), "-s", 50)) {
            copyString(surname, option.value, SURNAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-city", 50) ||
            compareStrings(cleanString(option.name), "-c", 50)) {
            copyString(city, option.value, CITY_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-postal", 50) ||
            compareStrings(cleanString(option.name), "-po", 50)) {
            postalCode = atoi(option.value);
        }

        if (compareStrings(cleanString(option.name), "-phone", 50) ||
            compareStrings(cleanString(option.name), "-ph", 50)) {
            copyString(phone, option.value, PHONE_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-email", 50) ||
            compareStrings(cleanString(option.name), "-e", 50)) {
            copyString(email, option.value, EMAIL_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-job", 50) ||
            compareStrings(cleanString(option.name), "-j", 50)) {
            copyString(job, option.value, JOB_SIZE);
        }

    }

    if (strlen(name) == 0) {
        printf("Enter the name of the new customer to add : ");
        fgets(name, NAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(surname) == 0) {
        printf("Enter the surname of the new customer : ");
        fgets(surname, SURNAME_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(city) == 0) {
        printf("Enter the city of the new customer : ");
        fgets(city, CITY_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    while (postalCode < 10000 || 99999 < postalCode) {
        printf("Enter the postal code of the new customer : ");
        scanf("%d", &postalCode);
        fseek(stdin, 0, SEEK_END);
    }

    while (strlen(phone) == 0 || !validPhoneNumber(phone)) {
        printf("Enter the phone number of the new customer : ");
        fgets(phone, PHONE_SIZE, stdin);
        formatString(phone, 15);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(email) == 0) {
        printf("Enter the email of the new customer : ");
        fgets(email, EMAIL_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    if (strlen(job) == 0) {
        printf("Enter the job of the new customer : ");
        fgets(job, JOB_SIZE, stdin);
        fseek(stdin, 0, SEEK_END);
    }

    Customer newCustomer = createCustomer();

    toUpperCase(city);
    formatString(name, NAME_SIZE);
    formatString(surname, SURNAME_SIZE);
    formatString(city, CITY_SIZE);
    formatString(phone, PHONE_SIZE);
    formatString(email, EMAIL_SIZE);
    formatString(job, JOB_SIZE);

    Customer *current = customer;

    while (current->postalCode != -1 && current->next != NULL) {
        current = current->next;
    }

    if (customer->postalCode != -1) {
        current->next = (Customer *) malloc(sizeof(Customer));
        *(current->next) = newCustomer;
        current = current->next;
    }

    strcpy(current->name, name);
    strcpy(current->surname, surname);
    strcpy(current->city, city);
    current->postalCode = postalCode;
    strcpy(current->phone, phone);
    strcpy(current->email, email);
    strcpy(current->job, job);
    printf("Customer has been added successfully\n");
}

bool validPhoneNumber(char phone[15]) {

    return isdigit(phone[0])
           && isdigit(phone[1])
           && phone[2] == '.'
           && isdigit(phone[3])
           && isdigit(phone[4])
           && phone[5] == '.'
           && isdigit(phone[6])
           && isdigit(phone[7])
           && phone[8] == '.'
           && isdigit(phone[9])
           && isdigit(phone[10])
           && phone[11] == '.'
           && isdigit(phone[12])
           && isdigit(phone[13])
           && phone[14] == '\0';
}
