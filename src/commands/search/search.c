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

    if (compareStrings(category, "name", 4)) {
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
            if (compareStrings(current->name, namec, 25)) {
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

    if (compareStrings(category, "surname", 8)) {
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
            if (compareStrings(current->surname, surnamec, 30)) {
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

    if (compareStrings(category, "city", 5)) {
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
            if (compareStrings(current->city, cityc, 25)) {
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

    if (compareStrings(category, "postal_code", 12)
        || compareStrings(category, "postal", 7)
        || compareStrings(category, "postalCode", 11)) {

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

    if (compareStrings(category, "phone", 6)) {
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
            if (compareStrings(current->phone, phonec, 15)) {
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

    if (compareStrings(category, "email", 6)) {
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
            if (compareStrings(current->email, mailc, 50)) {
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

    if (compareStrings(category, "job", 4)) {
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
            if (compareStrings(current->job, jobc, 35)) {
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