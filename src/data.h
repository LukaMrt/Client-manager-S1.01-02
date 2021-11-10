#ifndef CLIENT_MANAGER_S1_01_02_DATA_H
#define CLIENT_MANAGER_S1_01_02_DATA_H

typedef struct customer Customer;

struct customer {
    char name[25];
    char surname[30];
    char city[25];
    int postalCode;
    char phone[15];
    char email[50];
    char job[35];
    Customer *next;
};

#endif //CLIENT_MANAGER_S1_01_02_DATA_H
