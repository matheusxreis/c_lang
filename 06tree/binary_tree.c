#include"binary_tree.h"
#include <stdio.h>
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

eltype
getdata (node_b * tree)
{
  if (tree == NULL)
    {
      return 9688222;
    }
  return tree->data;
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


/// TRAVERSE A LIST

void
preorder (node_b * tree, void (*cb) (eltype * elem))
{

  // root
  // left
  // right
  if (tree == NULL)
    {
      return;
    }

  cb (&tree->data);
  preorder (tree->left, cb);
  preorder (tree->right, cb);

}


void
inorder (node_b * tree, void (*cb) (eltype * elem))
{

  // left
  // root
  // right
  if (tree == NULL)
    {
      return;
    }

  inorder (tree->left, cb);
  cb (&tree->data);
  inorder (tree->right, cb);
}

void
postorder (node_b * tree, void (*cb) (eltype * elem))
{

  // left
  // right
  // root
  if (tree == NULL)
    {
      return;
    }

  postorder (tree->left, cb);
  postorder (tree->right, cb);
  cb (&tree->data);
}
