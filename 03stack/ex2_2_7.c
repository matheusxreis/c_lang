#include"ex2_2_7.h"
#include <stdio.h>
#include <stdlib.h>


int
main ()
{

  int x = 1;
  int size = 50;

  DoubleStack d = create_double_stack (size);

  for (int i = 0; i < size; i++)
    {
      push2 (&d, &x);
    };
  pop2 (&d);
  push1 (&d, &x);
  pop2 (&d);
  push1 (&d, &x);
  pop1 (&d);
  pop1 (&d);
  push2 (&d, &x);
  push2 (&d, &x);
  for (int i = 0; i < size; i++)
    {
      pop2 (&d);
    };
  return 1;
}

DoubleStack
create_double_stack (int size)
{
  DoubleStack d;

  d.size = size;
  d.s[0].top = -1;		// SIZE: 50, top = -1, push from 0 to 24;
  d.s[1].top = size;		// SIZE: 50, top = 50, push from 50 to 25;

  return d;
};

void
push1 (DoubleStack * d, eltype i)
{

  if (d->s[0].top == d->s[1].top - 1)
    {
      printf ("Stackoverflow occurs\n");
      exit (1);
    };

  d->s[0].items[++(d->s[0].top)] = i;
};

void
push2 (DoubleStack * d, eltype i)
{

  if (d->s[0].top == d->s[1].top - 1)
    {
      printf ("Stackoverflow occurs\n");
      exit (1);
    };

  d->s[1].items[--(d->s[1].top)] = i;
};

eltype
pop1 (DoubleStack * d)
{

  if (d->s[0].top < 0)
    {
      printf ("Underflow occurs in stack1\n");
      exit (1);
    };
  return d->s[0].items[(d->s[0].top)--];
};

eltype
pop2 (DoubleStack * d)
{

  if (d->s[1].top >= d->size)
    {
      printf ("Underflow occurs in stack2\n");
      exit (1);
    };

  return d->s[1].items[(d->s[1].top)++];
};
