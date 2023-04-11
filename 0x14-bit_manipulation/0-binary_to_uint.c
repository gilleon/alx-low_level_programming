#include "main.h"
#include <stdio.h>

/**
 * binary_to_uint - unction that converts a binary number to an unsigned int
 * @b: char argv
 * Return: the converted number,
 */
unsigned int binary_to_uint(const char *b)
{
	unsigned int abs, expo;
	int length;

	if (b == NULL)
	{
		return (0);
	}

	for (length = 0; b[length]; length++)
	{
		if (b[length] != '0' && b[length] != '1')
		{
			return (0);
		}
	}

	for (expo = 1, abs = 0, length--; length >= 0; length--, expo *= 2)
	{
		if (b[length] == '1')
		{
			abs += expo;
		}
	}

	return (abs);
}
