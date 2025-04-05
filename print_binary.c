#include "main.h"

/**
 * print_binary - Prints an unsigned int in binary format
 * @args: List of arguments
 *
 * Return: Number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	int i, started = 0;
	unsigned int mask;

	/* 32 bits for unsigned int */
	for (i = 31; i >= 0; i--)
	{
		mask = 1u << i;
		if (n & mask)
		{
			write(1, "1", 1);
			count++;
			started = 1;
		}
		else if (started)
		{
			write(1, "0", 1);
			count++;
		}
	}

	if (!started)
	{
		write(1, "0", 1);
		count = 1;
	}

	return (count);
}
