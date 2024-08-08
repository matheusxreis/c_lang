#include<stdbool.h>

typedef int eltype;

typedef struct nodetype
{
  eltype value;
  struct nodetype *next;
} node;

typedef struct
{
  node *items;
} Stack;


void push (Stack * s, eltype item);
eltype pop (Stack * s);
eltype stacktop (Stack * s);
Stack create ();
bool empty (Stack * s);
