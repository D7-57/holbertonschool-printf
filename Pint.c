#include "main.h"

/**
 * print_int - prints an integer
 * @args: argument list
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	unsigned int num;
	int count = 0;
	char digit;

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = -n;
	}
	else
	{
		num = n;
	}

	/* Handle digits recursively */
	if (num / 10)
		count += print_number(num / 10);

	digit = (num % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}

/**
 * print_number - helper to print digits recursively
 * @n: unsigned int
 * Return: number of characters printed
 */
int print_number(unsigned int n)
{
	int count = 0;
	char digit;

	if (n / 10)
		count += print_number(n / 10);

	digit = (n % 10) + '0';
	write(1, &digit, 1);
	count++;

	return (count);
}
