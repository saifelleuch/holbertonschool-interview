#include "lists.h"

/**
* find_listint_loop - a function that finds the loop in a linked list
* @head: pointer to the linked list
* Return: The address of the node where the loop
* starts, or NULL if there is no loop
**/
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *x = head;
	listint_t *y = head;

	if (!head)
		return (NULL);
	while (x->next && y->next->next)
	{
		x = x->next;
		y = y->next->next;
		if (x == y)
		{
			x = head;
			while (x != y)
			{
				x = x->next;
				y = y->next;
			}
			return (y);
		}
	}
	return (NULL);
}
