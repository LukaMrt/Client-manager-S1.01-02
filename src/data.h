#ifndef CLIENT_MANAGER_S1_01_02_DATA_H
#define CLIENT_MANAGER_S1_01_02_DATA_H

#define NAME_SIZE 25
#define SURNAME_SIZE 30
#define CITY_SIZE 25
#define PHONE_SIZE 15
#define EMAIL_SIZE 50
#define JOB_SIZE 35

/**
 * Customer data Class.
 */
typedef struct customer Customer;

struct customer {
    char name[NAME_SIZE];
    char surname[SURNAME_SIZE];
    char city[CITY_SIZE];
    int postalCode;
    char phone[PHONE_SIZE];
    char email[EMAIL_SIZE];
    char job[JOB_SIZE];
    Customer *next;
};

#endif //CLIENT_MANAGER_S1_01_02_DATA_H
