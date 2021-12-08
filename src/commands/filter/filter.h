#ifndef CLIENT_MANAGER_S1_01_02_FILTER_H
#define CLIENT_MANAGER_S1_01_02_FILTER_H

#include "../../data.h"
#include "../commands.h"

void filter(Customer *customer, Command command);

void filterList(Customer *customer, int (*fieldComparator)(Customer *, char *));

#endif //CLIENT_MANAGER_S1_01_02_FILTER_H
