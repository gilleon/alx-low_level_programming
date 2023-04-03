#include "lists.h"

/**
 * add_nodeint - add a state node at the beginning of a `listint_t` list
 * @head: double pointer to head node
 * @n: int value to store in state node
 * Return: Address of state element or NULL if failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *clasp;
	listint_t *state;

	clasp = *head;
	state = malloc(sizeof(listint_t));
	if (state == NULL)
		return (NULL);
	state->n = n;
	*head = state;

	if (clasp == NULL)
		state->next = NULL;
	else
		state->next = clasp;

	return (state);
}
