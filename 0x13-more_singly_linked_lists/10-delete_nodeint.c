#include "lists.h"

/**
 * delete_nodeint_at_index - function that deletes the node at index index
 *
 * @head: the listint_t argv
 * @index: the index argv
 *
 * Return: 1 if succeeded, -1 if failed
 */

int	delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i = 0;
	listint_t *temp;
	listint_t *delNode = *head;

	if (*head && head)
	{
		if (index == 0)
		{
			temp = *head;
			*head = (*head)->next;
			free(temp);
		}
		else
		{
			while (i != index && delNode)
			{
				temp = delNode;
				delNode = temp->next;
				i++;
			}
			if (i == index && delNode)
			{
				temp->next = delNode->next;
				free(delNode);
			}
			else
				return (-1);
		}
		return (1);
	}
	return (-1);
}
