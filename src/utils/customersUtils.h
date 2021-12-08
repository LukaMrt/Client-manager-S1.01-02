#ifndef CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
#define CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H

#include <stdbool.h>

void createCustomer(Customer *customer);

int compareNames(Customer *customer1, Customer *customer2);

int compareSurnames(Customer *customer1, Customer *customer2);

int compareCities(Customer *customer1, Customer *customer2);

int comparePostalCodes(Customer *customer1, Customer *customer2);

int comparePhones(Customer *customer1, Customer *customer2);

int compareEmails(Customer *customer1, Customer *customer2);

int compareJobs(Customer *customer1, Customer *customer2);

bool matchName(Customer *customer, char *regex);

bool matchSurname(Customer *customer, char *regex);

bool matchCity(Customer *customer, char *regex);

bool matchPostalCode(Customer *customer, char *regex);

bool matchPhone(Customer *customer, char *regex);

bool matchEmail(Customer *customer, char *regex);

bool matchJob(Customer *customer, char *regex);

bool hasMissingData(const Customer *customer);

#endif //CLIENT_MANAGER_S1_01_02_CUSTOMERSUTILS_H
