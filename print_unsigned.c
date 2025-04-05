#include "main.h"

/**
 * print_unsigned - Prints an unsigned int in base 10
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_base(n, 10, 0));
}
