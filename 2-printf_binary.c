#include "main.h"
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
