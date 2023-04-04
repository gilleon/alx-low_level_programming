#include "lists.h"

/**
 * checkLoop - function to checks if the linked list has not looped
 *
 * @begin: the begining argv
 * @node: the current node argv
 * @i: the current postion argv
 *
 * Return: 1 if loop return true, 0 if there is a loop
 */

size_t	checkLoop(const listint_t *begin, const listint_t *node, size_t i)
{
	size_t check = 0;

	while (begin != node)
	{
		begin = begin->next;
		check++;
	}

	return ((check == i) ? 1 : 0);
}

/**
 * print_listint_safe - function that prints a listint_t linked list
 *
 * @head: the listint_t argv
 *
 * Return: the number of nodes in the list
 */

size_t	print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *begin = head;

	if (head)
	{
		while (head && checkLoop(begin, head, count))
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;

			count++;
		}

		if (head)
			printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (count);
}
