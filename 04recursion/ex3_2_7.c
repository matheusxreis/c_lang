
// merge sort


#include <stdio.h>
void merge_sort (int *arr, int low, int high);



int
main ()
{


  int arr[] =
    { 7, 13, 2, 2, 15, 20, 32, 0, 28, 99, 100, 1, 1, 2, 3, 4, 5, 6, 7 };
  int size = sizeof (arr) / sizeof (arr[0]);
  merge_sort (arr, 0, size - 1);
  for (int i = 0; i < size; printf (" %d ", arr[i++]));
  printf ("\n");
  return 0;
}

void
merge_sort (int *arr, int low, int high)
{


  if (low < high)
    {


      int middle = (high + low) / 2;

      merge_sort (arr, low, middle);
      merge_sort (arr, middle + 1, high);


      int n1 = middle - low + 1;
      int n2 = high - middle;

      int left[n1], right[n2];

      for (int i = 0; i < n1; i++)
	{
	  left[i] = arr[low + i];
	}
      for (int i = 0; i < n2; i++)
	{
	  right[i] = arr[middle + 1 + i];
	}

      int i = 0;
      int j = 0;
      int k = low;

      while (i < n1 && j < n2)
	{
	  if (left[i] <= right[j])
	    {
	      arr[k] = left[i];
	      i += 1;
	    }
	  else
	    {
	      arr[k] = right[j];
	      j += 1;
	    }
	  k += 1;
	}
      while (i < n1)
	{
	  arr[k] = left[i];
	  i += 1;
	  k += 1;
	}
      while (j < n2)
	{
	  arr[k] = right[j];
	  j += 1;
	  k += 1;
	}

    }

};
