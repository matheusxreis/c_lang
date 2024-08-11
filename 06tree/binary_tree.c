#include"binary_tree.h"
#include<stdlib.h>

node_b *
maketree ()
{
  node_b *tree = (node_b *) malloc (sizeof (node_b));

  tree->left = NULL;
  tree->right = NULL;
  tree->father = NULL;

  return tree;
};

void
setdata (node_b * tree, eltype value)
{
  tree->data = value;
}

void
setright (node_b * tree, eltype value)
{
  if (tree->right == NULL)
    {
      tree->right = maketree ();
    }
  tree->right->father = tree;
  tree->right->data = value;
}

void
setleft (node_b * tree, eltype value)
{
  if (tree->left == NULL)
    {
      tree->left = maketree ();
    }

  tree->left->father = tree;
  tree->left->data = value;
}

node_b *
getright (node_b * tree)
{
  return tree->right;
}

node_b *
getleft (node_b * tree)
{
  return tree->left;
};

node_b *
getfather (node_b * tree)
{
  return tree->father;
}

int
isleft (node_b * node)
{
  if (node->father == NULL)
    {
      return 0;
    }

  return getleft (node->father) == node;
}


int
isright (node_b * node)
{
  if (node->father == NULL)
    {
      return 0;
    }

  return getright (node->father) == node;
}
