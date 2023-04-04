#include "lists.h"

/**
 * free_listint_safe - function can free lists with a loop
 *
 * @head: the listint_t argv
 *
 * Return: the size of the list that was free’d
 */

size_t	free_listint_safe(listint_t **head)
{
	size_t counter = 0, i = 0;
	listint_t *begin = *head, *tmp;

	if (*head)
	{
		while (*head && checkLoop(begin, *head, counter))
		{
			tmp = (*head)->next;
			*head = tmp;

			counter++;
		}

		*head = begin;
		while (i < counter)
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
			i++;
		}

		if (*head)
			*head = NULL;
	}
	return (counter);
}
