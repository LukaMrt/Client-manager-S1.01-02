#ifndef CLIENT_MANAGER_S1_01_02_SHOW_H
#define CLIENT_MANAGER_S1_01_02_SHOW_H

#include "../commands.h"
#include <stdbool.h>

void show(Customer *customer, Command command);

void filterOption(Customer *customer, char *filterField, char *value);

void sortOption(Customer *customer, char *sortField, bool revert);

void showList(Customer *customer, char *word);

void showFilter(Customer *customer, char *value, bool (*fieldComparator)(Customer *, char *));

void showSort(Customer *customer, int (*fieldComparator)(Customer *, Customer *), bool revert);

void showIncomplete(Customer *customer);

void showComplete(Customer *customer);

#endif //CLIENT_MANAGER_S1_01_02_SHOW_H
