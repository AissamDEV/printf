#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_arg - Print the argument based on the specified conversion specifier.
 * @args: The list of arguments.
 * @specifier: The conversion specifier.
 *
 * Return: The number of characters printed.
 */
int print_arg(va_list args, char specifier)
{
	int len = 0;

	switch (specifier)
	{
		case 'c':
			len += putchar(va_arg(args, int));
			break;
		case 's':
			len += printf("%s", va_arg(args, char *));
			break;
		case 'd':
		case 'i':
			len += printf("%d", va_arg(args, int));
			break;
		case 'u':
			len += printf("%u", va_arg(args, unsigned int));
			break;
		case 'o':
			len += printf("%o", va_arg(args, unsigned int));
			break;
		case 'x':
			len += printf("%x", va_arg(args, unsigned int));
			break;
		case 'X':
			len += printf("%X", va_arg(args, unsigned int));
			break;
		case 'p':
			len += printf("%p", va_arg(args, void *));
			break;
		case '%':
			len += putchar('%');
			break;
		default:
			len += putchar('%');
			len += putchar(specifier);
			break;
	}
	return (len);
}
/**
 * _printf - Print a formatted string to stdout.
 * @format: Format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int len = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len += print_arg(args, *format);
		}
		else
		{
			len += putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (len);
}
