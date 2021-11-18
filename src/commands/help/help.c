#include <stdio.h>
#include "../../data.h"
#include "../commands.h"

void help(Customer *customer, Command command) {

    printf("Here is the commands list with their options :\n");

    printf("\nCommand add : add a user to the customers list.\n");
    printf("\t-name, -n : specify the name of the customer to add.\n");
    printf("\t-surname, -s : specify the surname of the customer to add.\n");
    printf("\t-city, -c : specify the city of the customer to add.\n");
    printf("\t-postal, -postalCode, -po : specify the postal code of the customer to add.\n");
    printf("\t-phone, -ph : specify the phone of the customer to add.\n");
    printf("\t-email, -e : specify the email of the customer to add.\n");
    printf("\t-job, -j : specify the job of the customer to add.\n");

    printf("\nCommand delete : remove a user from the customers list (if you don't give any option, remove will be done with name field).\n");
    printf("\t-field, -f : specify the field which will be used for the deletion.\n");
    printf("\t-value, -v : specify the value of the field used for the deletion.\n");

    printf("\nCommand edit : edit a user in the customers list.\n");

    printf("\nCommand filter : filter customers list by a specific field.\n");

    printf("\nCommand help : display the commands documentation\n");

    printf("\nCommand load : load customers list from a file.\n");
    printf("\t-file, -f : specify the path of the file from which customers will be loaded.\n");

    printf("\nCommand save : save customers list to a file.\n");
    printf("\t-file, -f : specify the path of the file in which customers will be saved.\n");

    printf("\nCommand search : search a specific customers from fields values.\n");

    printf("\nCommand show : display the list of the customers.\n");
    printf("\t-filter, -f : specify the field which will be used to filter the list before display it (without delete users from the list).\n");

    printf("\nCommand sort : sort customers list by a specific field.\n");

    printf("\nCommands exit, quit, stop, end, q : exit the program.\n");

}
