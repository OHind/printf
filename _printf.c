#include "main.h"

/**
 * print_operator - Prints dependingion the specifier
 * @format: string to be passed
 * @print_arr: array
 * @list: list of arguments
 * Return: numb of char to be printed
 */
int print_operator(const char *format, fmt_st *print_arr, va_list list)
{
	char a;
	int count = 0, b = 0, c = 0;

	a = format[b];
	while (a != '\0')
	{
		if (a == '%')
		{
			c = 0;
			b++;
			a = format[b];
			while (print_arr[c].type != NULL &&
			       a != *(print_arr[c].type))
				c++;
			if (print_arr[c].type != NULL)
				count = count + print_arr[c].f(list);
			else
			{
				if (a == '\0')
					return (-1);
				if (a != '%')
					count += _putchar('%');
				count += _putchar(a);
			}
		}
		else
			count += _putchar(a);
		b++;
		a = format[b];
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
	int a = 0;

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
	a = print_operator(format, ops, list);
	va_end(list);
	return (a);
}
