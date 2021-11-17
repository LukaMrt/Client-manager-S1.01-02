#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "utils.h"

/**
 * Scans a string from console with unknown length.
 * @return scanned string.
 */
char *scanString() {
    size_t size = 10;
    size_t index = 0;
    char *entry;
    int entryChar;

    entry = realloc(NULL, size);
    if (!entry) {
        return entry;
    }

    while ((entryChar = fgetc(stdin)) != '\n') {
        entry[index++] = (char) entryChar;

        if (index == size) {
            entry = realloc(entry, size += 16);
            if (!entry) {
                return entry;
            }
        }

    }

    entry[index] = '\0';
    return entry;
}

/**
 * Remove null characters from a string.
 * @param entry string to be cleaned.
 * @return cleaned string.
 */
char *cleanString(const char *entry) {
    size_t size = 10;
    size_t index = 0;
    char *output;
    char entryChar;

    output = realloc(NULL, size);
    if (!output) {
        return output;
    }

    while ((entryChar = entry[index]) != '\0') {
        output[index++] = entryChar;

        if (index == size) {
            output = realloc(output, size += 16);
            if (!output) {
                return output;
            }
        }

    }

    output[index] = '\0';
    return output;
}

/**
 * Formats entry to remove new lines characters.
 * @param entry Entry to formatString.
 * @param size Size of entry.
 */
void formatString(char *entry, int size) {

    for (int i = 0; i < size; ++i) {
        if (entry[i] == '\n') {
            entry[i] = '\0';
        }
    }

}

/**
 * Compares two strings.
 * @param name first string.
 * @param name1 second string.
 * @param size max size of the strings.
 * @return true if strings are equal, false otherwise.
 */
bool compareStrings(const char *name, const char *name1, int size) {

    int i;
    for (i = 0; i < size && name1[i] != '\n' && name1[i] != '\0'; ++i) {
        if (name[i] != name1[i]) {
            return false;
        }
    }

    return true;
}

/**
 * Copy a string.
 * @param dest destination string.
 * @param src source string.
 * @param size destination size.
 */
void copyString(char *dest, const char *src, int size) {

    int i;

    for (i = 0; i < (size - 1); ++i) {
        dest[i] = src[i];
        if (src[i] == '\0') {
            break;
        }
    }

    for (; i < size; ++i) {
        dest[i] = '\0';
    }

}

/**
 * Edit a string to upper case.
 * @param entry string to be edited.
 */
void toUpperCase(char *entry) {

    int i;

    for (i = 0; entry[i] != '\0'; ++i) {
        entry[i] = toupper(entry[i]);
    }

}

/**
 * Creates a new Customer with empty fields.
 * @return default Customer.
 */
Customer createCustomer() {
    Customer defaultCustomer = {
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            -1,
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0",
            NULL
    };
    return defaultCustomer;
}

/**
 * Check if a string is not a number.
 * @param value string to be checked.
 * @return true if string is not a number, false otherwise.
 */
bool isNotNumber(char *entry) {

    while (*entry != '\0') {

        if (*entry < '0' || '9' < *entry) {
            return true;
        }

        ++entry;
    }

    return false;
}
