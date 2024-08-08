#include"postfix.h"
#include"stack_char.c"
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>

#ifndef MAIN_EXIST

int
main ()
{
  char *a = malloc (100);
  char *r = malloc (100);

#ifdef TEST
  postfix_test ();
#endif

#ifndef TEST

  while (fgets (a, 100, stdin))
    {
      a[strcspn (a, "\r\n")] = '\0';
      postfix (a, r);
      printf ("result from infix: %s, postfix: %s \n", a, r);
    }
  free (a);
  free (r);

#endif
}

#endif


void
postfix_test ()
{
  // make test  
};


void
postfix (char *infix, char *postr)
{

  bool underflow;
  char topsymb;
  struct Stack stack;
  stack = create ();

  //reading string // that's is like (base + 0 * esize = base + 0 = first address of array) 
  while (*infix)
    {

      if (isdigit (*infix) || isalpha (*infix))
	{
	  // if operand

	  *(postr++) = *infix;

	}
      else if (*infix == '(')
	{

	  push (&stack, *infix);

	}
      else if (*infix == ')')
	{

	  popandtest (&stack, &topsymb, &underflow);

	  while (!underflow && topsymb != '(')
	    {
	      *(postr++) = topsymb;
	      popandtest (&stack, &topsymb, &underflow);
	    }
	  topsymb = ' ';	// removing '(' from topsymb

	}
      else
	{
	  // if operator
	  *(postr++) = ' ';

	  popandtest (&stack, &topsymb, &underflow);

	  while (!underflow &&
		 (prdc_value (*infix) < prdc_value (topsymb)
		  || prdc_value (*infix) == prdc_value (topsymb)))
	    {
	      *(postr++) = topsymb;
	      popandtest (&stack, &topsymb, &underflow);
	    };

	  if (prdc_value (*infix) > prdc_value (topsymb))
	    {
	      push (&stack, topsymb);
	    }
	  push (&stack, *infix);
	}
      infix++;
    };
  while (!empty (&stack))
    {
      *(postr++) = pop (&stack);
    };

  *postr = '\0';
};

int
prdc_value (char symb)
{
  switch (symb)
    {
    case '+':
    case '-':
      return 1;
    case '*':
    case '/':
      return 2;
    case '^':
      return 3;
    default:
      return 0;
    }
};
