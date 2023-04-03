#include "lists.h"

/**
 * listint_len - returns the number of elements in a linked listint_t list
 * @h: linked list head
 * Return: number of elements
 */
size_t listint_len(const listint_t *h)
{
	size_t counter;

	for (counter = 0; h != NULL; counter++, h = h->next)
		;

	return (counter);
}
