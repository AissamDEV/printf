#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

// Define a struct to represent each format specifier
typedef struct format_specifier {
    char type;
    int width;
    int precision;
} format_specifier_t;

// Define a struct to represent each conversion function
typedef int (conversion_func_t)(va_list, format_specifier_t);

// Define the function prototypes for the custom printf implementation
int my_printf(const char* format, ...);
int parse_format_string(const char* format, conversion_func_t* conversion_funcs, format_specifier_t* format_specifiers);
int print_int(va_list args, format_specifier_t* spec);
int print_string(va_list args, format_specifier_t* spec);
int print_char(va_list args, format_specifier_t* spec);
int print_hex(va_list args, format_specifier_t* spec);
int print_octal(va_list args, format_specifier_t* spec);
int print_pointer(va_list args, format_specifier_t* spec);
int print_binary(va_list args, format_specifier_t* spec);

#endif // MAIN_H
