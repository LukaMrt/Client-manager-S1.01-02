#ifndef CLIENT_MANAGER_S1_01_02_SHOW_H
#define CLIENT_MANAGER_S1_01_02_SHOW_H

#include "../commands.h"
#include <stdbool.h>

void show(Customer *customer, Command command);

void showList(Customer *customer, char *word);

void showFilter(Customer *customer, char *value, bool (*fieldComparator)(Customer *, char *));

#endif //CLIENT_MANAGER_S1_01_02_SHOW_H
