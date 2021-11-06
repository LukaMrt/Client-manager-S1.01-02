#ifndef CLIENT_MANAGER_S1_01_02_DATA_H
#define CLIENT_MANAGER_S1_01_02_DATA_H

typedef struct customer Customer;

struct customer {
    char name[20];
    char surname[20];
    char city[20];
    int postalCode;
    char phone[20];
    char email[20];
    char job[20];
    Customer *next;
};

#endif //CLIENT_MANAGER_S1_01_02_DATA_H
