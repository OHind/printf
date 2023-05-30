#include "main.h"
/**
 * print_oct - Print octal
 * @octo: list passed
 * Return: updated count
 */
int print_oct(va_list oct)
{
	int count = 0, i;
	int *ar;
	unsigned int n = va_arg(oct, unsigned int);
	unsigned int tmp = n;

	while (n / 8 != 0)
	{
		n /= 8;
		count++;
	}
	count++;
	arr = malloc(count * sizeof(int));
	for (i = 0; i < count; i++)
	{
		ar[i] = tmp % 8;
		tmp /= 8;
	}
	for (i = count - 1; i >= 0; i--)
	{
		_putchar(ar[i] + '0');
	}
	free(ar);
	return (count);
}
