#include "main.h"
#include "_printf.c"
#include <stdlib.h>
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
