#include "main.h"

/**
 * _putchar - Prints a char
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of printed characters
 */

int _putchar(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (_writechar(c, buffer, flags, width, precision, size));
}

/**
 * _printstring - Prints a string
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of printed characters
 */

int _printstring(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int len = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}

	return (write(1, str, len));
}

/**
 * _nonprintable - Prints ascii codes in hexa
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of printed characters
 */

int _nonprintable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buffer[i + offset] = str[i];
		else
			offset += _addhexa(str[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}

/**
 * _printpointer - Prints the value of a pointer
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of printed characters
 */

int _printpointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char excess = 0, padding = ' ';
	int ind = BUFFER - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFFER - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		padding = '0';
	if (flags & PLUS)
		excess = '+', length++;
	else if (flags & SPACE)
		excess = ' ', length++;

	ind++;

	return (write_pointer(buffer, ind, length,
		width, flags, padding, excess, padd_start));
}

/**
 * _printreverse - Prints a reverse string.
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Numbers of printed characters.
 */

int _printreverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
