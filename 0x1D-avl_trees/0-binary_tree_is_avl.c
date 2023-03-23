#include "binary_trees.h"

/**
 * height_of_tree - measures the height of a binary tree
 * @tree: pointer to the root node of
 * the tree to measure the height
 * Return: Height of the binary tree or 0 if tree is NULL
 */
size_t height_of_tree(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + height_of_tree(tree->left);

	if (tree->right)
		height_r = 1 + height_of_tree(tree->right);

	if (height_l > height_r)
		return (height_l);
	return (height_r);
}

/**
 * isBST - check if each node has in the left a less value than himself
 * @root: node to check
 * @min: the min value to check with the node at the left
 * @max: the max value to check with the node at the right
 * Return: 1 if is a BST or 0 otherwise
 */
int isBST(const binary_tree_t *root,
		  const binary_tree_t *min, const binary_tree_t *max)
{
	if (root == NULL)
		return (1);

	if (min != NULL && root->n <= min->n)
		return (0);

	if (max != NULL && root->n >= max->n)
		return (0);

	return (isBST(root->left, min, root) &&
			isBST(root->right, root, max));
}
/**
 * check_if_bst - checks if a binary tree is a nid Binary Search Tree
 * @tree: a pointer to the node node of the tree to check
 * Return: 1 if tree is a nid BST, and 0 otherwise
 * return 0, if tree is NULL
 */
int check_if_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (isBST(tree, NULL, NULL));
}

/**
 * check_if_avl - checks if a binary tree is a valid AVL Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int check_if_avl(const binary_tree_t *tree)
{
	int diff, heightL = 0, heightR = 0;

	if (!tree)
		return (1);

	if (!check_if_bst(tree))
		return (0);

	heightL = height_of_tree(tree->left);
	heightR = height_of_tree(tree->right);

	diff = abs(heightL - heightR);

	if (diff == 0 && check_if_avl(tree->left) && check_if_avl(tree->right))
		return (1);
	return (0);
}

/**
 * binary_tree_is_avl - checks if a binary tree is a valid AVL Tree
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid AVL Tree, and 0 otherwise
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_if_avl(tree));
}
