#include "binary_trees.h"

/**
 * get_depth - Measures the depth of a binary tree.
 * @tree: Pointer to the root node of the tree.
 *
 * Return: The depth of the tree.
 */
int get_depth(const binary_tree_t *tree)
{
	int depth = 0;

	while (tree)
	{
		depth++;
		tree = tree->left;
	}
	return (depth);
}

/**
 * is_perfect - Checks recursively if a tree is perfect.
 * @tree: Pointer to the root node of the tree.
 * @depth: Depth of the tree.
 * @level: Level of the current node.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int is_perfect(const binary_tree_t *tree, int depth, int level)
{
	if (tree == NULL)
		return (1);

	if (tree->left == NULL && tree->right == NULL)
		return (level == depth);

	if (tree->left == NULL || tree->right == NULL)
		return (0);

	return (is_perfect(tree->left, depth, level + 1) &&
		is_perfect(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is perfect, 0 otherwise.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int depth;

	if (tree == NULL)
		return (0);

	depth = get_depth(tree);
	return (is_perfect(tree, depth, 0));
}
