#include"prefix_to_postfix.h"
#include<string.h>
#include<ctype.h>
#include<stdio.h>

int
find_iterative (char *str)
{

  int length = strlen (str);
  int alpha = 0;
  int not_alpha = 0;

  if (length == 0)
    {
      return 0;
    }


  if (isalpha (str[0]))
    {
      return 1;
    }
  if (length < 2)
    {
      return 0;
    }

  int i;
  for (i = 0; i < length; i++)
    {
      if (isalpha (str[i]) == 0)
	{
	  not_alpha += 1;
	}
      else
	{
	  alpha += 1;
	}
      if (not_alpha != 0 && (alpha - 1) == not_alpha)
	{
	  return i + 1;
	}
    }
  if (i <= not_alpha || i == 0)
    {
      return 0;
    }

  return (i);
}
