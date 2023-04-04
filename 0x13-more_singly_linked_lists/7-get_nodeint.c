#include "lists.h"

/**
 * get_nodeint_at_index - function that returns the
 * nth node of a listint_t
 *
 * @head: the listint_t argv
 * @index: the index argv
 *
 * Return: the nth node of the list
 */

listint_t	*get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int n = 0;

	while (n != index && head)
	{
		head = head->next;
		n++;
	}

	if (n == index && head)
	{
		return (head);
	}
	return (NULL);
}
