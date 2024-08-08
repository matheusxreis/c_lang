#include<stdio.h>
#include<stdlib.h>
#include"stack.h"




Stack
create ()
{
  Stack s;
  s.items = NULL;
  return s;
}

void
push (Stack * s, eltype item)
{

  node *n = (node *) malloc (sizeof (node));	// Overflow occurs here

  n->value = item;
  n->next = s->items;
  s->items = n;

}

eltype
pop (Stack * s)
{
  if (s->items == NULL)
    {
      printf ("Stack Underflow occurs\n");
      exit (1);
    }
  eltype info = s->items->value;
  s->items = s->items->next;
  return info;
};


eltype
stacktop (Stack * s)
{
  if (s->items == NULL)
    {
      printf ("Stack Underflow occurs\n");
    }
  return s->items->value;
}

bool
empty (Stack * s)
{
  return s->items == NULL;
}
