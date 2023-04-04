#include "lists.h"

/**
 * reverse_listint - function that reverses a listint_t linked list
 *
 * @head: the listint_t argv
 *
 * Return: a pointer to the first node of the reversed list
 */

listint_t *reverse_listint(listint_t **head)
{
	listint_t *previous = NULL;
	listint_t *current = *head;

	if (*head)
	{
		while (current)
		{
			*head = (*head)->next;
			current->next = previous;
			previous = current;
			current = *head;
		}
		*head = previous;
	}
	return (*head);
}
