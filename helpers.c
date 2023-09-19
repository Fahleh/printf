#include "main.h"

/**
 * _handleprint - Prints an argument based on its type
 *
 * @fmt: Formatted string
 * @list: List of arguments
 * @ind: Pointer
 * @buffer: Buffer array
 * @flags: Flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 *
 * Return: 1 or 2;
 */

int _handleprint(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	flag_t flag_types[] = {
		{'c', _putchar}, {'s', _printstring}, {'%', _printpercent},
		{'i', _printint}, {'d', _printint}, {'b', _printbinary},
		{'u', _printunsigned}, {'o', _printoctal}, {'x', _printhexadecimal},
		{'X', _printhexa_upper}, {'p', _printpointer}, {'S', _nonprintable},
		{'r', _printreverse}, {'R', _printrot13}, {'\0', NULL}
	};
	for (i = 0; flag_types[i].flag != '\0'; i++)
		if (fmt[*ind] == flag_types[i].flag)
			return (flag_types[i].fn(list, buffer, flags, width, precision, size));

	if (flag_types[i].flag == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}


/**
 * _printpercent - Prints the percent sign
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width.
 * @precision: Precision
 * @size: Size
 *
 * Return: Number of chars printed
 */

int _printpercent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * _printhexa - Prints lowercase & upppercase hexadecimals
 *
 * @types: List of arguments
 * @map_to: Array of mapped numbers
 * @buffer: Buffer
 * @flags:  Flags
 * @flag_ch: Active flags
 * @width: Width
 * @precision: Precision
 * @size: Size
 * @size: Size
 *
 * Return: Number of printed charaters
 */

int _printhexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
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
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (_writeunsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _printrot13 - Encodes a string with rot13.
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

int _printrot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

/**
 * _printbinary - Prints an unsigned number
 *
 * @types: List of arguments
 * @buffer: Buffer array
 * @flags:  Flags
 * @width: Width.
 * @precision: Precision
 * @size: Size
 * Return: Numbers of printed characters.
 */

int _printbinary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648;
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

