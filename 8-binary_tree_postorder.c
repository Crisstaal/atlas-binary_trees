#include "binary_trees.h"
#include <stddef.h>

/**
 * binary_tree_postorder - Traverses a binary tree using post-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
 *
 * Description: The value in each node is passed as a parameter to the function.
 * If `tree` or `func` is NULL, do nothing.
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	/* Traverse the left subtree */
	binary_tree_postorder(tree->left, func);

	/* Traverse the right subtree */
	binary_tree_postorder(tree->right, func);

	/* Call the function on the current node */
	func(tree->n);
}
