// complex numbers implementation using structs in c
// i is the square root of -1
// complex number has a part real and another imaginary
// imaginary number are number that can be written as a multiple of the
// imaginary unit, where i is the square root of -1

#include<stdio.h>


typedef struct
{
  int real;
  int imaginary;
} COMPLEX;

void
negative (COMPLEX * complex, COMPLEX * result)
{
  result->real = (-complex->real);
  result->imaginary = (-complex->imaginary);	//*1 
};

void
multiply (COMPLEX * comp1, COMPLEX * comp2, COMPLEX * comp3)
{
  comp3->real =
    ((comp1->real * comp2->real) - (comp1->imaginary *comp2->imaginary));
  comp3->imaginary = ((comp1->real * comp2->imaginary) +(comp1->imaginary *comp2->real));	//*i
};

void
sum (COMPLEX * comp1, COMPLEX * comp2, COMPLEX * comp3)
{
  comp3->real = (comp1->real + comp2->real);
  comp3->imaginary = (comp1->imaginary +comp2->imaginary);	//*i;
};

COMPLEX
create (int real, int imaginary)
{
  COMPLEX c;
  c.real = real;
  c.imaginary = imaginary;
  return c;
};

void
show (COMPLEX * complex)
{
  printf ("(%d)+(%d)i\n", complex->real, complex->imaginary);
};

int
main ()
{

  COMPLEX c1 = create (10, 4);
  COMPLEX c2 = create (7, 2);
  COMPLEX r1, r2, r3;

  sum (&c1, &c2, &r1);
  multiply (&c1, &c2, &r2);
  negative (&c1, &r3);

  printf ("C => real: %d and imaginary: %d\n", c1.real, c1.imaginary);
  printf ("Results, sum, multiply and negative\n");
  show (&r1);
  show (&r2);
  show (&r3);

  negative (&c2, &r3);

  show (&r3);
  return 1;
}
