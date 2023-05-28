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
	int lf = 0;
	
	va_list ptr;
	va_start(ptr, format);
	if (format == NULL)
	{
		return (-1);
	}
	for (lf = 0; format && *(format + lf) != '\0'; lf++)
	{
		if (*(format + lf) != '%')
		{
		_putchar(*(format + lf));
		continue;
		}
		if (*(format + lf + 1) == 'd')
		{
			int car = (int) va_arg(ptr, int);
			_putchar(car + 48);
			lf++;
		}
		if (*(format + lf + 1) == 's')
		{
			const char * string = (const char *) va_arg(ptr, const char *);
				while((*string) != '\0')
				{
					_putchar(*string++);
				}
			lf++;
                }
		if (*(format + lf + 1) == 'c')
		{
			const char * string = (const char *) va_arg(ptr, const char *);
			_putchar(*string);
			lf++;
		}
		if (*(format + lf + 1) == 'i')
		{
			int car = (int) va_arg(ptr, int);
			_putchar(car + 48);
			lf++;
		}
	}
	va_end(ptr);
	_putchar('\n');
	return (lf);
}
