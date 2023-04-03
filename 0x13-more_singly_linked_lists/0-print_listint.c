#include "lists.h"
#include <stdio.h>

/**
 * print_listint - function with arg
 * @h: linked list head
 *
 * Description: prints all the elements in list
 * Return: number of nodes in list
 */
size_t print_listint(const listint_t *h)
{
	size_t counter;

	for (counter = 0; h != NULL; counter++, h = h->next)
		printf("%d\n", h->n);

	return (counter);
}
