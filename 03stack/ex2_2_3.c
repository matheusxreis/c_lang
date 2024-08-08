#include"stack.c"
#include <stdbool.h>
#include <stdio.h>


void
ex213 (char str[])
{
  struct Stack s = create ();

  bool valid = true;
  bool hitMiddle = false;

  for (int i = 0; str[i] != '\0'; i++)
    {

      if (str[i] == 'C' && !hitMiddle)
	{
	  hitMiddle = true;
	  continue;
	};

      if (!hitMiddle)
	{
	  push (&s, &str[i]);
	}
      else
	{
	  if (empty (&s))
	    {
	      valid = false;
	      return;
	    }
	  char item = *(char *) pop (&s);
	  if (item != str[i])
	    {
	      valid = false;
	      break;
	    }
	};
    };

  if (!valid || !hitMiddle || !empty (&s))
    {
      printf ("String invalid =)\n");
    }
  else
    {
      printf ("String valid =(\n");
    };
}


void
ex214 (char str[])
{

  bool valid = true;
  struct Stack s = create ();
  char separator = 'D';
  bool control = false;

  for (int i = 0; str[i] != '\0'; i++)
    {

      if (str[i] == separator)
	{
	  control = !control;
	  i++;
	}

      if (!control)
	{
	  push (&s, &str[i]);
	}
      else
	{
	  if (empty (&s))
	    {
	      valid = false;
	      break;
	    }
	  char item = *(char *) pop (&s);
	  if (item != str[i])
	    {
	      valid = false;
	      break;
	    }
	}
    }

  if (!control || !valid || !empty (&s))
    {
      printf ("String invalid =(\n");
    }
  else
    {
      printf ("String valid =)\n");
    }

};


void
testex213 ()
{

  char str1[] = "ABCBA";
  char str2[] = "ABACABA";
  char str3[] = "ACA";

  char str4[] = "AA";
  char str5[] = "AACCBB";
  char str6[] = "AABBCBBAA";
  char str7[] = "ACB";
  char str8[] = "ABABACBABC";

  ex213 (str1);			// expected valid
  ex213 (str2);			// expected valid
  ex213 (str3);			// expected valid
  ex213 (str6);			// expected valid
  ex213 (str4);			// expected invalid
  ex213 (str5);			// expected invalid
  ex213 (str7);			// expected invalid
  ex213 (str8);			// expected invalid

};

void
testex214 ()
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

  ex214 (str);			// valid
  ex214 (str2);			// valid 
  ex214 (str3);			// invalid
  ex214 (str4);			// valid
  ex214 (str5);			// invalid
  ex214 (str6);			// invalid;
  ex214 (str7);			// invalid;
  ex214 (str8);			// invalid
  ex214 (str9);			// valid;


}

int
main ()
{

  testex214 ();
  testex213 ();

  return 1;
}
