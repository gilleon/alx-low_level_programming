#include "main.h"
#include <stdio.h>
/**
 * get_bit - unction that sets the value of a
 * bit to 1 at a given index
 * @n: number to assess arg
 * @index: index argv
 * Return: 1 if it worked, or -1 if an error occurred
 */
int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int tempVal;

	if (index > 64)
	{
		return (-1);
	}

	tempVal = n >> index;

	return (tempVal & 1);
}
