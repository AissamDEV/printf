#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * print_binary - converts an unsigned int argument
 *to binary and print it
 * @args: the argument to be converted and printed
 * @spec: the format specifier for the argument
 *
 * Return: the number of digits printed
 *
 */
int print_binary(va_list args, format_specifier_t *spec)
{
	unsigned int num = va_arg(args, unsigned int);
	char binary_str[33];
	int i = 0;

	while (num)
		binary_str[i++] = (num & 1) + '0';
		num >>= 1;

	binary_str[i] = '\0';
	str_reverse(binary_str);

	return (print_string(binary_str, spec));
}
