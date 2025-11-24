#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>
#include <stddef.h>
#include <stdlib.h>

typedef int (*lib_function)(const char *data, size_t length);

int main(int argc, char *argv[])
{
    int rc = 0;
    /*
    printf("%d\n",argc);
    for(int i = 0; i < argc; i++)
	printf("%s\n", argv[i]);
    */
    check(argc == 5, "USAGE: ex29 libex29.so function data\n Your args %s %s %s %s %s", argv[0], argv[1], argv[2], argv[3], argv[4]);

    char *lib_file = argv[1];
    char *func_to_run = argv[2];
    char *data = argv[3];
    size_t length = (size_t)atoi(argv[4]);  //这里的字符串转换并不安全

    // 构建完整的库文件路径
    char lib_path[256];
    snprintf(lib_path, sizeof(lib_path), "build/%s", lib_file);

    void *lib = dlopen(lib_path, RTLD_NOW);
    check(lib != NULL, "Failed to open the library %s: %s", lib_file, dlerror());

    lib_function func = dlsym(lib, func_to_run);
    check(func != NULL, "Did not find %s function in the library %s: %s", func_to_run, lib_file, dlerror());

    rc = func(data, length);
    check(rc == 0, "Function %s return %d for data: %s", func_to_run, rc, data);

    rc = dlclose(lib);
    check(rc == 0, "Failed to close %s", lib_file);

    return 0;

error:
    return 1;
}
