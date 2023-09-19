#include "main.h"

void _putaddr_hex(unsigned long int nbr, char Xx, int *len)
{
	unsigned long int base_len;
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
		_putaddr_hex(nbr / base_len, Xx, len);
		_putaddr_hex(nbr % base_len, Xx, len);
	}
}

void _putaddr(void *addr, int *len)
{
	unsigned long int ptr;

	ptr = (unsigned long int)addr;
	_putstr("0x", len);
	_putaddr_hex(ptr, 'x', len);
}
