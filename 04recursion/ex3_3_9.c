#include<stdio.h>
#include<stdlib.h>

void
swap (int *arr, int i, int j)
{
  int x = arr[i];
  arr[i] = arr[j];
  arr[j] = x;
}

int
partition (int *arr, int low, int high)
{

  int pivot = arr[high];

  int i = (low - 1);

  for (int j = low; j <= high; j++)
    {
      if (arr[j] < pivot)
	{
	  i++;
	  swap (arr, i, j);
	}
    }
  swap (arr, high, i + 1);

  return (i + 1);
}

void
quick_sort (int *arr, int low, int high)
{

  if (low < high)
    {
      int pivot = partition (arr, low, high);
      quick_sort (arr, low, pivot - 1);
      quick_sort (arr, pivot + 1, high);
    }

}

int
nth_small (int *arr, int len, int n)
{
  if (n >= len)
    {
      printf ("Illegal argument\n");
      exit (1);
    }
  quick_sort (arr, 0, len - 1);
  return arr[n];
}



int
main ()
{

  int arr[] = { 10, 7, 8, 1, 1000, 9, 4, 14, 0 };	// 0 - 1 - 4 - 7 - 8 - 9 - 10 - 14 - 1000


  for (int i = 1; i < 10; i++)
    {
      int x = nth_small (arr, sizeof (arr) / sizeof (arr[0]), i - 1);
      printf ("The %d place is %d\n", i, x);
    }


}
