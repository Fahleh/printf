#include "main.h"

void _printbuffer(char buffer[], int *buffer_index);

/**
 * _printf - A custom printf function
 *
 * @format: format
 *
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size;
	int buffer_index = 0;
	char buffer[BUFFER];
	va_list list;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buffer_index++] = format[i];
			if (buffer_index == BUFFER)
				_printbuffer(buffer, &buffer_index);

			printed_chars++;
		}
		else
		{
			_printbuffer(buffer, &buffer_index);
			flags = _getflags(format, &i);
			width = _getwidth(format, &i, list);
			precision = _getprecision(format, &i, list);
			size = _getsize(format, &i);
			++i;
			printed = _handleprint(format, &i, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	_printbuffer(buffer, &buffer_index);

	va_end(list);

	return (printed_chars);
}

/**
 * _printbuffer - Prints the contents of the buffer
 *
 * @buffer: Array
 * @buffer_index: Index at which to add next char
 *
 */

void _printbuffer(char buffer[], int *buffer_index)
{
	if (*buffer_index > 0)
		write(1, &buffer[0], *buffer_index);

	*buffer_index = 0;
}
