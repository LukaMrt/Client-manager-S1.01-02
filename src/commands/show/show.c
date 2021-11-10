#include <stdio.h>
#include "show.h"

void show(Customer *customer, Command command) {

    if (customer->postalCode == -1) {
        printf("No customers found.\n");
        return;
    }

    printf("Here is the customers list :\n\n");

    printf("%-19s %-19s %-19s %-19s %-19s %-19s %-19s\n", "Name", "Surname", "City", "Postal code", "Phone", "Email", "Job");

    do {
        printf("%-19s %-19s %-19s %-19d %-19s %-19s %-19s\n",
               customer->name,
               customer->surname,
               customer->city,
               customer->postalCode,
               customer->phone,
               customer->email,
               customer->job);

        customer = customer->next;
    } while (customer != NULL);

}
