#include <stdio.h>
#include "show.h"

void show(Customer *customer, Command command) {

    if (customer->postalCode == -1) {
        printf("No customers found.\n");
        return;
    }

    printf("Here is the customers list :\n\n");

    printf("%-25s %-30s %-25s %-16s %-15s %-50s %-35s\n", "Name", "Surname", "City", "Postal code", "Phone", "Email", "Job");

    do {
        printf("%-25s %-30s %-25s %-16d %-15s %-50s %-35s\n",
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
