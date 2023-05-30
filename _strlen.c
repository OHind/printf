#include "main.h"

/**
 * _strlen - gets string length
 * @string: string
 * Return: length (int)
 */

int _strlen(char *string)
{
	int l;

	l = 0;
	while (string[l] != '\0')
	{
		l++;
	}
	return (l);
}
