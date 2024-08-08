// rational numbers implementation using structs in c
#include<stdio.h>

typedef struct
{
  int numerator;
  int denominator;
} RATIONAL;


// using euclid's algorithm to reduce a rational number
void
reduce (RATIONAL * rat, RATIONAL * rat2)
{

  int a, b;

  if (rat->numerator > rat->denominator)
    {
      a = rat->numerator;
      b = rat->denominator;
    }
  else
    {
      a = rat->denominator;
      b = rat->numerator;
    }

  while (b != 0)
    {
      int rest = a % b;
      a = b;
      b = rest;
    };
  rat2->numerator = rat->numerator / a;
  rat2->denominator = rat->denominator / a;
};

void
divide (RATIONAL * rat1, RATIONAL * rat2, RATIONAL * rat3)
{

  RATIONAL r3;

  r3.numerator = rat1->numerator * rat2->denominator;
  r3.denominator = rat1->denominator * rat2->numerator;

  reduce (&r3, rat3);
};

void
sub (RATIONAL * rat1, RATIONAL * rat2, RATIONAL * rat3)
{

  RATIONAL r3;

  if (rat1->denominator == rat2->denominator)
    {
      r3.numerator = rat1->numerator - rat1->numerator;
      reduce (&r3, rat3);
    }
  else
    {
      r3.numerator =
	(rat1->numerator * rat2->denominator) -
	(rat2->numerator * rat1->denominator);
      r3.denominator = rat1->denominator * rat2->denominator;
      reduce (&r3, rat3);
    };
};

void
sum (RATIONAL * rat1, RATIONAL * rat2, RATIONAL * rat3)
{

  RATIONAL r3;

  if (rat1->denominator == rat2->denominator)
    {
      r3.numerator = rat1->numerator + rat1->numerator;
      reduce (&r3, rat3);
    }
  else
    {
      r3.numerator =
	(rat1->numerator * rat2->denominator) +
	(rat2->numerator * rat1->denominator);
      r3.denominator = rat1->denominator * rat2->denominator;
      reduce (&r3, rat3);
    };
};

void
multiply (RATIONAL * rat1, RATIONAL * rat2, RATIONAL * rat3)
{

  RATIONAL r3;

  r3.numerator = rat1->numerator * rat2->numerator;
  r3.denominator = rat1->denominator * rat2->denominator;

  reduce (&r3, rat3);
};

_Bool
equal (RATIONAL * rat1, RATIONAL * rat2)
{
  RATIONAL r1, r2;
  reduce (rat1, &r1);
  reduce (rat2, &r2);

  return r1.numerator == r2.numerator && r1.denominator == r2.denominator;
};

void
show (RATIONAL * rat)
{
  printf ("%d/%d\n", rat->numerator, rat->denominator);
};

RATIONAL
create (int numerator, int denominator)
{
  RATIONAL x;
  x.numerator = numerator;
  x.denominator = denominator;
  return x;
};

int
main ()
{

  RATIONAL x, y, z, result, r1, r2, r3;

  x = create (2, 4);		// 2/4
  y = create (1, 2);		// 1/2
  z = create (12, 8);		// 12/8

  reduce (&x, &r1);		// 1/2
  reduce (&y, &r2);		// 1/2
  reduce (&z, &r3);		// 3/2

  show (&r1);
  show (&r2);
  show (&r3);

  multiply (&x, &y, &result);
  show (&result);

  sum (&x, &y, &result);
  show (&result);

  sub (&x, &y, &result);
  show (&result);

  divide (&x, &y, &result);
  show (&result);

  divide (&z, &x, &result);
  show (&result);

  multiply (&z, &x, &result);
  show (&result);

  sum (&z, &x, &result);
  show (&result);

  sub (&z, &x, &result);
  show (&result);







  return 1;
}
