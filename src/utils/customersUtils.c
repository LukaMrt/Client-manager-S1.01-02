#include <stdlib.h>
#include <string.h>
#include "../data.h"
#include "customersUtils.h"
#include "utils.h"

/**
 * Compares customer name with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareName(Customer *customer, char *value) {
    return compareStrings(customer->name, value, NAME_SIZE);
}

/**
 * Compares customer surname with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareSurname(Customer *customer, char *value) {
    return compareStrings(customer->surname, value, SURNAME_SIZE);
}

/**
 * Compares customer city with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareCity(Customer *customer, char *value) {
    return compareStrings(customer->city, value, CITY_SIZE);
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
    return compareStrings(customer->phone, value, PHONE_SIZE);
}

/**
 * Compares customer email with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareEmail(Customer *customer, char *value) {
    return compareStrings(customer->email, value, EMAIL_SIZE);
}

/**
 * Compares customer job with value.
 * @param customer customer to compare.
 * @param value value to compare.
 * @return
 */
bool compareJob(Customer *customer, char *value) {
    return compareStrings(customer->job, value, JOB_SIZE);
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
 * Check if customer has missing data.
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
