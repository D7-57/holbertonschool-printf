#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0, printed = 0;
	char buffer[1024];
	int buf_len = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printed = handle_format_buffer(format, args, &i, buffer, &buf_len);
			if (printed == -1)
				return (-1);
			count += printed;
		}
		else
		{
			buffer[buf_len++] = format[i++];
			if (buf_len == 1024)
				flush_buffer(buffer, &buf_len);
			count++;
		}
	}

	va_end(args);
	if (buf_len > 0)
		flush_buffer(buffer, &buf_len);
	return (count);
}
