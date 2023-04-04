#include "lists.h"

/**
 * pop_listint - function that deletes the head node
 *
 * @head: the listint_t argv
 *
 * Return: the head node’s data (n)
 */

int	pop_listint(listint_t **head)
{
	int data = 0;
	listint_t *temp = NULL;

	if (*head)
	{
		temp = *head;
		data = (*head)->n;
		*head = (*head)->next;
		free(temp);
	}
	return (data);
}
