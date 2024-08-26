#include<stdio.h>
#include"expression_tree.c"


void
print (eltype * elem)
{
  printf (" %c ",  *elem);
};


int
main ()
{
  node_b* tree = maketree();
  char* str = "AB+C-";
  printf("postfix: %s\n", str);

  from_postfix(str, &tree);
  
  printf("infix: ");
  inorder(tree, &print);
  printf("\n");
  
  printf("postfix: ");
  postorder(tree, &print);
  printf("\n");


  printf("prefix: ");
  preorder(tree, &print);
  printf("\n");
}
