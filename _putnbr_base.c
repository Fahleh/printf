#include "main.h"

void _putnbr_base(unsigned int nbr, char Xx, int *len)
{
	unsigned int base_len;
	char *base;

	base_len = 16;
	if (Xx == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (nbr < base_len)
		_putchar(base[nbr % base_len], len);
	else
	{
		_putnbr_base(nbr / base_len, Xx, len);
		_putnbr_base(nbr % base_len, Xx, len);
	}
}
