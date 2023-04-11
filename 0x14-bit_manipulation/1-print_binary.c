#include "main.h"
#include <stdio.h>

/**
 * print_binary - function that prints the binary
 * representation of a number
 * @n: method argv
 */
void print_binary(unsigned long int n)
{
	unsigned long int opp;
	int intva;

	if (n == 0)
	{
		printf("0");
		return;
	}

	for (opp = n, intva = 0; (opp >>= 1) > 0; intva++)
		;

	for (; intva >= 0; intva--)
	{
		if ((n >> intva) & 1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
	}
}
