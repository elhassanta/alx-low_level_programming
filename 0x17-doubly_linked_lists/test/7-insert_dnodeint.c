#include "lists.h"
/**
 *insert_dnodeint_at_index - this function insert node at idx
 *@h: pointer to a head of dlinked list
 *@idx: index of a node to be inserted
 *@n: data of an inserted node
 *Return: return pointer to an inserted node or NULL
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *tmp = NULL, *previous = NULL, *tmp1 = NULL;

	if (h == NULL)
		return (NULL);
	if (idx == 0)
	{
		tmp = add_dnodeint(h, n);
		if (tmp)
		{
			*h = tmp;
			return (*h);
		}
	}
	tmp = *h;
	while (tmp != NULL && idx > 0)
	{
		previous = tmp;
		tmp = tmp->next;
		idx--;
	}
	if (idx > 0)
		return (NULL);
	if (tmp == NULL && previous != NULL)
	{
		tmp = add_dnodeint_end(h, n);
		return (tmp);
	}
	tmp1 = malloc(sizeof(dlistint_t));
	if (tmp1 == NULL)
		return (NULL);
	tmp1->n = n;
	tmp1->next = tmp;
	tmp1->prev = previous;
	tmp->prev = tmp1;
	previous->next = tmp1;
	return (tmp1);
}
