#include "lists.h"
/**
 *dlistint_len - this function calculate the length of linked list
 *@h: parameter pointer point to a node in linked list
 *Return: return the length of a linked list
 */
size_t dlistint_len(const dlistint_t *h)
{
	dlistint_t tmp = (dllistint_t *)h;
	size_t len = 0;

	if (h == NULL)
		return (0);
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	tmp = (listint_t *)h;
	tmp = tmp->prev;
	while (tmp)
	{
		len++;
		tmp = tmp->prev;
	}
	return (len);
}
