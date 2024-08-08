/* combinae postfix * eval */
#include <ctype.h>
#include <fenv.h>
#include <math.h>
#include <stdlib.h>
#include"eval.h"
#include"stack_float.c"

#ifndef MAIN_EXIST
#define MAIN_EXIST

#include"postfix.c"

int
main ()
{

  char *a = malloc (100);

  while (fgets (a, 100, stdin))
    {

      a[strcspn (a, "\r\n")] = '\0';

      int result = eval (a);
      printf ("result from %s => %d\n", a, result);
    }

  free (a);
  return 0;
};

#endif

int
prcd2 (char op)
{
  switch (op)
    {
    case '(':
      return 1;
    case '+':
    case '-':
      return 2;
    case '*':
    case '/':
      return 3;
    case '^':
      return 4;
    default:
      return -1;
    }
}

float
eval (char *infix)
{

  struct Stack stack_operator = create ();
  struct StackF stack_operand = create_f ();
  float n, n2;
  bool underflow, underflow2;

  while (*infix)
    {

      if (*infix == '(')
	{
	  // case opening parenthesis
	  // add in operator stack

	  push (&stack_operator, *infix);

	}
      else if (*infix == ')')
	{

	  // case closing parenthesis, must execute all inside it
	  float number1, number2;
	  char c;
	  bool und;
	  popandtest (&stack_operator, &c, &und);

	  while (!und && c != '(')
	    {

	      number1 = pop_f (&stack_operand);
	      number2 = pop_f (&stack_operand);

	      push_f (&stack_operand, oper (c, number2, number1));
	      popandtest (&stack_operator, &c, &und);
	      //break;
	    };

	}
      else if (isdigit (*infix))
	{
	  // case operand
	  // add in operand stack
	  push_f (&stack_operand, *infix - '0');


	}
      else
	{

	  // case operator
	  // if a operand
	  //  1 -> top stack has precedence over or is equal current operand? 
	  //     yes -> calculate and push result in operand stack; repeat until top stack has not precendence or equal
	  //   add in operator stack
	  //
	  float number1, number2;
	  char c = 'b';
	  bool und;
	  popandtest (&stack_operator, &c, &und);

	  int current = prcd2 (*infix);

	  while (prcd2 (c) >= current && !und)
	    {

	      number1 = pop_f (&stack_operand);
	      number2 = pop_f (&stack_operand);

	      push_f (&stack_operand, oper (c, number2, number1));
	      popandtest (&stack_operator, &c, &und);
	    };

	  if (prcd2 (c) < current && !und)
	    {
	      push (&stack_operator, c);
	    }
	  push (&stack_operator, *infix);
	}

      infix++;
    }

  char c;
  bool und;
  popandtest (&stack_operator, &c, &und);

  while (!und)
    {
      // calculate the rest
      float number1 = pop_f (&stack_operand);
      float number2 = pop_f (&stack_operand);
      push_f (&stack_operand, oper (c, number2, number1));
      popandtest (&stack_operator, &c, &und);

    };


  return pop_f (&stack_operand);

};

float
oper (char op, float number1, float number2)
{
  printf ("%.1f %c %.1f\n", number1, op, number2);
  switch (op)
    {
    case '+':
      return number1 + number2;
    case '-':
      return number1 - number2;
    case '*':
      return number1 * number2;
    case '/':
      return number1 / number2;
    case '^':
      return pow (number1, number2);
    default:
      printf ("Operation undefined op=>%c", op);
      exit (1);
    }
}
