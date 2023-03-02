#include "list.h"

/**
 * add_node_end - Add a new node to the end of a double circular linked list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_end(List **list, char *str)
{
	List *the_new_node;
	char *strNode;

	if (!list)
		return (NULL);
	the_new_node = malloc(sizeof(List));
	if (!the_new_node)
		return (NULL);
	strNode = strdup(str);
	if (!strNode)
	{
		free(the_new_node);
		return (NULL);
	}
	the_new_node->str = strNode;
	if (!*list)
	{
		the_new_node->next = the_new_node;
		the_new_node->prev = the_new_node;
		*list = the_new_node;
		return (the_new_node);
	}
	the_new_node->next = *list;
	the_new_node->prev = (*list)->prev;
	(*list)->prev = the_new_node;
	the_new_node->prev->next = the_new_node;
	return (the_new_node);
}

/**
 * add_node_begin - Add a new node to the beginning of a double circular l-list
 * @list: the list to modify
 * @str: the string to copy into the new node
 * Return: Address of the new node, or NULL on failure
 */

List *add_node_begin(List **list, char *str)
{
	List *the_new_node;
	char *strNode;

	if (!list)
		return (NULL);
	the_new_node = malloc(sizeof(List));
	if (!the_new_node)
		return (NULL);
	strNode = strdup(str);
	if (!strNode)
	{
		free(the_new_node);
		return (NULL);
	}
	the_new_node->str = strNode;
	if (*list)
	{
		the_new_node->next = *list;
		the_new_node->prev = (*list)->prev;
		(*list)->prev = the_new_node;
		if (the_new_node->prev)
			the_new_node->prev->next = the_new_node;
	}
	else
	{
		the_new_node->prev = the_new_node;
		the_new_node->next = the_new_node;
	}
	*list = the_new_node;
	return (the_new_node);
}
