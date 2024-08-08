#include<stdio.h>

void increment (int *py);
void decrement (int *py);
void print_address (int *var);
void print_address2 (char *var);

int
main ()
{
  /*
   * declare a integer pointer -> int *py or int* py
   * retrieve the address in a integer variable -> &x
   * add in a integer pointer the integer variable's address -> py = &x
   */

  int x = 5;
  increment (&x);
  printf ("%d\n", x);
  decrement (&x);
  printf ("%d\n", x);

  int vector[] = { 1, 2, 3, 4, 5, 6 };
  char vector2[] = "Hello World\n";


  for (int i = 0; i <= 6; i++)
    {
      // if i pass vector[i], i will copy the data type to another address each time and the addresses will be the same
      print_address (&vector[i]);
    }
  for (int j = 0; j <= 11; j++)
    {
      print_address2 (&vector2[j]);
    }
  print_address (&x);

  return 1;
};

void
increment (int *py)
{
  (*py) += 1;
};

void
decrement (int *py)
{
  (*py) -= 1;
}

void
print_address (int *var)
{
  // in c, integer are stored in words with 4 bytes
  // so, a int array with 6 itens, has 24 bytes
  // &arr[0] = 100; &arr[1] = 104;
  printf ("adrres from %d is -> %d\n", (*var), var);
};

void
print_address2 (char *var)
{
  // in c, chars are stored in words with 1 bytes
  // so, a char array with 6 itens, has 6 bytes
  // &arr[0] = 100; &arr[1] = 101;
  printf ("adrres from %c is -> %d\n", (*var), var);
}
