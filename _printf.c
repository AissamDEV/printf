#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);

	printed_chars = vprintf(format, args);
	va_end(args);
	return (printed_chars);
}
