#include "hash_tables.h"

/**
 * key_index - function for the index of the key
 * @key: the key
 * @size: the size of the array of the hash table
 * Return: index of the key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	if (!size)
		return (0);
	return (hash_djb2(key) % size);
}
