#ifndef CLIENT_MANAGER_S1_01_02_SORT_H
#define CLIENT_MANAGER_S1_01_02_SORT_H

#include <stdbool.h>

void sort(Customer *customer, Command command);

void mergeSort(Customer **customer, int (*fieldComparator)(Customer *, Customer *));

Customer* merge(Customer* start, Customer* end, int (*fieldComparator)(Customer *, Customer *));

void split(Customer* source, Customer** start, Customer** end);

#endif //CLIENT_MANAGER_S1_01_02_SORT_H
