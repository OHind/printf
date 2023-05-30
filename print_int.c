#include "main.h"

/**
 * print_int - function that prints integers
 *
 * @integ: list to print
 *
 * Return: len(count)
 */

int print_int(va_list integ)
{
	int a, b = 1, len = 0;
	unsigned int x;

	a = va_arg(integ, int);

	if (a < 0)
	{
		len = len + _putchar('-');
		x = a * -1;
	}
	else
		x = a;
	while (x / b > 9)
		b *= 10;
	while (b != 0)
	{
		len = len + _putchar(x / b + '0');
		x = x % b;
		b = b / 10;
	}
	return (len);
}
