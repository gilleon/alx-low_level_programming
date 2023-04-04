#include "lists.h"

/**
 * sum_listint - a function that returns the sum of all the data (n)
 *
 * @head: the listint_t argv
 *
 * Return: the sum of all data
 */

int	sum_listint(listint_t *head)
{
	int sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return (sum);
}
