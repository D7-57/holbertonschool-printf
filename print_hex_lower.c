#include "main.h"

/**
 * print_hex_lower - Prints an unsigned int in lowercase hexadecimal
 * @args: Argument list
 * Return: Number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_base(n, 16, 0));
}
