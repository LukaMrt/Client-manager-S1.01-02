#include <stdio.h>
#include <string.h>
#include "../../data.h"
#include "../commands.h"
#include "../../utils/utils.h"
#include "save.h"

/**
 * Saves customers into a file.
 * @param customer head of the customers list.
 * @param command command to execute.
 */
void save(Customer *customer, Command command) {

    char *fileName = "";

    for (int i = 0; i < command.optionsCount; ++i) {
        Option option = command.options[i];

        if (compareStrings(reformatString(option.name), "-file", 50) ||
            compareStrings(reformatString(option.name), "-f", 50)) {
            fileName = reformatString(option.value);
        }

    }

    if (strlen(fileName) == 0) {
        printf("Enter the file where customers will be saved :");
        fileName = scanString();
    }
    FILE *file = fopen(fileName, "w");

    if (file == NULL) {
        printf("File not found.\n");
        return;
    }

    Customer *current = customer;
    while (current != NULL && current->postalCode != -1) {

        fprintf(file, "%s,%s,%s,%d,%s,%s,%s\n",
                reformatString(current->name),
                reformatString(current->surname),
                reformatString(current->city),
                current->postalCode,
                reformatString(current->phone),
                reformatString(current->email),
                reformatString(current->job));

        current = current->next;
    }

    fclose(file);
    printf("Customers list successfully saved in file %s.\n", fileName);
}
