#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 * @node: A pointer to the node to find the sibling of
 *
 * Return: A pointer to the sibling node, or NULL if no sibling or invalid input
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    /* Check for NULL node or parent */
    if (node == NULL || node->parent == NULL)
        return (NULL);

    /* Check if the node is the left child of its parent */
    if (node == node->parent->left)
        return (node->parent->right); /* Return the right sibling */
    
    /* Check if the node is the right child of its parent */
    if (node == node->parent->right)
        return (node->parent->left); /* Return the left sibling */

    return (NULL); /* Return NULL if no sibling exists */
}
