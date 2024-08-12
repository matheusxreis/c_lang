



#include "binary_tree.c"
#include <stdio.h>

/*
 *
 * Finding elemenets duplicates in a arry using a Binary Tree
 * Complexity: O(n*h)  
 * Using an array, or list the complexity would be O(n*n)
 *
 */

void
repeat_w_tree (int *arr, int index, node_b ** tree)
{

  if (*tree == NULL)
    {
    /**
     * If there is no node with arr[index] value, create one
    **/
      *tree = maketree ();
      setdata (*tree, arr[index]);
      return;
    }

  if ((*tree)->data == arr[index])
    {
      /* If a node with arr[index] value already exist, print it */
      printf ("Data repeat = %d\n", arr[index]);
      return;

    }
  else if (arr[index] > (*tree)->data)
    {
      /* If arr[index] > value from the node, add it on the right (on case it exist on the right, print it) */
      repeat_w_tree (arr, index, &(*tree)->right);

    }
  else
    {
      /* Otherwise, add it on the left (or case it exist on the left, print it) */
      repeat_w_tree (arr, index, &(*tree)->left);
    };


};


void
print (eltype * elem)
{
  printf (" %d ", *elem);
};

void
find_repeat_elements (int *arr, int size)
{


  node_b *tree = maketree ();
  setdata (tree, arr[0]);
  for (int i = 0; i < size - 1; i++)
    {
      repeat_w_tree (arr, 1 + i, &tree);
    }


  printf ("pre-order: ");
  preorder (tree, &print);
  printf ("\n");

  printf ("in-order: ");
  inorder (tree, &print);
  printf ("\n");

  printf ("post-order:");
  postorder (tree, &print);
  printf ("\n");
}
