#include "main.h"

/**
 * _printint - Prints integer values
 * 
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width.
 * @precision: Precision
 * @size: Size
 * 
 * Return: Number of printed characters
 */

int _printint(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = _convertsize_num(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFFER - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num 10) + '0';
		num /= 10;
	}

	i++;

	return (_writenumber(is_negative, i, buffer, flags, width, precision, size));
}

/**
 * _printunsigned - Prints an unsigned number
 * 
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * Return: Number of printed characters.
 */

int _printunsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFFER - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = _convert_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num 10) + '0';
		num /= 10;
	}

	i++;

	return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _printoctal - Prints an unsigned number in octal
 * 
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * 
 * Return: Number of printed characters.
 */

int _printoctal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFFER - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = _convert_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFFER - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num 8) + '0';
		num /= 8;
	}

	if (flags & HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _printhexadecimal - Prints an unsigned number in hexadecimal
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

int _printhexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_printhexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * _printhexa_upper - Prints an unsigned number in uppercase hexadecimal
 * 
 * @types: Listaof arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * 
 * Return: Number of printed characters
 */

int _printhexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (_printhexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}
