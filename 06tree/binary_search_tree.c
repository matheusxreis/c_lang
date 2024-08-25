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
};



node_b *
succ (node_b * tree)
{

  // GET SUCESSOR 

  if (tree == NULL)
    {
      return tree;
    }

  if (tree->left == NULL)
    {
      return tree;
    }

  return succ (tree->left);
}

node_b *
dele (node_b ** tree, eltype elem)
{

  if (*tree == NULL)
    {
      return *tree;
    }

  eltype current = getdata (*tree);

  if (elem > current)
    {
      // If element is bigger than current
      (*tree)->right = dele (&(*tree)->right, elem);

    }
  else if (elem < current)
    {
      // If element is smaller than current 
      (*tree)->left = dele (&(*tree)->left, elem);
    }
  else
    {
      // if element is equal the current

      if (!getleft (*tree))
	{
	  // Current has not left child or both
	  // Case not have both childs, its value will be substitute by null, because this will returns null and it will be reassign to left or right from father;
	  // Case have only right, it will be substitute by its right child
	  return (*tree)->right;

	}
      else if (!getright (*tree))
	{
	  //Current has not right child
	  return (*tree)->left;

	}
      else if (getright (*tree))
	{
	  // Current has both child
	  // We must find the sucessor inorder, and substitute
	  // its value by its sucessor and the right child

	  node_b *successor = succ ((*tree)->right);

	  (*tree)->right = dele (&(*tree)->right, successor->data);
	  setdata (*tree, getdata (successor));

	}
    }

  return *tree;
}


void
del (node_b ** tree, eltype elem)
{
  dele (tree, elem);
}
