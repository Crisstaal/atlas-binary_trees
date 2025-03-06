#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child
 * @tree: A pointer to the root node of the tree to count the nodes
 * 
 * Return: The number of nodes with at least one child, or 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    size_t count = 0;

    if (tree == NULL)
        return (0);

    /* Check if the current node has at least one child*/
    if (tree->left || tree->right)
        count = 1;

    count += binary_tree_nodes(tree->left);
    count += binary_tree_nodes(tree->right);

    return (count);
}
