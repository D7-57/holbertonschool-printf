/**
 * handle_format_buffer - Handles format specifiers with buffer
 * @format: Format string
 * @args: Argument list
 * @i: Current index
 * @buffer: Buffer to write to
 * @buf_len: Pointer to buffer length
 *
 * Return: Number of characters written or -1 on error
 */
int handle_format_buffer(const char *format, va_list args, int *i,
			 char *buffer, int *buf_len)
{
	int printed = 0;
	char temp[100];
	int len;

	if (!format[*i])
		return (-1);

	if (format[*i] == 'c')
	{
		char c = va_arg(args, int);
		buffer[(*buf_len)++] = c;
		printed = 1;
	}
	else if (format[*i] == 's')
	{
		char *str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		for (len = 0; str[len]; len++)
		{
			buffer[(*buf_len)++] = str[len];
			if (*buf_len == 1024)
				flush_buffer(buffer, buf_len);
		}
		printed = len;
	}
	else if (format[*i] == '%')
	{
		buffer[(*buf_len)++] = '%';
		printed = 1;
	}
	/* Extend this to call print_int_buffer, print_unsigned_buffer, etc. */
	else
	{
		buffer[(*buf_len)++] = '%';
		buffer[(*buf_len)++] = format[*i];
		printed = 2;
	}
	(*i)++;
	return (printed);
}
