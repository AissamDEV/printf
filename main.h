#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...);
int print_binary(va_list args, format_specifier_t *spec);

#endif /* MAIN_H */

