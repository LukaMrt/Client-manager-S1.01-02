#include <stdio.h>
#include <stdlib.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"

void edit(Customer *customer, Command command) {

    char name[NAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char surname[SURNAME_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char city[CITY_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char phone[PHONE_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char email[EMAIL_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char job[JOB_SIZE] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int postalCode = 0;

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(cleanString(option.name), "-name", 6)
            || compareStrings(cleanString(option.name), "-n", 3)) {
            copyString(name, option.value, NAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-surname", 9)
            || compareStrings(cleanString(option.name), "-s", 3)) {
            copyString(surname, option.value, SURNAME_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-city", 6)
            || compareStrings(cleanString(option.name), "-c", 3)) {
            copyString(city, option.value, CITY_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-postal", 8)
            || compareStrings(cleanString(option.name), "-postalCode", 12)
            || compareStrings(cleanString(option.name), "-po", 4)) {
            postalCode = atoi(option.value);
        }

        if (compareStrings(cleanString(option.name), "-phone", 7)
            || compareStrings(cleanString(option.name), "-ph", 4)) {
            copyString(phone, option.value, PHONE_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-email", 7)
            || compareStrings(cleanString(option.name), "-e", 3)) {
            copyString(email, option.value, EMAIL_SIZE);
        }

        if (compareStrings(cleanString(option.name), "-job", 5)
            || compareStrings(cleanString(option.name), "-j", 3)) {
            copyString(job, option.value, JOB_SIZE);
        }

    }

}
