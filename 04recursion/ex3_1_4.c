#include<stdio.h>

int factorial (int x);
int multiply (int a, int b);
int fib (int a);

int factorial_i (int x);
int multiply_i (int a, int b);
int fib_i (int a);

int
main ()
{

  printf ("factorial from 6, 9, 3 => %d %d %d\n", factorial (6),
	  factorial (9), factorial (3));
  printf ("factorial iterative from 6, 9, 3 => %d %d %d\n\n", factorial_i (6),
	  factorial_i (9), factorial_i (3));

  printf ("mul from 100*3, 6*4, 1*4 => %d %d %d\n", multiply (100, 3),
	  multiply (6, 4), multiply (1, 4));
  printf ("mul iterative from 100*3, 6*4, 1*4 => %d %d %d\n\n",
	  multiply_i (100, 3), multiply_i (6, 4), multiply_i (1, 4));

  printf ("fib from 10, 11, 4 => %d %d %d\n", fib (10), fib (11), fib (4));
  printf ("fib from 10, 11, 4 => %d %d %d\n\n", fib_i (10), fib_i (11),
	  fib_i (4));

  return 1;
}

/* recursive definition from factorial, multiply and fibonacci */
int
factorial (int x)
{
  if (x <= 1)
    {
      return x;
    }
  return x * factorial (x - 1);
}

int
multiply (int a, int b)
{
  if (b == 1)
    {
      return a;
    }
  if (b == 0)
    {
      return b;
    }
  return a + multiply (a, b - 1);
}

int
fib (int a)
{
  if (a <= 1)
    {
      return a;
    }

  return fib (a - 2) + fib (a - 1);
}

/* iterative definition from factorial, multiply and fibonacci */

int
factorial_i (int x)
{
  int n = x;
  for (int i = 1; i < x; i++)
    {
      n *= x - i;
    };
  return n;
}

int
multiply_i (int a, int b)
{
  int n = 0;
  for (int i = b; i > 0; i--)
    {
      n += a;
    }
  return n;
}

int
fib_i (int a)
{

  int prev = 0;
  int current = 1;

  for (int i = 1; i <= a; i++)
    {
      int x = prev + current;
      prev = current;
      current = x;
    }

  return prev;
}
