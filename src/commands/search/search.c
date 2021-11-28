#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "../../data.h"
#include "../commands.h"
#include "search.h"
#include "../../utils/utils.h"

void search(Customer *customer, Command command) {

    char category[15] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char jobc[35] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char namec[25] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char surnamec[30] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char cityc[25] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char phonec[15] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    char mailc[50] = "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
    int postal;
    bool a = true;

    Customer *current = customer;
    printf("Enter the name of the category: ");
    scanf("%s", category);
    getchar();

    if (compareStrings(category, "name")) {
        printf("Enter the name :");
        scanf("%s", namec);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->name, namec)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("Name not found");
        }
    }

    if (compareStrings(category, "surname")) {
        printf("Enter the surname : ");
        scanf("%s", surnamec);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->surname, surnamec)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("Surname not found");
        }
    }

    if (compareStrings(category, "city")) {
        printf("Enter the city : ");
        scanf("%s", cityc);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->city, cityc)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("City not found");
        }
    }

    if (compareStrings(category, "postal_code")
        || compareStrings(category, "postal")
        || compareStrings(category, "postalCode")) {

        printf("Enter the postal code : ");
        scanf("%d", &postal);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL && current->postalCode != -1) {

            if (current->postalCode == postal) {

                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }

                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }

            current = current->next;
        }

        if (a) {
            printf("Postal Code not found");
        }
    }

    if (compareStrings(category, "phone")) {
        printf("Enter the phone : ");
        scanf("%s", phonec);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->phone, phonec)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("City not found");
        }
    }

    if (compareStrings(category, "email")) {
        printf("Enter the city : ");
        scanf("%s", mailc);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->email, mailc)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("City not found");
        }
    }

    if (compareStrings(category, "job")) {
        printf("Enter the job: ");
        scanf("%s", jobc);
        getchar();
        char postalCode[13] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";

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
        while (current != NULL) {
            if (compareStrings(current->job, jobc)) {
                a = false;
                if (current->postalCode != 0) {
                    sprintf(postalCode, "%d", current->postalCode);
                }
                printf("%-5d %-25s %-30s %-25s %-13s %-16s %-50s %-35s\n",
                       i++,
                       current->name,
                       current->surname,
                       current->city,
                       postalCode,
                       current->phone,
                       current->email,
                       current->job);
            }
            current = current->next;
        }

        if (a) {
            printf("Job not found");
        }
    }

}