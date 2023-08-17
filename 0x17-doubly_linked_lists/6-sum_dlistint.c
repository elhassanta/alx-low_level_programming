#include "lists.h"
/**
 *sum_dlistint - function calculate sum of dlinked list
 *head: pointer point to head of dlinked list
 *Return: return sum of dlinked list
 */
int sum_dlistint(dlistint_t *head)
{
	int sum = 0;

	if (head == NULL)
		return (sum);
	while (head)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
