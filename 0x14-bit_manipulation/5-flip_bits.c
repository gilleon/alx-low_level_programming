#include "main.h"
#include <stdio.h>

/**
 * flip_bits - function to convert one number to another number
 * @n: first argv
 * @m: secondargv
 * Return: bits you would need to flip
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int interv;
	int cnt;

	interv = n ^ m;
	cnt = 0;

	while (interv)
	{
		cnt++;
		interv &= (interv - 1);
	}

	return (cnt);
}
