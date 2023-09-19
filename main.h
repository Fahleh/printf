#ifndef MAIN_H
# define MAIN_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int _printf(const char *format, ...);
void _putchar(char c, int *len);
void _putstr(char *s, int *len);
void _putnbr(int n, int *len);
void _putnbr_u(unsigned int n, int *len);
void _putnbr_base(unsigned int nbr, char Xx, int *len);
void _putaddr(void *addr, int *len);


#endif
