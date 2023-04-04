#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list
 *
 * @head: the listint_t argument (head)
 *
 * Return: the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *curr, *contend;
	size_t counter, i;

	curr = head;
	counter = 0;

	while (curr != NULL)
	{
		contend = head;
		for (i = 0; i < counter; i++)
		{
			if (contend == curr)
			{
				printf("-> [%p] %d\n", (void *)curr, curr->n);
				return (counter);
			}

			contend = contend->next;
		}
		printf("[%p] %d\n", (void *)curr, curr->n);
		curr = curr->next;
		counter++;
	}

	return (counter);
}
