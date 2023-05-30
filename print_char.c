#include "main.h"

/**
 * print_char - function that prints caracter
 *
 * @c: list passed
 *
 * Return: number of char printed
 */
int print_char(va_list c)
{
	return (_putchar(va_arg(c, int)));
}
