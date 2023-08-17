#include "lists.h"
/**
 *get_dnodeint_at_index - this function return node at index
 *@head: pointer to the a head node
 *@index: the index of the node we want to retrieve
 *Return: return the node in index or NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (head == NULL)
		return (NULL);
	while (head != NULL && index > 0)
	{
		head = head->next;
		index--;
	}
	if (index == 0 && head != NULL)
		return (head);
	return (NULL);
}
