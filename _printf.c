#include "main.h"

/**
 * print_operator - Prints dependingion the specifier
 * @format: string to be passed
 * @print_arr: array
 * @list: list of arguments
 * Return: numb of char to be printed
 */
int print_operator(const char *format, fmt_t *print_arr, va_list list)
{
	char x;
	int count = 0, b = 0, c = 0;

	x = format[b];
	while (x != '\0')
	{
		if (x == '%')
		{
			c = 0;
			b++;
			x = format[b];
			while (print_arr[c].type != NULL &&
			       x != *(print_arr[c].type))
				c++;
			if (print_arr[c].type != NULL)
				count = count + print_arr[c].f(list);
			else
			{
				if (x == '\0')
					return (-1);
				if (x != '%')
					count += _putchar('%');
				count += _putchar(x);
			}
		}
		else
			count += _putchar(x);
		b++;
		x = format[b];
	}
	return (count);
}

/**
 * _printf - printf
 * @format: string  passed
 * Return: char to be printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int x = 0;

	fmt_st ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"d", print_int},
		{"b", print_bin},
		{"i", print_int},
		{"u", print_unsigned},
		{"o", print_oct},
		{"x", _hex_l},
		{"X", _hex_u},
		{"R", print_rot13},
		{NULL, NULL}
	};

	if (format == NULL)
		return (-1);
	va_start(list, format);
	x = print_operator(format, ops, list);
	va_end(list);
	return (x);
}
