#include "main.h"

/**
 * _getflags - Checks the active flags
 *
 * @format: Formatted string
 * @i: take a parameter
 *
 * Return: Flags
 */

int _getflags(const char *format, int *i)
{
	int j, current_index;
	int flags = 0;
	const char FLAG_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS[] = {MINUS, PLUS, ZERO, HASH, SPACE, 0};

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		for (j = 0; FLAG_CH[j] != '\0'; j++)
			if (format[current_index] == FLAG_CH[j])
			{
				flags |= FLAGS[j];
				break;
			}

		if (FLAG_CH[j] == 0)
			break;
	}

	*i = current_index - 1;

	return (flags);
}

/**
 * _getprecision - Calculates the printing precision
 *
 * @format: Formatted string
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */

int _getprecision(const char *format, int *i, va_list list)
{
	int current_index = *i + 1;
	int precision = -1;

	if (format[current_index] != '.')
		return (precision);

	precision = 0;

	for (current_index += 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			precision *= 10;
			precision += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_index - 1;

	return (precision);
}

/**
 * _getsize - Calculates the size
 *
 * @format: Formatted string
 * @i: List of arguments to be printed.
 *
 * Return: Precision.
 */

int _getsize(const char *format, int *i)
{
	int current_index = *i + 1;
	int size = 0;

	if (format[current_index] == 'l')
		size = LONG;
	else if (format[current_index] == 'h')
		size = SHORT;

	if (size == 0)
		*i = current_index - 1;
	else
		*i = current_index;

	return (size);
}

/**
 * get_width - Calculates the width for printing
 * @format: Formatted string in which to print the arguments.
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: width.
 */
int _getwidth(const char *format, int *i, va_list list)
{
	int current_index;
	int width = 0;

	for (current_index = *i + 1; format[current_index] != '\0'; current_index++)
	{
		if (is_digit(format[current_index]))
		{
			width *= 10;
			width += format[current_index] - '0';
		}
		else if (format[current_index] == '*')
		{
			current_index++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = current_index - 1;

	return (width);
}
