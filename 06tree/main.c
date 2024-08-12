#include<stdio.h>
#include"binary_search_tree.c"



void
print (eltype * elem)
{
  printf (" %d ", *elem);
};


int
main ()
{


//  int list[16] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5, 4 };
//  find_repeat_elements (list, sizeof (list) / sizeof (int));

  node_b *tree;
  insert (&tree, 14);
  insert (&tree, 15);
  insert (&tree, 4);
  insert (&tree, 9);
  insert (&tree, 7);
  insert (&tree, 18);
  insert (&tree, 3);
  insert (&tree, 5);
  insert (&tree, 16);
  insert (&tree, 4);
  insert (&tree, 20);
  insert (&tree, 17);
  insert (&tree, 9);
  insert (&tree, 14);
  insert (&tree, 5);

  printf ("in-order: ");
  inorder (tree, &print);
  printf ("\n");

  printf ("searching;...27 => %d\n", getdata (search (tree, 27)));
  printf ("searching;...17 => %d\n", getdata (search (tree, 17)));



}
