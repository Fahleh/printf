#include "main.h"

void _putnbr_u(unsigned int n, int *len)
{
	if (n < 10)
		_putchar(n + '0', len);
	else
	{
		_putnbr(n / 10, len);
		_putnbr(n % 10, len);
	}
}
