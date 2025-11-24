#include "ex22.h"
#include "dbg.h"

const char *MY_NAME = "Zed A. Shaw";

void scope_demo(int count)
{
    log_info("count is: %d", count);

    if(count > 10) {
        int count = 100;  // BAD! BUGS!

        log_info("count in this scope is %d", count);
    }

    log_info("count is at exit: %d", count);

    count = 3000;

    log_info("count after assign: %d", count);
}

void transfer_value(int value){

    log_info("Enter func, vaule is: %d", value);

    value = 100;

    log_info("vaule after assign: %d", value);
}

void transfer_addr(int* addr){

    log_info("Enter func, vaule is: %d", *addr);

    *addr = 100;

    log_info("vaule after assign: %d", *addr);
}

void infinite_stack(){
    int a[20 * 4096];
    log_info("stack down for least 80KB....");
    infinite_stack();
}


int main(int argc, char *argv[])
{
    // test out THE_AGE accessors
    log_info("My name: %s, age: %d", MY_NAME, get_age());

    set_age(100);

    log_info("My age is now: %d", get_age());

    // test out THE_SIZE extern
    log_info("THE_SIZE is: %d", THE_SIZE);
    print_size();

    THE_SIZE = 9;

    log_info("THE SIZE is now: %d", THE_SIZE);
    print_size();

    // test the ratio function static
    log_info("Ratio at first: %f", update_ratio(2.0));
    log_info("Ratio again: %f", update_ratio(10.0));
    log_info("Ratio once more: %f", update_ratio(300.0));

    // test the scope demo
    int count = 4;
    scope_demo(count);
    scope_demo(count * 20);

    log_info("count after calling scope_demo: %d", count);

    //"值传递和指针传递"
    int value = 10;
    int* addr = &value;

    transfer_value(value);
    log_info("count after calling transfer_value: %d", value);
    transfer_addr(addr);
    log_info("count after calling transfer_addr: %d", *addr);

    //通过指针修改ratio	
    log_info("Ratio at first: %f", *get_ratio_addr());
    *get_ratio_addr() = 233.33;
    log_info("Ratio after assign: %f", *get_ratio_addr());

    //栈溢出
    infinite_stack();

    return 0;
}
