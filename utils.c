#include "main.h"

/**
 * printability - finds out if a char is printable
 *
 * @c: Char to be evaluated.
 *
 * Return: 1 if c is printable, 0 otherwise
 */

int printability(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hexa - it appends ascii in hexadecimal code to the buffer
 *
 * @buffer: Array of chars.
 * @i: Index at which to start appending.
 * @ascii_code: the ascii code.
 *
 * Return: 3 always.
 */

int append_hexa(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];
	return (3);
}

/**
 * is_it_digit - function that verifies if a char is a digit
 * @c: the char to check
 *
 * Return: 1 when c is a digit or 0 otherwise
 */

int is_it_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/**
 * convert_number - emit a number to the specified size
 *
 * @num: the number
 * @size: Number indicating the type to be emitted.
 *
 * Return: final value
 */

long int convert_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);
	return ((int)num);
}

/**
 * convert_unsgnd - Casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */

long int convert_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);
	return ((unsigned int)num);
}
