#include <stdio.h>
#include "ex22.h"
#include "dbg.h"

int THE_SIZE = 1000;

static int THE_AGE = 37;

int get_age()
{
    return THE_AGE;
}

void set_age(int age)
{
    THE_AGE = age;
}

double* get_ratio_addr(){
    static double ratio = 1.0;
    return &ratio;
}

double update_ratio(double new_ratio)
{
    double old_ratio = *get_ratio_addr();
    *get_ratio_addr() = new_ratio;

    return old_ratio;
}

void print_size()
{
    log_info("I think size is: %d", THE_SIZE);
}
