#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * is_palindrome - checks if a singly linked list is a palindrome.
 * @head: pointer to pointer of first node of listint_t list
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
*/
int is_palindrome(listint_t **head)
{
	int list[10000];
	int i = 0, back = 0;
	int tmp = 1;

	while (*head)
	{
		list[i] = (*head)->n;
		*head = (*head)->next;
		i++;
	}
	i--;

	while (i > back && tmp != 0)
	{
		if (list[i] != list[back])
			tmp = 0;
		i--;
		back++;
	}
	return (tmp);
}
