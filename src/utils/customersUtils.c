#include <stdlib.h>
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
