// binary search
#include<stdio.h>


int binary_search (int *arr, int low, int high, int n);

int
main ()
{

  int arr[] = { 1, 3, 7, 15, 21, 36, 78, 95, 106 };
  int high = (sizeof (arr) / sizeof (arr[0])) - 1;

  int result1 = binary_search (arr, 0, high, 1);
  int result20 = binary_search (arr, 0, high, 20);
  int result36 = binary_search (arr, 0, high, 36);
  int result7 = binary_search (arr, 0, high, 7);
  int result106 = binary_search (arr, 0, high, 106);
  int result99 = binary_search (arr, 0, high, 99);


  printf ("\n this is the result, expected 0, searching 1 => %d\n", result1);	// expected: 0
  printf ("\n this is the result, expected -1, searching 20 => %d\n", result20);	// expected: -1
  printf ("\n this is the result, expected 5, searching 36 => %d\n", result36);	// expected: 5
  printf ("\n this is the result, expected 2, searching 7 => %d\n", result7);	// expected: 2
  printf ("\n this is the result, expected 8, searching 106 => %d\n", result106);	// expected: 8
  printf ("\n this is the result, expected -1, searching 99 => %d\n", result99);	// expected: -1

  return 1;

}

int
binary_search (int *arr, int low, int high, int n)
{

  int middle = low + (high - low) / 2;
  // low + (last index to search - first index to search)/2

  if (arr[middle] == n)
    {
      return middle;
    }

  if (low >= high)
    {
      return -1;
    }

  if (arr[middle] < n)
    {

      return binary_search (arr, middle + 1, high, n);

    }
  else
    {

      return binary_search (arr, low, middle - 1, n);

    };

}
