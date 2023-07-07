#include "hash_tables.h"

/**
 * hash_djb2 - hashing function
 * @str: the key parsed
 * Return: hash index
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long hash = 5381;
	int x;

	for (x = *str++; x; x = *str++)
		hash = ((hash << 5) + hash) + x;

	return (hash);
}
