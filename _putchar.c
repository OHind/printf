#include "main.h"
#include <unistd.h>
/**
 * _putchar - Print char
 * @c: char to print
 * Return: the number of bytes written
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
