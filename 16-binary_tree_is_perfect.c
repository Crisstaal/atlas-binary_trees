#include "binary_trees.h"

/**
 * tree_depth - Measures the depth of a tree
 * @tree: A pointer to the root node of the tree
 * Return: The depth of the tree
 */
static size_t tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;
    
    while (tree)
    {
        depth++;
        tree = tree->left;
    }
    return (depth);
}

/**
 * is_perfect_helper - Recursively checks if a tree is perfect
 * @tree: A pointer to the root node of the tree to check
 * @depth: The depth of the tree
 * @level: The current level of the node
 * Return: 1 if the tree is perfect, 0 otherwise
 */
static int is_perfect_helper(const binary_tree_t *tree, size_t depth, size_t level)
{
    if (!tree)
        return (1);

    // If it's a leaf, check if it's at the correct level
    if (!tree->left && !tree->right)
        return (level == depth);

    // If it's not a leaf and has less than two children, it's not perfect
    if (!tree->left || !tree->right)
        return (0);

    // Recursively check both subtrees
    return (is_perfect_helper(tree->left, depth, level + 1) &&
            is_perfect_helper(tree->right, depth, level + 1));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: A pointer to the root node of the tree
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    size_t depth = tree_depth(tree);
    return (is_perfect_helper(tree, depth, 0));
}
