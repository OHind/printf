#include "main.h"
/**
 * print_str - prints string
 * @string: list
 * Return: number of char
 */
int print_str(va_list string)
{
	int l;
	char *s;

	s = va_arg(string, char *);

	if (s == NULL)
		s = "(null)";
	l = 0;

	while (s[l] != '\0')
		l = l + _putchar(s[l]);
	return (l);
}
