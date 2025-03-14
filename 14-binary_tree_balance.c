#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height; /* Declare variables at the start */

	if (tree == NULL)
		return 0;

	/* Recursively calculate the height of the left and right subtrees */
	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	/* Return the greater of the two heights, plus 1 for the current node */
	return (left_height > right_height ? left_height : right_height) + 1;
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the balance factor.
 *
 * Return: The balance factor of the tree. If tree is NULL, return 0.
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return 0;

	/* Calculate balance factor: height(left) - height(right) */
	return binary_tree_height(tree->left) - binary_tree_height(tree->right);
}
