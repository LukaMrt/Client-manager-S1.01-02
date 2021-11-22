#ifndef CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
#define CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H

#include <stdbool.h>

bool compareName(Customer *customer, char *value);

bool compareSurname(Customer *customer, char *value);

bool compareCity(Customer *customer, char *value);

bool comparePostalCode(Customer *customer, char *value);

bool comparePhone(Customer *customer, char *value);

bool compareEmail(Customer *customer, char *value);

bool compareJob(Customer *customer, char *value);

bool hasMissingData(const Customer *current);

#endif //CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
