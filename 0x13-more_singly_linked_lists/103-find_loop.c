#include "lists.h"

/**
 * find_listint_loop - function that finds the loop in a linked list
 *
 * @head: the listint_t argv
 *
 * Return:  the address of the node where the loop start
 */

listint_t	*find_listint_loop(listint_t *head)
{
	listint_t *current = head, *curr_pace = head;

	if (head && head->next)
	{
		while (current && curr_pace && curr_pace->next)
		{
			current = current->next;
			curr_pace = curr_pace->next->next;

			if (current == curr_pace)
			{
				current = head;
				while (current != curr_pace)
				{
					current = current->next;
					curr_pace = curr_pace->next;
				}
				return (current);
			}
		}
	}
	return (NULL);
}
