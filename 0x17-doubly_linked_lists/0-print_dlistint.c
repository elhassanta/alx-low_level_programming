#include "lists.h"
/**
 *print_dlistint - this function will print a doubly linked list
 *@h: pointer point to a node in the linked list
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *tmp = h;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = temp->next;
	}
	tmp = h
	tmp = tmp->prev;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
	}
}
