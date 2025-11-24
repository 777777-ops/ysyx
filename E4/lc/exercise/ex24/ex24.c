#include <stdio.h>
#include <stdlib.h>
#include "lib/dbg.h"

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES,
    BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;


int main(int argc, char *argv[])
{
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;
    char buffer[MAX_DATA];

    printf("What's your First Name? ");
    
    i = scanf("%50s", you.first_name);
    check(i > 0, "Failed to read first name.");
    //in = fgets(you.first_name, MAX_DATA-1, stdin);
    //check(in != NULL, "Failed to read first name.");
    getchar();

    printf("What's your Last Name? ");
    i = scanf("%50s", you.last_name);
    check(i > 0, "Failed to read last name.");
    getchar();

    char* endprt;
    printf("How old are you? ");
    in = fgets(buffer, MAX_DATA-1, stdin);  /*使用fgets有个小问题，直接输入换行就结束输入了*/
    check(in != NULL, "Failed to read last name");
    //转换
    you.age = strtol(buffer, &endprt, 10);
    check(*endprt == '\0'||*endprt == '\n', "Fail turn.");
    

    printf("What color are your eyes:\n");
    for(i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i+1, EYE_COLOR_NAMES[i]);
    }
    printf("> ");

    int eyes = -1;
    in = fgets(buffer, MAX_DATA-1, stdin);  /*使用fgets有个小问题，直接输入换行就结束输入了*/
    check(in != NULL, "Failed to read last name");
    //转换
    eyes = strtol(buffer, &endprt, 10);
    check(*endprt == '\0'||*endprt == '\n', "Fail turn.");

    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

    int rc;
    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number.");

    printf("----- RESULTS -----\n");

    printf("First Name: %s", you.first_name);
    printf("Last Name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);

    return 0;
error:

    return -1;
}
