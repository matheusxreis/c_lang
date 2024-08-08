#include<stdio.h>
#include<stdlib.h>

void execute ();
int media (int arr[], int size);

int
main ()
{


  execute ();

  return 1;
};


void
execute ()
{

  // leitura de uma semana, dê 180 diferentes latitudes (-90 até 90);
  int reads[181][7];
  int medias[181];


  for (int i = 0; i <= 180; i++)
    {
      for (int j = 0; j <= 6; j++)
	{
	  int temp = rand () % 40;
	  if (i % 7 == 0)
	    {
	      // mock latitudes sem temperatua
	      reads[i][j] = 0;
	    }
	  else
	    {
	      reads[i][j] = temp;
	    }

	}
    }


  int j = 0;

  // printando médias de cada latitute
  printf ("| latitude | temperatura |\n");
  for (int i = -90; i <= 90; i++, j++)
    {
      int med = media (reads[j], sizeof (reads[j]) / sizeof (reads[j][0]));
      medias[j] = med;
      printf ("|    %d    |     %d     |\n", i, med);

    }

  j = 0;

  printf ("hemisfério sul\n");
  printf ("| temperatura média |\n");
  printf ("| %d |\n", media (medias, 89));
  printf ("hemisfério norte\n");
  printf ("| temperatura média |\n");
  printf ("| %d |\n", media (medias + 91, 89));


  // hemisferio mais quente

  int sreads[90];
  int nreads[90];

  for (int i = 0; i <= 89; i++)
    {
      if (medias[i] != 0 && medias[180 - i] != 0)
	{
	  sreads[i] = medias[i];
	  nreads[i] = medias[180 - i];
	}
      else
	{
	  sreads[i] = 0;
	  nreads[i] = 0;
	}
    };

  for (int i = 0; i <= 89; i++)
    {
      printf ("|   sul=> %d | norte => %d  |\n", sreads[i], nreads[i]);
    }

  int hottiest;
  if (media (sreads, 90) > media (nreads, 90))
    {
      printf
	("O hemisfério mais quente, tirando a média de acordo com a latitude correspondente é o hemisfério sul\n");
    }
  else
    {
      printf
	("O hemisfério mais quente, tirando a média de acordo com a latitude correspondente é o hemisfério norte\n");
    };

};


int
media (int arr[], int size)
{
  int result = 0;
  for (int i = 0; i <= size - 1; result += arr[i++]);
  return result / size;
}
