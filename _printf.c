#include "main.h"

static void check_flags(va_list args, const char format, int *len)
{
	if (format == 'd' || format == 'i')
		_putnbr(va_arg(args, int), len);
	else if (format == 'u')
		_putnbr_u(va_arg(args, unsigned int), len);
	else if (format == 'c')
		_putchar((char)va_arg(args, int), len);
	else if (format == 's')
		_putstr(va_arg(args, char *), len);
	else if (format == '%')
		_putchar(format, len);
	else if (format == 'x')
		_putnbr_base(va_arg(args, int), format, len);
	else if (format == 'X')
		_putnbr_base(va_arg(args, int), format, len);
	else if (format == 'p')
		_putaddr(va_arg(args, void *), len);
}

int _printf(const char *format, ...)
{
	va_list	args;
	int len;

	len = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			check_flags(args, *format, &len);
		}
		else
			_putchar(*format, &len);
		format++;
	}
	va_end(args);
	return (len);
}
