#include "lists.h"
/**
 *delete_dnodeint_at_index - this function delete a node in dlinked list
 *@head: pointer point to the head of dlinked list
 *@index: the index of a node to be deleted
 *Return: return 1 in success other ways -1
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *tmp = (*head), *previous = NULL, *nex = NULL;

	if (head == NULL)
		return (-1);
	if (index == 0)
	{
		if ((*head)->next)
		{
			(*head) = (*head)->next;
			(*head)->prev = NULL;
			free(tmp);
			return (1);
		}
		free(tmp);
		*head = NULL;
		return (1);
	}
	while (tmp)
	{
		previous = tmp;
		tmp = tmp->next;
		index--;
	}
	if (tmp == NULL || index > 0)
		return (-1);
	nex = tmp->next;
	if (nex == NULL)
	{
		previous->next = NULL;
		free(tmp);
		return (1);
	}
	previous->next = nex;
	nex->prev = previous;
	free(tmp);
	return (1);
}
