#include "main.h"

/**
 * is_printable - Checks if a char can be printed
 * 
 * @c: Char
 *
 * Return: 1 if c is printable, 0 otherwise
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}


/**
 * _addhexa - Adds ACII in hexadecimal
 * 
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: ASSCI CODE.
 * Return: Always 3
 */
int _addhexa(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Checks if a char is a digit
 * 
 * @c: Char
 *
 * Return: 1 if c is a digit, 0 otherwise
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * _convertsize_num - Converts a number to the specified size
 * 
 * @num: Number
 * @size: Size
 *
 * Return: Casted num
 */

long int _convertsize_num(long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * _convert_unsgnd - Converts a number to the specified size
 * 
 * @num: Number
 * @size: Number
 *
 * Return: Converted num
 */

long int _convert_unsgnd(unsigned long int num, int size)
{
	if (size == LONG)
		return (num);
	else if (size == SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
