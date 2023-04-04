#include "lists.h"

/**
 * free_listint - function that frees a listint_t list
 *
 * @head: the listint_t arg
 */

void free_listint(listint_t *head)
{
	listint_t *node = NULL;

	while (head)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
