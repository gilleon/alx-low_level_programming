#include "lists.h"

/**
 * free_listint2 - a function that frees a listint_t list
 *
 * @head: the listint_t arg
 */

void	free_listint2(listint_t **head)
{
	listint_t *node = NULL;

	if (head)
	{
		while (*head)
		{
			node = *head;
			*head = (*head)->next;
			free(node);
		}
		*head = NULL;
	}
}
