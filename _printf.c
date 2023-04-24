#include <stdio.h>
#include <stdarg.h>
#include "main.h"
/**
 * _printf - Print formatted output to stdout
 * @format: The format string, containing conversion specifiers
 * and optional text to be printed verbatim
 *
 * Return: The number of characters printed, excluding the null byte
 * used to end output to strings, or a negative value if an error occurs
 */
int _printf(const char *format, ...)
{
	int num_chars_printed = 0;
	const char *p = format;

	va_list args;
	va_start(args, format);

	while (*p != '\0')
	{
		if (*p == '%')
		{
			p++;
			switch (*p)
			{
				case 'd':
					num_chars_printed += printf("%d", va_arg(args, int));
					break;
				case 's':
					num_chars_printed += printf("%s", va_arg(args, char*));
					break;
				case 'f':
					num_chars_printed += printf("%f", va_arg(args, double));
					break;
				case 'c':
					num_chars_printed += printf("%c", va_arg(args, int));
					break;
				default:
					num_chars_printed += printf("%%%c", *p);
			}
		}
		else
		{
			putchar(*p);
			num_chars_printed++;
		}
		p++;
	}
	va_end(args);
	return (num_chars_printed);
}
