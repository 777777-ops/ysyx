#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    printf("=== 固定宽度整数类型 ===\n");
    
    printf("int8_t:   %" PRId8 " 到 %" PRId8 "\n", INT8_MIN, INT8_MAX);
    printf("uint8_t:  0 到 %" PRIu8 "\n", UINT8_MAX);
    
    printf("int16_t:  %" PRId16 " 到 %" PRId16 "\n", INT16_MIN, INT16_MAX);
    printf("uint16_t: 0 到 %" PRIu16 "\n", UINT16_MAX);
    
    printf("int32_t:  %" PRId32 " 到 %" PRId32 "\n", INT32_MIN, INT32_MAX);
    printf("uint32_t: 0 到 %" PRIu32 "\n", UINT32_MAX);
    
    printf("int64_t:  %" PRId64 " 到 %" PRId64 "\n", INT64_MIN, INT64_MAX);
    printf("uint64_t: 0 到 %" PRIu64 "\n", UINT64_MAX);
    
    printf("\n=== 最小宽度整数类型 ===\n");
    
    printf("int_least8_t:   %" PRIdLEAST8 " 到 %" PRIdLEAST8 "\n", INT_LEAST8_MIN, INT_LEAST8_MAX);
    printf("uint_least8_t:  0 到 %" PRIuLEAST8 "\n", UINT_LEAST8_MAX);
    
    printf("int_least16_t:  %" PRIdLEAST16 " 到 %" PRIdLEAST16 "\n", INT_LEAST16_MIN, INT_LEAST16_MAX);
    printf("uint_least16_t: 0 到 %" PRIuLEAST16 "\n", UINT_LEAST16_MAX);
    
    printf("int_least32_t:  %" PRIdLEAST32 " 到 %" PRIdLEAST32 "\n", INT_LEAST32_MIN, INT_LEAST32_MAX);
    printf("uint_least32_t: 0 到 %" PRIuLEAST32 "\n", UINT_LEAST32_MAX);
    
    printf("int_least64_t:  %" PRIdLEAST64 " 到 %" PRIdLEAST64 "\n", INT_LEAST64_MIN, INT_LEAST64_MAX);
    printf("uint_least64_t: 0 到 %" PRIuLEAST64 "\n", UINT_LEAST64_MAX);
    
    printf("\n=== 最快最小宽度整数类型 ===\n");
    
    printf("int_fast8_t:   %" PRIdFAST8 " 到 %" PRIdFAST8 "\n", INT_FAST8_MIN, INT_FAST8_MAX);
    printf("uint_fast8_t:  0 到 %" PRIuFAST8 "\n", UINT_FAST8_MAX);
    
    printf("int_fast16_t:  %" PRIdFAST16 " 到 %" PRIdFAST16 "\n", INT_FAST16_MIN, INT_FAST16_MAX);
    printf("uint_fast16_t: 0 到 %" PRIuFAST16 "\n", UINT_FAST16_MAX);
    
    printf("int_fast32_t:  %" PRIdFAST32 " 到 %" PRIdFAST32 "\n", INT_FAST32_MIN, INT_FAST32_MAX);
    printf("uint_fast32_t: 0 到 %" PRIuFAST32 "\n", UINT_FAST32_MAX);
    
    printf("int_fast64_t:  %" PRIdFAST64 " 到 %" PRIdFAST64 "\n", INT_FAST64_MIN, INT_FAST64_MAX);
    printf("uint_fast64_t: 0 到 %" PRIuFAST64 "\n", UINT_FAST64_MAX);
    
    printf("\n=== 指针相关类型 ===\n");
    
    printf("intptr_t:  %" PRIdPTR " 到 %" PRIdPTR "\n", INTPTR_MIN, INTPTR_MAX);
    printf("uintptr_t: 0 到 %" PRIuPTR "\n", UINTPTR_MAX);
    
    printf("ptrdiff_t: %td 到 %td\n", PTRDIFF_MIN, PTRDIFF_MAX);
    printf("size_t:    0 到 %zu\n", SIZE_MAX);
    
    printf("\n=== 最大宽度整数类型 ===\n");
    
    printf("intmax_t:  %" PRIdMAX " 到 %" PRIdMAX "\n", INTMAX_MIN, INTMAX_MAX);
    printf("uintmax_t: 0 到 %" PRIuMAX "\n", UINTMAX_MAX);
    
    // 显示类型大小
    printf("\n=== 类型大小（字节） ===\n");
    printf("int8_t: %zu bytes\n", sizeof(int8_t));
    printf("int16_t: %zu bytes\n", sizeof(int16_t));
    printf("int32_t: %zu bytes\n", sizeof(int32_t));
    printf("int64_t: %zu bytes\n", sizeof(int64_t));
    printf("intptr_t: %zu bytes\n", sizeof(intptr_t));
    printf("intmax_t: %zu bytes\n", sizeof(intmax_t));
    
    return 0;
}
