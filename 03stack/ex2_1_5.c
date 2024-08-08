
#include <stdio.h>
enum Operation
{
  PUSH,
  POP
};

int
exec (enum Operation operation, int counter_state)
{
  static int counter;

  if (counter_state == 0)
    {
      counter = 0;
    }
  if (operation == PUSH)
    {
      //push
      counter++;
    }
  else
    {
      //pop
      if (counter == 0)
	{
	  return 0;
	};
      counter--;
    };

  return 1;
};

void
loop (enum Operation list[], int size)
{
  for (int i = 0; i < size; i++)
    {
      if (exec (list[i], i) == 0)
	{
	  printf ("Underflow =(\n");
	  break;
	};

      if (i == size - 1)
	{
	  printf ("That's ok =D \n");
	}
    };
};

int
main ()
{


  enum Operation op[] = { PUSH, POP, PUSH, PUSH, POP, POP };
  enum Operation op2[] = { PUSH, PUSH, PUSH, POP, POP, POP };
  enum Operation op3[] = { PUSH, PUSH, PUSH, POP, POP, PUSH, POP, POP };
  enum Operation op4[] = { POP, PUSH, PUSH, POP, POP };
  enum Operation op5[] = { PUSH, PUSH, POP, PUSH, POP, POP, POP };

  loop (op5, sizeof (op5) / sizeof (op5[0]));	// underflow
  loop (op, sizeof (op) / sizeof (op[0]));
  loop (op2, sizeof (op2) / sizeof (op2[0]));
  loop (op3, sizeof (op3) / sizeof (op3[0]));
  loop (op4, sizeof (op4) / sizeof (op4[0]));	// underflow 

  return 1;
}
