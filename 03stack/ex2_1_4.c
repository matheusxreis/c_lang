/*
 * The exercise was make an algoritm,
 * this code is the impl from the algoritm
 */

#include<stdbool.h>
#include <stdio.h>

int
exec (char str[])
{

  bool valid = true;
  // false stack
  char stack[20];
  char separator = 'D';
  bool control = false;
  int counter = 2;

  int index = -1;

  for (int i = 0; str[i] != '\0'; i++)
    {

      index += 1;

      if (str[i] == separator)
	{
	  control = !control;
	  if (counter > 2)
	    {
	      index = 0;
	    };
	  if (index == 0)
	    {
	      counter = 2;
	    };
	  continue;
	}

      if (!control)
	{
	  //pushing
	  stack[index] = str[i];
	}
      else
	{
	  // supose that stack is not empty
	  // popping
	  char item = stack[index - counter];
	  if (item != str[i])
	    {
	      valid = false;
	      break;
	    }
	  counter += 2;
	}
    }

  if (counter == 2 || !valid)
    {				//or stack is not empty
      printf ("String invalid =(\n");
    }
  else
    {
      printf ("String valid =)\n");
    }

};

int
main ()
{

  char str[] = "ABDBADAADAADBADABDBBDBB";
  char str2[] = "ADADBDBDBADABDBBADABBDABADABA";
  char str3[] = "ADADBDBDBADABDBBADABBDABAD";
  char str4[] = "BADAB";
  char str5[] = "DAADAADBADAB";
  char str6[] = "D";
  char str7[] = "AADBBDAADAADBADAB";
  char str8[] = "DABDBAD";
  char str9[] = "AADAADAADAADBADAB";

  exec (str);			// valid
  exec (str2);			// valid 
  exec (str3);			// invalid
  exec (str4);			// valid
  exec (str5);			// invalid
  exec (str6);			// invalid;
  exec (str7);			// invalid;
  exec (str8);			// invalid
  exec (str9);			// valid;


}
