#ifndef CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
#define CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H

#include <stdbool.h>

void createCustomer(Customer *customer);

bool compareName(Customer *customer, char *value);

bool compareSurname(Customer *customer, char *value);

bool compareCity(Customer *customer, char *value);

bool comparePostalCode(Customer *customer, char *value);

bool comparePhone(Customer *customer, char *value);

bool compareEmail(Customer *customer, char *value);

bool compareJob(Customer *customer, char *value);

int compareNames(Customer *customer1, Customer *customer2);

int compareSurnames(Customer *customer1, Customer *customer2);

int compareCities(Customer *customer1, Customer *customer2);

int comparePostalCodes(Customer *customer1, Customer *customer2);

int comparePhones(Customer *customer1, Customer *customer2);

int compareEmails(Customer *customer1, Customer *customer2);

int compareJobs(Customer *customer1, Customer *customer2);

bool matchName(Customer *customer, char *stringRegex);

bool matchSurname(Customer *customer, char *regex);

bool matchCity(Customer *customer, char *stringRegex);

bool matchPostalCode(Customer *customer, char *stringRegex);

bool matchPhone(Customer *customer, char *stringRegex);

bool matchEmail(Customer *customer, char *stringRegex);

bool matchJob(Customer *customer, char *stringRegex);

bool hasMissingData(const Customer *current);

#endif //CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
