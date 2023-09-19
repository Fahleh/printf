#include "main.h"

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
