#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: The number of characters printed
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
