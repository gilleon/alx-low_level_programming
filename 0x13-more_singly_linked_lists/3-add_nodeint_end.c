#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node
 * at the end of a listint_t list
 *
 * @head: the listint_t argument (head)
 * @n: the second arg
 *
 * Return: a pointer to the added node
 */

listint_t	*add_nodeint_end(listint_t **head, const int n)
{
	listint_t *node = *head;
	listint_t *newNode = NULL;

	newNode = malloc(sizeof(listint_t));
	if (newNode)
	{
		newNode->n = n;
		newNode->next = NULL;

		if (!(*head))
		{
			*head = newNode;
		}
		else
		{
			while (node->next)
			{
				node = node->next;
			}
			node->next = newNode;
		}
	}
	return (newNode);
}
