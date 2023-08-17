#include "lists.h"
/**
 *add_dnodeint_end - this function add a node at the end of a dlinked list
 *@head: pointer point to head of dlinked list
 *@n: data to add into a node added to dlinked list
 *Return: return address of the node added or NULL
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *tmp = (*head);
	dlistint_t *tmp1 = NULL;

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
	while (tmp->next)
		tmp = tmp->next;
	tmp1 = malloc(sizeof(dlistint_t));
	if (tmp1 == NULL)
		return (NULL);
	tmp1->n = n;
	tmp1->next = NULL;
	tmp1->prev = tmp;
	tmp->next = tmp1;
	return (tmp1);
}
