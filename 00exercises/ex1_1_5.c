// 1.1.5
// the same is easily applicable with strings

#include<stdio.h>
#include<assert.h>

int mpow (int base, int exp);
int read_binary (int binary[], int size);
int convert_to_binary (int number, int binary[32]);

enum Operation
{
  ADD,
  MULTIPLY,
  SUB
};

typedef struct
{
  enum Operation operation;
  int size1;
  int size2;
  int b1[32];
  int b2[32];
  int result[32];
} Parameters;


int calculate (Parameters params);
Parameters make_parameters (int b1[], int b2[], int size1, int size2,
			    enum Operation operation);

int
main ()
{

  int binary1[] = { 1, 0, 1, 0 };	//10
  int binary2[] = { 1, 0, 0, 0, 0 };	//16
  int binary4[] = { 0, 1, 0, 1 };	//5
  int binary5[] = { 1, 0, 1, 1 };	//11
  int binary4_copy[] = { 0, 1, 0, 1 };	//5
  int binary6[] = { 0, 0, 0, 0, 0, 0 };	//0;

  int size1 = sizeof (binary1) / sizeof (binary1[0]);
  int size2 = sizeof (binary2) / sizeof (binary2[0]);
  int size4 = sizeof (binary4) / sizeof (binary4[0]);
  int size5 = sizeof (binary5) / sizeof (binary5[0]);
  int size6 = sizeof (binary6) / sizeof (binary6[0]);

  // mpow
  assert (mpow (2, 3) == 8);
  assert (mpow (2, 8) == 256);
  assert (mpow (2, 0) == 1);
  assert (mpow (2, 1) == 2);

  // read_binary
  assert (read_binary (binary1, size1) == 10);
  assert (read_binary (binary2, size2) == 16);
  assert (read_binary (binary4, size4) == 5);
  assert (read_binary (binary5, size5) == 11);
  assert (read_binary (binary6, size6) == 0);


  int binary_test[32] = { };

  // add_binaryI
  Parameters params = make_parameters (binary1, binary2, size1, size2, ADD);
  assert (calculate (params) == 26);
  params = make_parameters (binary4, binary1, size4, size1, ADD);
  assert (calculate (params) == 15);
  params = make_parameters (binary4, binary2, size4, size2, ADD);
  assert (calculate (params) == 21);
  params = make_parameters (binary4, binary4_copy, size4, size4, ADD);
  assert (calculate (params) == 10);

  // sub_binary  
  params = make_parameters (binary2, binary1, size2, size1, SUB);
  assert (calculate (params) == 6);
  params = make_parameters (binary2, binary4, size2, size4, SUB);
  assert (calculate (params) == read_binary (binary5, size5));
  params = make_parameters (binary4, binary4_copy, size4, size4, SUB);
  assert (calculate (params) == 0);

  // mult_binary

  params = make_parameters (binary2, binary1, size2, size1, MULTIPLY);
  assert (calculate (params) == 160);
  params = make_parameters (binary2, binary4, size2, size4, MULTIPLY);
  assert (calculate (params) == 80);
  params = make_parameters (binary4, binary4_copy, size4, size4, MULTIPLY);
  assert (calculate (params) == 25);

  // case of negative result  

  params = make_parameters (binary1, binary2, size1, size2, SUB);
  assert (calculate (params) == 0);

  return 0;
};



Parameters
make_parameters (int b1[], int b2[], int size1, int size2,
		 enum Operation operation)
{

  Parameters params;
  for (int i = 0; i <= size1; i++)
    {
      params.b1[i] = b1[i];
    };
  for (int i = 0; i <= size2; i++)
    {
      params.b2[i] = b2[i];
    };

  params.size1 = size1;
  params.size2 = size2;
  params.result[0] = 0;
  params.operation = operation;

  return params;


}

int
calculate (Parameters params)
{

  int number1 = read_binary (params.b1, params.size1);
  int number2 = read_binary (params.b2, params.size2);

  int result = 0;

  char op;
  switch (params.operation)
    {
    case ADD:
      result = number1 + number2;
      op = '+';
      break;
    case MULTIPLY:
      result = number1 * number2;
      op = '*';
      break;
    case SUB:
      op = '-';
      result = number1 - number2;
      break;
    };

  if (convert_to_binary (result, params.result) == 0)
    {
      return 0;
    }

  printf ("%d %c %d = %d => ", number1, op, number2, result);
  for (int i = 0; i <= 32; i++)
    {
      printf ("%d", params.result[i]);
    };
  printf ("\n");

  return result;
};

int
convert_to_binary (int number, int result[32])
{

  if (number <= 0)
    {
      return 0;
    }

  int n = number;
  int i = 32;


  while (n > 0)
    {

      if (n % 2 != 0)
	{

	  result[i] = 1;

	}
      else
	{

	  result[i] = 0;

	}
      n = n / 2;
      i--;
    }

  while (i >= 0)
    {

      result[i] = 0;
      i--;
    }

  return 1;
}

int
read_binary (int binary[], int size)
{
  int sum = 0;			//soma
  int exp = 0;			//expoente

  for (int i = size - 1; i >= 0; i--)
    {
      if (binary[i] == 1)
	{
	  sum += mpow (2, exp);
	}
      exp++;
    };

  return sum;
}

int
mpow (int base, int exp)
{

  int value = 1;

  for (int i = 1; i <= exp; i++)
    {
      value = value * base;
    }

  return value;
};
