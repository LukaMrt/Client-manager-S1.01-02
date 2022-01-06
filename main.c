/* In charge : NAUDTS Angelo */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "src/commands/commands.h"
#include "src/utils/utils.h"
#include "src/utils/customersUtils.h"

long timeDifference(struct timespec *start, struct timespec *end);

/**
 * Entry point of application
 * Retrieves commands from user
 * @return 0
 */
int main() {

    printf("  ~~~ Customers manager ~~~ \n");

    char *entry;
    Customer *customer = (Customer *) malloc(sizeof(Customer));
    createCustomer(customer);
    struct timespec startTime;
    struct timespec endTime;

    do {

        printf("\n => Enter a command (help for help) : ");
        entry = scanString();

        clock_gettime(CLOCK_REALTIME, &startTime);
        executeCommand(entry, customer);
        clock_gettime(CLOCK_REALTIME, &endTime);

        printf("Last operation's time : %lds %ldms %ldns\n",
               timeDifference(&startTime, &endTime) / 1000000,
               timeDifference(&startTime, &endTime) % 1000000 / 1000,
               timeDifference(&startTime, &endTime) % 1000);

    } while (!compareStrings(entry, "exit")
             && !compareStrings(entry, "quit")
             && !compareStrings(entry, "stop")
             && !compareStrings(entry, "end")
             && !compareStrings(entry, "q"));

    printf("\n  ~~~ Customers manager ~~~ \n");

    return 0;
}

/**
 * Computes the time difference between two times
 * @param start the start time
 * @param end the end time
 * @return the time difference in nanoseconds
 */
long timeDifference(struct timespec *start, struct timespec *end) {
    long startTime = start->tv_sec * 1000000 + start->tv_nsec / 1000;
    long endTime = end->tv_sec * 1000000 + end->tv_nsec / 1000;
    return endTime - startTime;
}
