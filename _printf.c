#include "main.h"
#include< stdarg.h>


void print_buffer(char buffer[], int *buff_ind);


/**
 * _printf - Printf function replica.
 * @format: format.
 * Return: Printed chars according to the format.
 */


int _printf(const char *format, ...)
{
	int i, p = 0, print_chars = 0;
	int flags, width, precision, size, buff_i = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_i++] = format[i];
			if (buff_i == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			print_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_i);
			flags = find_flags(format, &i);
			width = find_width(format, &i, list);
			precision = find_precision(format, &i, list);
			size = find_size(format, &i);
			++i;
			p = type_to_print(format, &i, list, buffer, flags, width, precision, size);
			if (p == -1)
				return (-1);
			print_chars += p;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (print_chars);
}


/**
 * print_buffer - Prints the buffer if it exist.
 * @buffer: Array.
 * @buff_ind: Index at which to add next char proportional to the lenght.
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
