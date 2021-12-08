#include <stdlib.h>
#include <string.h>
#include "regex/regex.h"
#include <stdio.h>
#include "../data.h"
#include "customersUtils.h"
#include "utils.h"

/**
 * Creates a new Customer with empty fields.
 * @return default Customer.
 */
void createCustomer(Customer *customer) {

    createEmptyString(customer->name, NAME_SIZE);
    createEmptyString(customer->surname, SURNAME_SIZE);
    createEmptyString(customer->city, CITY_SIZE);
    customer->postalCode = -1;
    createEmptyString(customer->phone, PHONE_SIZE);
    createEmptyString(customer->email, EMAIL_SIZE);
    createEmptyString(customer->job, JOB_SIZE);
}

/**
 * Compares customer name with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareName(Customer *customer, char *value) {
    return compareStrings(customer->name, value);
}

/**
 * Compares customer surname with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareSurname(Customer *customer, char *value) {
    return compareStrings(customer->surname, value);
}

/**
 * Compares customer city with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareCity(Customer *customer, char *value) {
    return compareStrings(customer->city, value);
}

/**
 * Compares customer postal code with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool comparePostalCode(Customer *customer, char *value) {
    return customer->postalCode == atoi(value);
}

/**
 * Compares customer phone with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool comparePhone(Customer *customer, char *value) {
    return compareStrings(customer->phone, value);
}

/**
 * Compares customer email with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareEmail(Customer *customer, char *value) {
    return compareStrings(customer->email, value);
}

/**
 * Compares customer job with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareJob(Customer *customer, char *value) {
    return compareStrings(customer->job, value);
}

// TODO: change doc

/**
 * Compares customer name with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int compareNames(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->name, customer2->name);
}

/**
 * Compares customer surname with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int compareSurnames(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->surname, customer2->surname);
}

/**
 * Compares customer city with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int compareCities(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->city, customer2->city);
}

/**
 * Compares customer postal code with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int comparePostalCodes(Customer *customer1, Customer *customer2) {
    return customer1->postalCode > customer2->postalCode;
}

/**
 * Compares customer phone with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int comparePhones(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->phone, customer2->phone);
}

/**
 * Compares customer email with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int compareEmails(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->email, customer2->email);
}

/**
 * Compares customer job with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
int compareJobs(Customer *customer1, Customer *customer2) {
    return strcmp(customer1->job, customer2->job);
}

/**
 * Checks if customer name match with regex.
 * @param customer customer to check.
 * @return true if match, false otherwise.
 */
bool matchName(Customer *customer, char *regex) {
    int length = NAME_SIZE;
    return re_match(regex, customer->name, &length) != -1;
}

/**
 * Checks if customer surname match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchSurname(Customer *customer, char *regex) {
    int length = SURNAME_SIZE;
    return re_match(regex, customer->surname, &length) != -1;
}

/**
 *   Checks if customer city match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchCity(Customer *customer, char *regex) {
    int length = CITY_SIZE;
    return re_match(regex, customer->city, &length) != -1;
}

/**
 * Checks if customer postal code match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchPostalCode(Customer *customer, char *regex) {
    char stringPostalCode[6];
    sprintf(stringPostalCode, "%d", customer->postalCode);
    int length = 6;
    return re_match(regex, stringPostalCode, &length) != -1;
}

/**
 * Checks if customer phone match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchPhone(Customer *customer, char *regex) {
    int length = PHONE_SIZE;
    return re_match(regex, customer->phone, &length) != -1;
}

/**
 * Checks if customer email match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchEmail(Customer *customer, char *regex) {
    int length = EMAIL_SIZE;
    return re_match(regex, customer->email, &length) != -1;
}

/**
 * Checks if customer job match with regex.
 * @param customer customer to compare.
 * @return true if match, false otherwise.
 */
bool matchJob(Customer *customer, char *regex) {
    int length = JOB_SIZE;
    return re_match(regex, customer->phone, &length) != -1;
}

/**
 * Checks if customer has missing data.
 * @param current customer to check.
 * @return true if customer has missing data, false otherwise.
 */
bool hasMissingData(const Customer *current) {
    return strlen(current->name) == 0
           || strlen(current->surname) == 0
           || strlen(current->city) == 0
           || current->postalCode == 0
           || strlen(current->phone) == 0
           || strlen(current->email) == 0
           || strlen(current->job) == 0;
}
