#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string containing characters and specifiers
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, printed;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed = handle_format(format, args, &i);
			if (printed == -1)
				return (-1);
			count += printed;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}

	va_end(args);
	return (count);
}
