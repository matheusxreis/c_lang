#include <stdio.h>
#include <stdlib.h>
int
main ()
{

  // 20 filais 
  // 10 itens
  int arr[20][10];

  for (int i = 0; i < 20; i++)
    {
      for (int j = 0; j < 10; j++)
	{
	  arr[i][j] = rand () % 99;
	}
    };


  printf ("FILIAL:      |");
  for (int i = 0; i < 11; i++)
    {
      if (i > 9)
	{
	  printf ("TOTAL");
	}
      else
	{
	  printf ("ITEM %d     |", i + 1);
	}
    };
  printf ("\n");

  int total_column[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
  int total = 0;
  for (int i = 0; i < 20; i++)
    {
      //ONLY VISUAL
      if (i + 1 < 10)
	{
	  printf ("FILIAL: %d   |", i + 1);
	}
      else
	{
	  printf ("FILIAL: %d  |", i + 1);
	}
      int total_row = 0;
      for (int j = 0; j < 10; j++)
	{

	  total_column[j] += arr[i][j];
	  total_row += arr[i][j];
	  //ONLY VISUAL
	  if (arr[i][j] < 10)
	    {
	      printf ("   R$ %d    |", arr[i][j]);
	    }
	  else
	    {
	      printf ("   R$ %d   |", arr[i][j]);
	    }
	};
      total += total_row;
      printf (" R$ %d ", total_row);
      printf ("\n");
    };

  printf ("TOTAL       |");
  for (int i = 0; i < 10; i++)
    {
      if (total_column[i] < 1000)
	{
	  printf ("   R$ %d  |", total_column[i]);
	}
      else
	{
	  printf ("   R$ %d |", total_column[i]);
	};
    };
  printf (" R$ %d", total);
  printf ("\n");

  return 0;
}
