#include "main.h"


/**
 * printf_unsigned - function that prints an unsigned number
 * @types: the list a of arguments
 * @buffer: buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: the precision specification
 * @size: size
 * Return: num of chars printed.
 */

int printf_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * printf_octal - function that prints an unsigned number in octal
 *
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 *
 * Return: num of chars printed.
 */

int printf_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int i_num = num;

	UNUSED(width);

	num = convert_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && i_num != 0)
		buffer[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}


/**
 * printf_hexadecimal - function that prints an unsigned number in hexadecimal
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: num of chars printed.
 */

int printf_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}


/**
 * printf_hexa_upper - function that prints an unsigned
 * number in upper hexadecimal
 * @types: list of arguments
 * @buffer: Buffer array
 * @flags:  calculates active flags
 * @width: width
 * @precision: Precision specification
 * @size: Size
 * Return: num of chars printed.
 */

int printf_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}



/**
 * printf_hexa - function that prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */

int printf_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int i_num = num;

	UNUSED(width);

	num = convert_unsgnd(num, size);
	if (num == 0)
		buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}
	if (flags & F_HASH && i_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;
	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
