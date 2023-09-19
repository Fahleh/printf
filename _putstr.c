#include "main.h"

/**
 * _printf - Printf function
 *
 * @s: Character.
 * @len: pointer
 *
 * Return: Printed chars.
 */

void	_putstr(char *s, int *len)
{
	if (s == NULL)
		_putstr("(null)", len);
	while (s && *s)
	{
		_putchar(*s, len);
		s++;
	}
}
