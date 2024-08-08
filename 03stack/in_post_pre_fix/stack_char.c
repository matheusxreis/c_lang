#include"stack_char.h"
#include <stdio.h>
#include <stdlib.h>


bool
empty (struct Stack *s)
{
  return s->top < 0;
};

eltype
stacktop (struct Stack *s)
{
  if (empty (s))
    {
      printf ("Underflow occurs\n");
      exit (0);
    };
  return s->items[s->top];
};

struct Stack
create ()
{
  struct Stack s;
  s.top = INITIAL_TOP_VALUE;
  return s;
};

eltype
pop (struct Stack *s)
{
  if (empty (s))
    {
      printf ("Underflow occurs\n");
      exit (0);
    }
  return s->items[s->top--];
};

void
push (struct Stack *s, eltype i)
{
  // We shouldn't worry about overflow because a Stack has not limit
  // but in this implementation, as items in Stack are arrays, 
  // we must worry about.
  if (s->top >= STACKSIZE - 1)
    {
      printf ("Overflow occurs\n");
      exit (0);
    };
  s->items[++(s->top)] = i;
};

void
popandtest (struct Stack *s, eltype * i, bool *underflow)
{

  if (empty (s))
    {
      *(underflow) = true;
      return;
    };
  *(underflow) = false;
  *i = s->items[s->top--];

};

void
pushandtest (struct Stack *s, eltype i, bool *overflow)
{

  if (s->top >= STACKSIZE - 1)
    {
      *(overflow) = true;
      return;
    };
  *(overflow) = false;

  s->items[++(s->top)] = i;
};
