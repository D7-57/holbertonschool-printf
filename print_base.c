#include "main.h"

/**
 * print_base - Prints an unsigned int in a specified base
 * @n: Number to print
 * @base: Base to convert to
 * @uppercase: 1 for uppercase hex, 0 for lowercase
 * Return: Number of characters printed
 */
int print_base(unsigned int n, int base, int uppercase)
{
	char buffer[32];
	char *digits;
	int i = 0, count = 0;

	digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (n)
	{
		buffer[i++] = digits[n % base];
		n /= base;
	}

	while (i--)
	{
		write(1, &buffer[i], 1);
		count++;
	}

	return (count);
}
