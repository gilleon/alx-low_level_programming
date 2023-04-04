#include "lists.h"

/**
 * free_listint_safe - function can free lists with a loop
 *
 * @h: the listint_t argv
 *
 * Return: the size of the list that was free’d
 */

size_t free_listint_safe(listint_t **h)
{
	listint_t *curr, *hold;
	size_t count;

	counter = 0;
	curr = *h;
	while (curr != NULL)
	{
		counter++;
		hold = curr;
		curr = curr->next;
		free(hold);

		if (hold < curr)
			break;
	}
	*h = NULL;

	return (counter);
}
