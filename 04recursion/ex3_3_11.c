//// 

#include<stdio.h>
#include"../03stack/in_post_pre_fix/stack_char.c"

#define N 10
#define TRUE 1
#define FALSE 2

enum MOVES
{
  DOWN,
  RIGHT,
  LEFT,
  UP
};


void drawmaze ();
void drawmoves ();

int move (enum MOVES m, int r, int c);
char read_move (enum MOVES m);
/*
static int maze[N][N] = {
  {0, 0, 1, 1},
  {1, 0, 0, 1},
  {1, 1, 0, 0},
  {1, 1, 1, 0}
};
*/

/*
static int maze[N][N] =   {
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {0, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {0, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {0, 1, 0, 0, 0, 0, 0, 1, 0, 1}, 
    {0, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};
*/

static int maze[N][N] = {
  {0, 0, 0, 0, 1, 0, 0, 1, 0, 1},	//0
  {1, 1, 0, 1, 1, 0, 0, 0, 1, 1},	//1
  {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},	//2
  {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},	//3
  {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},	//4
  {1, 0, 1, 1, 0, 0, 1, 1, 0, 1},	//5
  {1, 1, 0, 0, 1, 0, 1, 1, 1, 1},	//6
  {1, 1, 0, 0, 0, 0, 0, 1, 0, 1},	//7
  {1, 1, 1, 0, 1, 0, 0, 0, 0, 0},	//8
  {1, 1, 0, 0, 0, 0, 0, 1, 1, 0}	//9
};				// 0  1  2  3  4  5  6  7  8  9

/*
static int maze[N][N] =  {
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 1}, //0
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 1}, //1
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0}, //2
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1}, //3
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1}, //4
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1}, //5
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1}, //6
    {1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, //7
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 0}, //8
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0}  //9
};// 0  1  2  3  4  5  6  7  8  9
*/

static struct Stack stack;

int try (int row, int col);

int
main ()
{

  create (stack);


  drawmaze ();

  if (try (0, 0) == TRUE)
    {
      printf ("The solution is:\n");
      drawmoves ();
    }
  else
    {
      printf ("There is no solution\n");
    };


  return 1;
}



int
try (int row, int col)
{

  enum MOVES m;

  if (maze[row][col] == 1)
    {
      return FALSE;
    }

  // marking what I passed
  maze[row][col] = 1;

  for (int i = 0; i < 4; i++)
    {
      m = i;
      if (row == N - 1 && col == N - 1)
	{
	  return TRUE;
	}
      if (move (m, row, col) == TRUE)
	{
	  push (&stack, read_move (m));	// only to print 
	  return TRUE;
	}
    }

  return FALSE;

}


int
move (enum MOVES m, int r, int c)
{

  int row = r;
  int col = c;


  switch (m)
    {
    case DOWN:
      if (row + 1 > N - 1)
	{
	  return FALSE;
	}
      row += 1;
      break;
    case UP:
      if (row - 1 < 0)
	{
	  return FALSE;
	}
      row -= 1;
      break;
    case LEFT:
      if (col - 1 < 0)
	{
	  return FALSE;
	}
      col -= 1;
      break;
    case RIGHT:
      if (col + 1 > N - 1)
	{
	  return FALSE;
	}
      col += 1;
      break;
    }
  return try (row, col);
}

char
read_move (enum MOVES m)
{
  switch (m)
    {
    case DOWN:
      return 'D';
    case UP:
      return 'U';
    case LEFT:
      return 'L';
    case RIGHT:
      return 'R';
    }
}

void
drawmaze ()
{

  for (int row = 0; row < N; row++)
    {
      for (int col = 0; col < N; col++)
	{
	  if (maze[row][col] == 1)
	    {
	      printf (" x ");
	    }
	  else
	    {
	      printf (" . ");
	    }
	}
      printf ("\n");
    }
}

void
drawmoves ()
{

  while (!empty (&stack))
    {
      printf ("move:  %c\n", pop (&stack));
    }
}
