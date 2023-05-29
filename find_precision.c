#include "main.h"

/**
 * find_precision - gets the precision for printing
 * @format: Formatted string
 * @i: the list of arguments to be printed.
 * @list: the list of arguments.
 *
 * Return: the precision.
 */

int find_precision(const char *format, int *i, va_list list)
{
	int x = *i + 1;
	int precision = -1;

	if (format[x] != '.')
		return (precision);
	precision = 0;
	for (x += 1; format[x] != '\0'; x++)
	{
		if (is_it_digit(format[x]))
		{
			precision *= 10;
			precision += format[x] - '0';
		}
		else if (format[x] == '*')
		{
			x++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = x - 1;
	return (precision);
}
