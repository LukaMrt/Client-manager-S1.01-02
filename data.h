//
// Created by Luka Maret on 27/10/2021.
//

#ifndef CLIENT_MANAGER_S1_01_02_DATA_H
#define CLIENT_MANAGER_S1_01_02_DATA_H

typedef struct customer {
    bool valid;
    char *surname;
    char *name;
    char *city;
    int postal_code;
    char *phone;
    char *email;
    char *job;
} Customer;

#endif //CLIENT_MANAGER_S1_01_02_DATA_H
