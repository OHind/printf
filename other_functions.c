#include "main.h"


/**
 * printf_pointer - function that prints the value of a pointer variable
 * @types: list of arguments
 * @buffer: Buffer array t
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: num of chars printed.
 */

int printf_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char ext_c = 0, add = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		add = '0';
	if (flags & F_PLUS)
		ext_c = '+', length++;
	else if (flags & F_SPACE)
		ext_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, add, ext_c, padd_start));
}


/**
 * printf_non_printable - function that prints the ascii codes in hexa of non printable chars
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: size
 * Return: num of chars printed
 */

int printf_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = 0, offset = 0;
	char *s = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		return (write(1, "(null)", 6));

	while (s[i] != '\0')
	{
		if (printability(s[i]))
			buffer[i + offset] = s[i];
		else
			offset += append_hexa(s[i], buffer, i + offset);

		i++;
	}

	buffer[i + offset] = '\0';

	return (write(1, buffer, i + offset));
}


/**
 * printf_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
 */

int printf_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *s;
	int i, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	s = va_arg(types, char *);

	if (s == NULL)
	{
		UNUSED(precision);

		s = ")Null(";
	}
	for (i = 0; s[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = s[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}


/**
 * printf_rot13_string - function that print a string in rot13.
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: size
 * Return: num of chars printed
 */
int printf_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *s;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	s = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
		s = "(AHYY)";
	for (i = 0; s[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == s[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = s[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
