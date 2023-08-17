#include "lists.h"
/**
 *add_dnodeint - funtion that add a head
 *@n: data to insert into the node
 *@head: pointer point to the head of linked list
 *Return: return a node in linked list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *tmp = (*head);
	dlistint_t *tmp2 = NULL;

	if (tmp == NULL)
	{
		tmp = malloc(sizeof(dlistint_t));
		if (tmp == NULL)
			return (NULL);
		tmp->n = n;
		tmp->next = NULL;
		tmp->prev = NULL;
		(*head) = tmp;
		return (tmp);
	}
	while (tmp->prev)
	{
		tmp = tmp->prev;
	}
	tmp2 = malloc(sizeof(dlistint_t));
	if (tmp2 == NULL)
		return (NULL);
	tmp2->n = n;
	tmp2->next = tmp;
	tmp2->prev = NULL;
	tmp->prev = tmp2;
	(*head) = tmp2;
	return (tmp2);
}
