#include "hash_tables.h"

/**
 * hash_table_get - func to retrieve value asso with a key
 * @ht: pointer to hash table
 * @key: the string key
 *
 * Return: string value aaso with the element or NULL
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	hash_node_t *node;
	unsigned long int index;

	if (!ht || !key || !*key)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node)
	{
		if (!strcmp(node->key, key))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}
