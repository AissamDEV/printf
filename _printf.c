#include <stdarg.h>
#include <stdio.h>
/**
 * _printf - Print a formatted string to stdout.
 * @format: Format string.
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
	int num_chars = 0;
	char c;
	va_list arg_list;

	va_start(arg_list, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = (char) va_arg(arg_list, int);
				putchar(c);
				num_chars++;
			} else if (*format == 's')
			{
				char *s = va_arg(arg_list, char *);

				while (*s != '\0')
				{
					putchar(*s);
					s++;
					num_chars++;
				}
			} else if (*format == '%')
			{
				putchar('%');
				num_chars++;
			}
		} else
		{
			putchar(*format);
			num_chars++;
		}
		format++;
	} va_end(arg_list);
	return (num_chars);
}
