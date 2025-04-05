#include "main.h"

/**
 * handle_format - Handles format specifiers for _printf
 * @format: Format string
 * @args: Argument list
 * @i: Current index in format string (pointer)
 * Return: Number of characters printed or -1 on error
 */
int handle_format(const char *format, va_list args, int *i)
{
	int printed = 0;

	if (!format[*i])
		return (-1);

	if (format[*i] == 'c')
		printed += print_char(args);
	else if (format[*i] == 's')
		printed += print_string(args);
	else if (format[*i] == '%')
		printed += print_percent();
	else if (format[*i] == 'd' || format[*i] == 'i')
		printed += print_int(args);
	else if (format[*i] == 'b')
        	printed += print_binary(args);
	else
	{
		write(1, "%", 1);
		write(1, &format[*i], 1);
		printed += 2;
	}
	(*i)++;
	return (printed);
}
