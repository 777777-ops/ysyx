#include <stdio.h>
#include <stddef.h>
#include <ctype.h>
#include "dbg.h"


int print_a_message(const char *msg, size_t length)
{
    size_t i = 0;

    printf("A STRING: ");
    for(i = 0; msg[i] != '\0' && i < length; i++) {
        printf("%c", msg[i]);
    }

    printf("\n");


    return 0;
}


int uppercase(const char *msg, size_t length)
{
    size_t i = 0;

    // BUG: \0 termination problems
    for(i = 0; msg[i] != '\0' && i < length; i++) {
        printf("%c", toupper(msg[i]));
    }

    printf("\n");

    return 0;
}

int lowercase(const char *msg, size_t length)
{
    size_t i = 0;

    // BUG: \0 termination problems
    for(i = 0; msg[i] != '\0' && i < length; i++) {
        printf("%c", tolower(msg[i]));
    }

    printf("\n");

    return 0;
}

int fail_on_purpose(const char *msg, size_t length)
{
    return 1;
}
