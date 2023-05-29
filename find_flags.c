#include "main.h"

/**
 * find_flags - function to alculates active flags
 * @format: Formatted string
 * @i: a parameter.
 * Return: flag.
 */
/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
int find_flags(const char *format, int *i)
{
	int j, k;
	int flag = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (k = *i + 1; format[k] != '\0'; k++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[k] == FLAGS_CH[j])
			{
				flag |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}
	*i = k - 1;
	return (flag);
}

