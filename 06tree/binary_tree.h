///
/// A binary tree is a finite set of elements
/// that is empty or partioned 
/// in three disjoint subsets. 
/// The fist subset is the root,
/// ant there is others two subsets,
/// the left and right.
///       === root ===
///     /            \
///   left          right
///  /    \         /
// left2  right2   left

#ifndef ELTYPE
#define ELTYPE
typedef int eltype;
#endif

typedef struct nodetype_b
{
  eltype data;
  struct nodetype_b *left;
  struct nodetype_b *right;
  struct nodetype_b *father;
} node_b;

/**
 * @brief Create a binary tree structure
 * @return A node pointer, representing a binary tree structure
 */
node_b *maketree ();

/**
 * @brief Set a value for a node from a binary tree structure
 * @param node The node to data be inserted
 * @param value The value to be inserted
 * @return void
 */
void setdata (node_b * node, eltype value);


/**
 * @brief Set a subtree in left node from a tree
 * @param node The node to be inserted as subtree
 * @param value The value to be inserted
 * @return void
 */
void setleft (node_b * node, eltype value);

/**
 : @brief Set a subtree in right node_p from a tree
 * @param node The node to be inserted as subtree
 * @param value The value to be inserted
 * @return void
 */
void setright (node_b * node, eltype value);

/**
 * @brief Get a subtree in right node from a tree
 * @param node The tree which you want get the right subtree
 * @return The node that represents the right subtree
 */
node_b *getright (node_b * node);

/**
 * @brief Get a subtree in left node from a tree
 * @param node The tree which you want get the left subtree
 * @return The node that represents the left subtree
 */
node_b *getleft (node_b * node);

/**
 * @brief Get the fater from subtree
 * @param node The subtree which you want get the father
 * @return The node that represents the father
 */
node_b *getfather (node_b * node);

/**
 * @brief Verify if current node is a left child
 * @param node The tree which apply
 * @Returns true if is a left child, otherwise returns false
 */
int isleft(node_b * node);

/**
 * @brief Verify if current node is a right child
 * @param node The tree which apply
 * @Returns true if is a right child, otherwise returns false
 */
int isright(node_b * node); 
