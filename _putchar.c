#include "main.h"

void _putchar(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}
