#include "main.h"

/**
 * print_rot13 - function that prints rot13 version
 *
 * @rot: the list passed
 *
 * Return: count
 */

int print_rot13(va_list rot)
{
	int x, count;
	char *s;

	x = count = 0;
	s = va_arg(rot, char *);

	if (s == NULL)
		return (-1);

	while (s[x] != '\0')
	{

		if ((s[x] >= 'a' && s[x] <= 'z') ||
			(s[x] >= 'A' && s[x] <= 'Z'))
		{
			if ((s[x] >= 'n' && s[x] <= 'z') ||
				(s[x] >= 'N' && s[x] <= 'Z'))
				count = count + _putchar(s[x] - 13);
			else
				count = count + _putchar(s[x] + 13);
		}
		else
			count = count + _putchar(s[x]);
		x++;
	}
	return (count);
}
