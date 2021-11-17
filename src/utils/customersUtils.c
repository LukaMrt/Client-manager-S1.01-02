#include <stdlib.h>
#include "../data.h"
#include "customersUtils.h"
#include "utils.h"

bool compareName(Customer *customer, char *value) {
    return compareStrings(customer->name, value, 30);
}

bool compareSurname(Customer *customer, char *value) {
    return compareStrings(customer->surname, value, 35);
}

bool compareCity(Customer *customer, char *value) {
    return compareStrings(customer->city, value, 25);
}

bool comparePostalCode(Customer *customer, char *value) {
    return customer->postalCode == atoi(value);
}

bool comparePhone(Customer *customer, char *value) {
    return compareStrings(customer->phone, value, 15);
}

bool compareEmail(Customer *customer, char *value) {
    return compareStrings(customer->email, value, 20);
}

bool compareJob(Customer *customer, char *value) {
    return compareStrings(customer->job, value, 35);
}
