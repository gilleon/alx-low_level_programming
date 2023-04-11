#include "main.h"
#include <stdio.h>
/**
 * clear_bit - function that sets the value of
 * a bit to 0 at a given index
 * @n: pointer argv
 * @index: index argv
 * Return: 1 if it worked, or -1 if an error occurred
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	unsigned int reserve;

	if (index > 64)
	{
		return (-1);
	}

	reserve = index;
	for (i = 1; reserve > 0; i *= 2, reserve--)
		;

	if ((*n >> index) & 1)
	{
		*n -= i;
	}

	return (1);
}
