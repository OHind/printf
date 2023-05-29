#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */

#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */

#define S_LONG 2
#define S_SHORT 1

/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};


/**
 * typedef struct fmt fmt_t - Struct op
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */

typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int type_to_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* functions for printing chars and strings */

int printf_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* functions for printing numbers */

int printf_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* Function for printing  non printable characters */

int printf_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Function for printing memory address */

int printf_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Functions handling other specifiers */

int find_flags(const char *format, int *i);
int find_width(const char *format, int *i, va_list list);
int find_precision(const char *format, int *i, va_list list);
int find_size(const char *format, int *i);
int printf_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int printf_rot13_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* width handler */

int handle_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);


/* utils*/

int printability(char);
int append_hexa(char, char[], int);
int is_it_digit(char);
long int convert_number(long int num, int size);
long int convert_unsgnd(unsigned long int num, int size);


#endif 

