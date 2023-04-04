#include "lists.h"

/**
 * insert_nodeint_at_index - function that inserts a newData node
 * at a given position
 *
 * @head: the listint_t argv
 * @idx: index to insert argv
 * @n: the int data node argv
 *
 * Return: the address of the newData node
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int i = 0;
	listint_t *newData = NULL, *temp;

	if (head)
	{
		newData = malloc(sizeof(listint_t));
		if (newData)
		{
			newData->n = n;
			newData->next = NULL;
			temp = *head;

			if (idx == 0)
			{
				newData->next = *head;
				*head = newData;
			}
			else
			{
				while (i != idx - 1 && temp)
				{
					temp = temp->next;
					i++;
				}
				if (!temp)
				{
					free(newData);
					return (NULL);
				}
				else
				{
					newData->next = temp->next;
					temp->next = newData;

				}
			}
		}
	}
	return (newData);
}
