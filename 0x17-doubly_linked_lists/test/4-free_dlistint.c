#include "lists.h"
/**
 *free_dlistint - this function that frees a dlistint_t list.
 *@head: pointer to head
 */
void free_dlistint(dlistint_t *head)
{
	if (head == NULL)
		return;
	free_dlistint(head->next);
	free(head);
}
