/* In charge : NAUDTS Angelo */

#include <stdio.h>

/**
 * Displays the help menu.
 */
void help() {

    printf("Here is the commands list with their options :\n");

    printf("\nCommand add : add a user to the customers list.\n");
    printf("\t-name, -n : specify the name of the customer to add.\n");
    printf("\t-surname, -s : specify the surname of the customer to add.\n");
    printf("\t-city, -c : specify the city of the customer to add.\n");
    printf("\t-postal, -postalCode, -po : specify the postal code of the customer to add.\n");
    printf("\t-phone, -ph : specify the phone of the customer to add.\n");
    printf("\t-email, -e : specify the email of the customer to add.\n");
    printf("\t-job, -j : specify the job of the customer to add.\n");

    printf("\nCommand delete : remove a user from the customers list (if you don't give any option, it will delete all customers).\n");
    printf("\t-field, -f : specify the field which will be used for the deletion.\n");
    printf("\t-value, -v : specify the value of the field used for the deletion.\n");

    printf("\nCommand edit : edit a user in the customers list.\n");
    printf("\t-id, -i : specify the id of the customer to edit (in the list displayed by show command).\n");
    printf("\t-name, -n : specify the new name of the customer.\n");
    printf("\t-surname, -s : specify the new surname of the customer.\n");
    printf("\t-city, -c : specify the new city of the customer.\n");
    printf("\t-postal, -postalCode, -po : specify the new postal code of the customer.\n");
    printf("\t-phone, -ph : specify the new phone of the customer.\n");
    printf("\t-email, -e : specify the new email of the customer.\n");
    printf("\t-job, -j : specify the new job of the customer.\n");

    printf("\nCommand filter : filter customers list by a specific field.\n");

    printf("\nCommand help : display the commands documentation\n");

    printf("\nCommand load : load customers list from a file.\n");
    printf("\t-file, -f : specify the path of the file from which customers will be loaded.\n");

    printf("\nCommand save : save customers list to a file.\n");
    printf("\t-file, -f : specify the path of the file in which customers will be saved.\n");

    printf("\nCommand search : search a specific customers from fields values.\n");

    printf("\nCommand show : display the list of the customers.\n");
    printf("\t-filter, -f : specify the field which will be used to filter the list before display it (without delete users from the list).\n");
    printf("\t-filter, -f : specify the field which will be used to sort the list before display it (without modify the list).\n");
    printf("\t-complete, -c : show only customers without missing data.\n");
    printf("\t-incomplete, -i : show only customers with missing data.\n");

    printf("\nCommand sort : sort customers list by a specific field.\n");

    printf("\nCommands exit, quit, stop, end, q : exit the program.\n");
}
