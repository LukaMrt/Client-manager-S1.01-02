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

        if (compareStrings(removeNullCharacters(option.name), "-file") ||
            compareStrings(removeNullCharacters(option.name), "-f")) {
            fileName = removeNullCharacters(option.value);
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
                removeNullCharacters(current->name),
                removeNullCharacters(current->surname),
                removeNullCharacters(current->city),
                current->postalCode,
                removeNullCharacters(current->phone),
                removeNullCharacters(current->email),
                removeNullCharacters(current->job));

        current = current->next;
    }

    fclose(file);
    printf("Customers list successfully saved in file %s.\n", fileName);
}
