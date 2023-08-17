#include "lists.h"
/**
 *print_dlistint - this function will print a doubly linked list
 *@h: pointer point to a node in the linked list
 *Return: return number of elements printed
 */
size_t print_dlistint(const dlistint_t *h)
{
	dlistint_t *tmp = (dlistint_t *)h;
	size_t ele = 0;

	if (h == NULL)
		return (0);
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
		ele++;
	}
	tmp = (dlistint_t *)h;
	tmp = tmp->prev;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->prev;
		ele++;
	}
	return (ele);
}
