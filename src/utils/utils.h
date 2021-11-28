#ifndef CLIENT_MANAGER_S1_01_02_UTILS_H
#define CLIENT_MANAGER_S1_01_02_UTILS_H

#include <stdbool.h>
#include "../data.h"

char *scanString();

char *removeNullCharacters(const char *entry);

void removeNewLineCharacters(char *entry, int size);

void createEmptyString(char *entry, int size);

bool compareStrings(const char *name, const char *name1, int size);

void copyString(char *dest, const char *src, int size);

void toUpperCase(char *entry);

Customer createCustomer();

bool isNotNumber(char *entry);

bool validPhoneNumber(char phone[15]);

#endif //CLIENT_MANAGER_S1_01_02_UTILS_H
