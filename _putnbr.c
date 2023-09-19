#include "main.h"

void _putnbr(int n, int *len)
{
	unsigned int nb;

	nb = n;
	if (n < 0)
	{
		_putchar('-', len);
		nb *= -1;
	}
	if (nb < 10)
		_putchar(nb + '0', len);
	else
	{
		_putnbr(nb / 10, len);
		_putnbr(nb % 10, len);
	}
}
