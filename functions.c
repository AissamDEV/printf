#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int print_binary(va_list args, format_specifier_t* spec) {
    unsigned int num = va_arg(args, unsigned int);
    char* binary_str = (char*)malloc(sizeof(char) * 33);
    if (binary_str == NULL) {
        perror("Error allocating memory for binary string");
        exit(1);
    }

    for (int i = 0; i < 32; i++) {
        binary_str[i] = (num & (1 << (31 - i))) ? '1' : '0';
    }
    binary_str[32] = '\0';

    int padding = spec->width - 32;
    if (padding > 0) {
        for (int i = 0; i < padding; i++) {
            putchar('0');
        }
    }

    printf("%s", binary_str);

    free(binary_str);

    return 0;
}
