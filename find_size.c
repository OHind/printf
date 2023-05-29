#include "main.h"

/**
 * find_size - function that calculates the size to cast the argument
 * @format: the formatted string
 * @i: List of arguments to be printed.
 *
 * Return: size.
 */

int find_size(const char *format, int *i)
{
	int x = *i + 1;
	int size = 0;

	if (format[x] == 'l')
		size = S_LONG;
	else if (format[x] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = x - 1;
	else
		*i = x;
	return (size);
}
