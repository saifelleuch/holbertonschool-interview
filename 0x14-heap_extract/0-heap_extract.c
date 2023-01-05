#include "binary_trees.h"
/**
 * get_size_of_tree - get the size of the tree
 * @root: pointer to the head
 * Return: the size of the tree
 **/
int get_size_of_tree(heap_t *root)
{
	if (root == NULL)
		return (0);
	return (1 + get_size_of_tree(root->left) + get_size_of_tree(root->right));
}
/**
 * swap_nodes - swaps nodes values
 * @x: the node to swap value of
 * @y: the node to swap value of
 * Return: first node value
 **/
heap_t *swap_nodes(heap_t *x, heap_t *y)
{
	x->n = x->n * y->n;
	y->n = x->n / y->n;
	x->n = x->n / y->n;
	return (x);
}
/**
 * get_lastnode - returns the last node
 * @root: pointer to the root node
 * @size: size of the tree
 * Return: the found node ptr
 **/
heap_t *get_lastnode(heap_t *root, int size)
{
	int x_idx = 0;
	int mask  = 0;

	for (; 1 << (x_idx + 1) <= size; x_idx++)
		;
	for (x_idx--; x_idx >= 0; x_idx--)
	{
		mask = 1 << x_idx;
		if (size & mask)
			root = root->right;
		else
			root = root->left;
	}
	return (root);
}

/**
 * convert_tree_to_heap - converts the tree into a max heap tree
 * @root: pointer to the root node
 */
void convert_tree_to_heap(heap_t *root)
{
	heap_t *max = NULL;
	int first = 0;

	while (max || !first)
	{
		max = NULL;
		first = 1;
		if (root->left && root->left->n > root->n)
			max = root->left;
		if (root->right && root->right->n > root->n &&
				(max && root->right->n > max->n))
			max = root->right;
		if (max)
			root = swap_nodes(max, root);
	}
}
/**
 * heap_extract - function that extracts the root node
 * of a Max Binary Heap
 * @root:  is a double pointer to the root node of the heap
 * Return: the value stored in the root node or 0
 */
int heap_extract(heap_t **root)
{
	int max = (*root)->n;
	int size = get_size_of_tree(*root);
	heap_t *last_node = get_lastnode(*root, size);

	swap_nodes(last_node, *root);
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;
	free(last_node);
	convert_tree_to_heap(*root);
	return (max);
}
