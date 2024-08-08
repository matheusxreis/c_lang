#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int calc (int a, int b, char op);
int eval (char *prefix);
char pop_string (char *str);


int
main ()
{
  char *a = malloc (100);

  while (fgets (a, 100, stdin))
    {
      a[strcspn (a, "\r\n")] = '\0';
      int l = strlen (a);
      int result = eval (a);
      printf ("result from prefix: %s is: %d \n", a, result);
    }
  free (a);
}


int
eval (char *prefix)
{

  char op = pop_string (prefix);

  if (isdigit (op) == 0)
    {
      /*case op be a operator */
      return calc (eval (prefix), eval (prefix), op);
    }
  else
    {
      return op - '0';
    }

}

int
calc (int a, int b, char op)
{

  printf ("calculing... %d%c%d\n", a, op, b);
  switch (op)
    {
    case '+':
      return a + b;
    case '-':
      return a - b;
    case '/':
      return a / b;
    case '*':
      return a * b;
    case '^':
      return pow (a, b);
    default:
      printf ("Invalid operation (%c) with %d and %d", op, a, b);
      exit (1);
    }
}


char
pop_string (char *str)
{
  char x = str[0];
  memmove (&str[0], &str[1], strlen (str));
  return x;
}
