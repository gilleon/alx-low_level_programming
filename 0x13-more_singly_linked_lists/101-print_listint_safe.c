#include "lists.h"
#include <stdio.h>

/**
 * print_listint_safe - function that prints a listint_t linked list
 *
 * @head: the listint_t argv
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr;
	size_t counter;
	const listint_t *clasp;

	curr = head;
	if (curr == NULL)
		exit(98);

	counter = 0;
	while (curr != NULL)
	{
		clasp = curr;
		curr = curr->next;
		counter++;
		printf("[%p] %d\n", (void *)clasp, clasp->n);

		if (clasp < curr)
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			break;
		}
	}

	return (counter);
}
