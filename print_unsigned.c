#include "main.h"
/**
 * print_unsigned - Prints unsigned int
 * @unsign: list being passed
 * Return: char count
 */
int print_unsigned(va_list unsign)
{
	unsigned int x;
	int expo = 1;
	int len = 0;

	x = va_arg(unsign, unsigned int);

	while (x / expo > 9)
		expo *= 10;

	while (expo != 0)
	{
		len = len + _putchar(x / expo + '0');
		x = x % expo;
		expo = expo / 10;
	}

	return (len);
}
