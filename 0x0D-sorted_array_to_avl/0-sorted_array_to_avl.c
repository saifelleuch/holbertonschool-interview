#include "binary_trees.h"
/**
 * binary_search - recursive function that builds an AVL tree from an array
 * @array: pointer to array
 * @first: first element
 * @last: last element
 * @parent: parent node
 * Return: a pointer to the root node of the created
 * AVL tree, or NULL on failure.
 **/
avl_t *binary_search(int *array, int first, int last, avl_t *parent)
{
	int middle;
	avl_t *node;

	if (first > last)
		return (NULL);
	middle = (first + last) / 2;
	node = malloc(sizeof(avl_t));
	if (!node)
		return (NULL);
	node->n = array[middle];
	node->parent = parent;
	node->left = binary_search(array, first, middle - 1, node);
	node->right = binary_search(array, middle + 1, last, node);
	return (node);
}
/**
 * sorted_array_to_avl - function that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: a pointer to the root node of the created
 * AVL tree, or NULL on failure.
 **/
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array)
		return (NULL);
	return (binary_search(array, 0, size - 1, NULL));
}
