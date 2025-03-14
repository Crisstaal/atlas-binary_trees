#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: A pointer to the node to find the uncle of
 *
 * Return: A pointer to the uncle node, or NULL if no uncle or invalid input
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	/* Check if the node or its parent is NULL */
	if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
		return (NULL);

	if (node->parent == node->parent->parent->left)
		return (node->parent->parent->right);

	if (node->parent == node->parent->parent->right)
		return (node->parent->parent->left);

	return (NULL); /* If no uncle exists */
}
