#include "main.h"

/**
 * print_bin - function that Print binary
 *
 * @bin: list
 *
 * Return: updated count
 */

int print_bin(va_list bin)
{
	int count = 0, i;
	int *a;
	unsigned int n = va_arg(bin, unsigned int);
	unsigned int tmp = n;

	while (n / 2 != 0)
	{
		n /= 2;
		count++;
	}
	count++;

	a = malloc(count * sizeof(int));
	if (a == NULL)
	{
		free(a);
		return (0);
	}

	for (i = 0; i < count; i++)
	{
		a[i] = tmp % 2;
		tmp /= 2;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(a[i] + '0');
	}
	free(a);
	return (count);
}
