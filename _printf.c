#include "main.h"

static void check_flags(va_list args, const char format, int *len)
{
	if (format == 'c')
		_putchar((char)va_arg(args, int), len);
	else if (format == 's')
		_putstr(va_arg(args, char *), len);
	else if (format == '%')
		_putchar(format, len);
}

int	_printf(const char *format, ...)
{
	va_list	args;
	int		len;

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
