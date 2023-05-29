#include "main.h"

/**
 * printf_char - Prints a char
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int printf_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_char(c, buffer, flags, width, precision, size));
}

/**
 * printf_string - function that prints a string
 * @types: list a of arguments
 * @buffer: Buffer array
 * @flags:  calculates the active flags
 * @width: width.
 * @precision: Precision specification
 * @size: size
 * Return: num of chars printed
 */
int printf_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *s = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (s == NULL)
	{
		s = "(null)";
		if (precision >= 6)
			s = "      ";
	}

	while (s[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &s[0], length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, &s[0], length);
			return (width);
		}
	}

	return (write(1, s, length));
}

/**
 * printf_percent - Prints a percent sign
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width.
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */

int printf_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}


/**
 * printf_int - function to print int
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size
 * Return: num of chars printed
 */
int printf_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	int is_neg = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_number(n, size);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_neg = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_neg, i, buffer, flags, width, precision, size));
}


/**
 * printf_binary - function that prints an unsigned number
 * @types: list of arguments
 * @flags:  calculates active flags
 * @width: width.
 * @precision: Precision specification
 * @size: Size
 * Return: num of char printed.
 */
int printf_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, i, sum;
	unsigned int A[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	/*m= (2 ^ 31) */
	m = 2147483648;
	A[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		A[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += A[i];
		if (sum || i == 31)
		{
			char z = '0' + A[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

