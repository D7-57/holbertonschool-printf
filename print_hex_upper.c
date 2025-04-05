#include "main.h"

/**
 * print_hex_upper - Prints an unsigned int in uppercase hexadecimal
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_base(n, 16, 1));
}
