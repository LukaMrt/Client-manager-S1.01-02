#include <stdio.h>
#include "show.h"

/**
 * Format postalCode from int to string.
 * @param postalCode string variable.
 * @param postalCodeInt original int variable.
 */
void formatPostalCode(char *postalCode, int postalCodeInt);

/**
 * Displays customers list.
 * @param customer head of the customers list.
 * @param command command to execute.
 */
void show(Customer *customer, Command command) {

    if (customer->postalCode == -1) {
        printf("No customer found.\n");
        return;
    }

    printf("Here is the customers list :\n\n");
    printf("      %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
           "Name",
           "Surname",
           "City",
           "Postal code",
           "Phone",
           "Email",
           "Job");

    int i = 1;
    
    do {

        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

        formatPostalCode(postalCode, customer->postalCode);

        printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
               i++,
               customer->name,
               customer->surname,
               customer->city,
               postalCode,
               customer->phone,
               customer->email,
               customer->job);

    } while ((customer = customer->next) != NULL);

}

void formatPostalCode(char *postalCode, int postalCodeInt) {
    
    if (postalCodeInt != 0) {
        sprintf(postalCode, "%d", postalCodeInt);
    }
    
}
