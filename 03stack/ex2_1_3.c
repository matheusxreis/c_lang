/*
 * The exercise was make an algoritm,
 * this code is the impl from the algoritm
 */

#include <stdio.h>

void
exec (char str[])
{

  // false stack
  char push[10];
  //

  int valid = 1;
  int middle = 0;

  int count = 2;

  for (int i = 0; str[i] != '\0'; i++)
    {

      if (str[i] == 'C' && middle == 0)
	{
	  middle = 1;
	  continue;
	};

      if (middle == 0)
	{
	  push[i] = str[i];
	}
      else
	{
	  // imagining that i is not empty
	  char item = push[i - count];
	  if (item != str[i])
	    {
	      valid = 0;
	      break;
	    }
	  count += 2;
	};
    };

  if (valid == 0 || middle == 0)
    {				// or stack is empty
      printf ("String invalid =)\n");
    }
  else
    {
      printf ("String valid =(\n");
    };
};

int
main ()
{

  char str1[] = "ABCBA";
  char str2[] = "ABACABA";
  char str3[] = "ACA";

  char str4[] = "AA";
  char str5[] = "AACCBB";
  char str6[] = "AABBCBBAA";
  char str7[] = "ACB";
  char str8[] = "ABABACBABC";

  exec (str1);			// expected valid
  exec (str2);			// expected valid
  exec (str3);			// expected valid
  exec (str6);			// expected valid
  exec (str4);			// expected invalid
  exec (str5);			// expected invalid
  exec (str7);			// expected invalid
  exec (str8);			// expected invalid

};
