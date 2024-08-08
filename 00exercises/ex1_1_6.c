// 1.1.6
#include <stdio.h>

int convert_to_ternary (int number, int result[32]);


int
main ()
{

  int ternary[32] = { };

  convert_to_ternary (6, ternary);

  for (int i = 0; i <= 32; i++)
    {
      printf ("%d", ternary[i]);
    };
  return 1;
}


int
convert_to_ternary (int number, int result[32])
{

  if (number <= 0)
    {
      return 0;
    }

  int n = number;
  int i = 32;

  while (n > 0)
    {
      result[i] = n % 3;
      n = n / 3;
      i--;
    }
  while (i >= 0)
    {
      result[i] = 0;
      i--;
    }
  return 1;
}
