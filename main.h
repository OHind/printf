#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - function to check for formats
 * @type: The format to print
 * @f: The print function to use
 */
typedef struct fmt
{
	char *type;
	int (*f)();
} fmt_st;

int _printf(const char *format, ...);
int print_operator(const char *format, fmt_t *print_arr, va_list list);
int print_ch(va_list character);
int print_str(va_list string);
int print_int(va_list integ);
int print_unsigned(va_list unsign);
int print_oct(va_list octo);
int print_rot13(va_list rot);
int _hex_str(unsigned int n, unsigned int hex, char alpha);
int _hex_l(va_list hexa);
int _hex_u(va_list hexa);
int _strlen(char *s);
int print_bin(va_list bin);
int _putchar(char c);
#endif
