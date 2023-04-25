#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "main.h"
/**
  *_putchar - function that outputs a single characte
  *@c: character
  *Return: putchar
  */
int _putchar(char c)
{
	return (putchar(c));
}
/**
  *print_binary - function thats print a binary
  *@n: unsigned integer to print in binary
  *Return: void
  */
void print_binary(unsigned int n)
{
	if (n > 1)
		print_binary(n / 2);
		_putchar((n % 2) + '0');
}
int _printf(const char *format, ...)
{
	va_list args;
	int printed = 0;
	unsigned int n;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'b')
			{
				n = va_arg(args, unsigned int);
				print_binary(n);
				printed += sizeof(unsigned int) * 8;
			}
			else
			{
				_putchar('%');
				printed++;
				if (*format)
					_putchar(*format);
				printed++;
			}
		}
		else
		{
			_putchar(*format);
			printed++;
		}
		format++;
	}
	va_end(args);
	return (printed);
}
