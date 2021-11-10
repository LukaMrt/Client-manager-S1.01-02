#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"

void load(Customer *customer, Command command) {

    char *fileName = "";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        char *a = reformatString(option.name);
        if (compareStrings(reformatString(option.name), "-file", 20) ||
            compareStrings(reformatString(option.name), "-f", 20)) {
            fileName = reformatString(option.value);
        }

    }

    if (strlen(fileName) == 0) {
        printf("Enter the file where customers are stored : ");
        fileName = scanString();
    }
    FILE *file = fopen(fileName, "r");

    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    Customer defaultCustomer = {
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            -1,
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            NULL
    };
    *customer = defaultCustomer;

    Customer *last = customer;

    while (!feof(file)) {

        char c;

        char name[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        char surname[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        char city[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        int postalCode = 0;
        char phone[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        char email[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
        char job[20] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";

        int i = 0;
        while ((c = fgetc(file)) != ',') {
            if (i < 19) {
                name[i++] = c;
            }
        }

        i = 0;
        while ((c = fgetc(file)) != ',') {
            if (i < 19) {
                surname[i++] = c;
            }
        }

        i = 0;
        while ((c = fgetc(file)) != ',') {
            if (i < 19) {
                city[i++] = c;
            }
        }

        while ((c = fgetc(file)) != ',') {
            postalCode *= 10;
            postalCode += (int) c;
        }

        i = 0;
        while ((c = fgetc(file)) != ',') {
            if (i < 19) {
                phone[i++] = c;
            }
        }

        i = 0;
        while ((c = fgetc(file)) != ',') {
            if (i < 19) {
                email[i++] = c;
            }
        }

        i = 0;
        c = fgetc(file);
        while (c != '\n' && c != '\0' && !feof(file)) {
            if (i < 19) {
                job[i++] = c;
            }
            c = fgetc(file);
        }

        Customer newCustomer = {
                .name = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .surname = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .city = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .postalCode = -1,
                .phone = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .email = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .job = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
                .next = NULL
        };

        if (last->postalCode == -1) {
            *last = newCustomer;

            strcpy(last->name, name);
            strcpy(last->surname, surname);
            strcpy(last->city, city);
            last->postalCode = postalCode;
            strcpy(last->phone, phone);
            strcpy(last->email, email);
            strcpy(last->job, job);

            continue;
        }

        last->next = (Customer *) malloc(sizeof(Customer));
        *(last->next) = newCustomer;

        strcpy(last->next->name, name);
        strcpy(last->next->surname, surname);
        strcpy(last->next->city, city);
        last->next->postalCode = postalCode;
        strcpy(last->next->phone, phone);
        strcpy(last->next->email, email);
        strcpy(last->next->job, job);
        last = last->next;
    }


    printf("Customers successfully loaded.\n");
    fclose(file);
}
