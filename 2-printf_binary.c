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
	int i, padding;
	unsigned int num = va_arg(args, unsigned int);
	char *binary_str = (char *)malloc(sizeof(char) * 33);

	if (binary_str == NULL)
	{
		perror("Error");
		exit(1);
	}
	for (i = 0; i < 32; i++)
	{
		binary_str[i] = (num & (1 << (31 - i))) ? '1' : '0';
	}
	binary_str[32] = '\0';

	padding = spec->width - 32;
	if (padding > 0)
	{
		for (i = 0; i < padding; i++)
		{
			putchar('0');
		}
	}
	printf("%s", binary_str);
	free(binary_str);

	return (0);
}
