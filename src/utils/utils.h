#ifndef CLIENT_MANAGER_S1_01_02_UTILS_H
#define CLIENT_MANAGER_S1_01_02_UTILS_H

#include <stdbool.h>
#include "../data.h"

char *scanString();

char *reformatString(const char *entry);

void format(char *entry, int size);

bool compareStrings(const char *name, const char *name1, int size);

Customer createCustomer();

bool isNotNumber(char *entry);

#endif //CLIENT_MANAGER_S1_01_02_UTILS_H
