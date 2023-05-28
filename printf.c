#include "main.h"
#include <stdlib.h>
#include <stdarg.h>
/**
 * _printf - print
 * @format: the format to print
 * Return: the number of caracter printed
 */
int _printf(const char *format, ...)
{
	int i = 0, lf = 0;

	if (format == NULL)
	{
		return (-1);
	}
	while (*(format + lf) != '\0')
	{
		lf++;
	}
	for (i = 0; format && *(format + i) != '\0'; i++)
	{
		_putchar(*(format + i));
	}
	_putchar('\n');
	return (lf);
}
