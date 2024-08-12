#include"binary_search_tree.h"
#include <stdlib.h>

/* Complexity: O(h) */

void
insert (node_b ** tree, eltype elem)
{

  if (*tree == NULL)
    {
      *tree = maketree ();
      setdata (*tree, elem);
      return;
    }

  if (elem >= (*tree)->data)
    {
      insert (&(*tree)->right, elem);
    }
  else
    {
      insert (&(*tree)->left, elem);
    }

};

node_b *
search (node_b * tree, eltype elem)
{

  if (tree == NULL)
    {
      return NULL;
    }

  if (tree->data == elem)
    {
      return tree;
    };

  if (elem > tree->data)
    {
      return search (tree->right, elem);
    }
  else
    {
      return search (tree->left, elem);
    }
}

