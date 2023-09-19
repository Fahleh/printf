#include "main.h"

/**
 * _printf - Printf function
 *
 * @c: Character.
 * @len Length
 *
 * Return: Printed chars.
 */

void _putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
