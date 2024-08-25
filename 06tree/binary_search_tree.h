// BINARY SEARCH TREE
//

#include "binary_tree.c"

/**
 *
 * @brief Inserts the elem in the left node case be less
 * than the father, ou in right case be equal or bigger
 * than the father
 * @param tree The tree which elem will be inserted
 * @param elem The element to be inserted
 */
void insert (node_b ** tree, eltype elem);

/**
 *
 * @brief Search the element in the tree as the binary search algorithm
 * @param tree The tree which elem will be searched
 * @param elem The element to be searched
 * @return The node or NULL
 */
node_b *search (node_b * tree, eltype elem);


/**
 *
 * @brief Delete the elem from the BST
 * @param tree The tree which elem will be deleted
 * @param elem The element to be deleted
 * @return void
 */
void del (node_b ** tree, eltype elem);
