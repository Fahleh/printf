#include "main.h"

/**
 * _writechar - Handles printing a string
 *
 * @c: Char types.
 * @buffer: Buffer array
 * @flags:  Active flags.
 * @width: Get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed characters.
 */

int _writechar(char c, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0;
	char padding = ' ';

	UNUSED(precision);
	UNUSED(size);

	if (flags & ZERO)
		padding = '0';

	buffer[i++] = c;
	buffer[i] = '\0';

	if (width > 1)
	{
		buffer[BUFFER - 1] = '\0';
		for (i = 0; i < width - 1; i++)
			buffer[BUFFER - i - 2] = padding;

		if (flags & MINUS)
			return (write(1, &buffer[0], 1) +
					write(1, &buffer[BUFFER - i - 1], width - 1));
		else
			return (write(1, &buffer[BUFFER - i - 1], width - 1) +
					write(1, &buffer[0], 1));
	}

	return (write(1, &buffer[0], 1));
}


/**
 * _writenumber - Handles printing a string
 *
 * @is_negative: List of arguments
 * @ind: Char types
 * @buffer: Buffer array
 * @flags:  Checks active flags
 * @width: Get width.
 * @precision: precision specifier
 * @size: Size specifier
 *
 * Return: Number of printed characters.
 */

int _writenumber(int is_negative, int ind, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER - ind - 1;
	char padding = ' ', excess_char = 0;

	UNUSED(size);

	if ((flags & ZERO) && !(flags & MINUS))
		padding = '0';
	if (is_negative)
		excess_char = '-';
	else if (flags & PLUS)
		excess_char = '+';
	else if (flags & SPACE)
		excess_char = ' ';

	return (_writenum(ind, buffer, flags, width, precision,
		length, padding, excess_char));
}

/**
 * _writenum - Writes a number using a bufffer
 *
 * @ind: Index at which the number starts on the buffer
 * @buffer: Buffer
 * @flags: Flags
 * @width: width
 * @prec: Precision
 * @length: Number length
 * @padding: Pading char
 * @excess: Extra char
 *
 * Return: Number of printed chars.
 */

int _writenum(int ind, char buffer[],
	int flags, int width, int prec,
	int length, char padding, char excess)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFFER - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFFER - 2 && buffer[ind] == '0')
		buffer[ind] = padding = ' ';
	if (prec > 0 && prec < length)
		padding = ' ';
	while (prec > length)
		buffer[--ind] = '0', length++;
	if (excess != 0)
		length++;
	if (width > length)
	{
		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flags & MINUS && padding == ' ')
		{
			if (excess)
				buffer[--ind] = excess;
			return (write(1, &buffer[ind], length) + write(1, &buffer[1], i - 1));
		}
		else if (!(flags & MINUS) && padding == ' ')
		{
			if (excess)
				buffer[--ind] = excess;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));
		}
		else if (!(flags & MINUS) && padding == '0')
		{
			if (excess)
				buffer[--padd_start] = excess;
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start)));
		}
	}
	if (excess)
		buffer[--ind] = excess;
	return (write(1, &buffer[ind], length));
}

/**
 * _writeunsgnd - Writes an unsigned number
 *
 * @is_negative: Sign indicator
 * @ind: Index of first num
 * @buffer: Array of chars
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of written characters.
 */

int _writeunsgnd(int is_negative, int ind,
	char buffer[],
	int flags, int width, int precision, int size)
{
	int length = BUFFER - ind - 1, i = 0;
	char padding = ' ';

	UNUSED(is_negative);
	UNUSED(size);

	if (precision == 0 && ind == BUFFER - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padding = ' ';

	while (precision > length)
	{
		buffer[--ind] = '0';
		length++;
	}

	if ((flags & ZERO) && !(flags & MINUS))
		padding = '0';

	if (width > length)
	{
		for (i = 0; i < width - length; i++)
			buffer[i] = padding;

		buffer[i] = '\0';

		if (flags & MINUS)
		{
			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));
		}
		else
		{
			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));
		}
	}

	return (write(1, &buffer[ind], length));
}

/**
 * _writepointer - Write a memory address
 *
 * @buffer: Arrays of chars
 * @ind: Index of first num
 * @length: Length of number
 * @width: Wwidth
 * @flags: Flags
 * @padding: Padding
 * @excess: Excess char
 * @padd_start: Index to start padding
 *
 * Return: Number of written characters.
 */

int _writepointer(char buffer[], int ind, int length,
	int width, int flags, char padding, char excess, int padd_start)
{
	int i;

	if (width > length)
	{
		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padding;
		buffer[i] = '\0';
		if (flags & MINUS && padding == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (excess)
				buffer[--ind] = excess;
			return (write(1, &buffer[ind], length) + write(1, &buffer[3], i - 3));
		}
		else if (!(flags & MINUS) && padding == ' ')
		{
			buffer[--ind] = 'x';
			buffer[--ind] = '0';
			if (excess)
				buffer[--ind] = excess;
			return (write(1, &buffer[3], i - 3) + write(1, &buffer[ind], length));
		}
		else if (!(flags & MINUS) && padding == '0')
		{
			if (excess)
				buffer[--padd_start] = excess;
			buffer[1] = '0';
			buffer[2] = 'x';
			return (write(1, &buffer[padd_start], i - padd_start) +
				write(1, &buffer[ind], length - (1 - padd_start) - 2));
		}
	}
	buffer[--ind] = 'x';
	buffer[--ind] = '0';
	if (excess)
		buffer[--ind] = excess;
	return (write(1, &buffer[ind], BUFFER - ind - 1));
}
