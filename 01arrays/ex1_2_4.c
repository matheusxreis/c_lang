#include<stdio.h>
#include<stdlib.h>

enum Colors
{
  Black,
  White,
  Nil
};
enum Pieces
{
  King = 1,
  Queen = 2,
  Bishop = 3,
  Knight = 4,
  Rook = 5,
  Pawn = 6,
  Empty = -1,
};

struct Square
{
  enum Pieces piece;
  enum Colors color;
};

struct Position
{
  int row;
  int column;
};

void change_board_state (struct Square **board, enum Pieces piece,
			 enum Colors color, int row, int column);
void print_board (struct Square **board);
char *show_piece_name (struct Square piece);
void mount_board (struct Square **board);
void move (struct Square **board, struct Position current,
	   struct Position target);
int move_is_valid (struct Square current_square, struct Position current,
		   struct Position target);
void black_moves (struct Square **board);

int
main ()
{

  // same that board[8][8]
  struct Square **board = malloc (8 * sizeof (struct Square *));
  for (int column = 0; column < 8; column++)
    {
      board[column] = (struct Square *) malloc (8 * sizeof (struct Square));
    };

  mount_board (board);
  print_board (board);

  struct Position current, target;
  current.row = 1;
  current.column = 4;
  target.row = 3;
  target.column = 4;

  move (board, current, target);
  print_board (board);
  current.row = 6;
  current.column = 3;
  target.row = 4;
  target.column = 3;

  move (board, current, target);
  print_board (board);
  black_moves (board);
  return 1;
};

void
move (struct Square **board, struct Position current, struct Position target)
{

  if (move_is_valid (*(*(board + current.row) + current.column),
		     current, target) == 0)
    {
      printf ("\nMove is invalid =(\n");
      return;
    }
  struct Square curr = *(*(board + current.row) + current.column);
  struct Square targ = *(*(board + target.row) + target.column);
  change_board_state (board, curr.piece, curr.color, target.row,
		      target.column);
  change_board_state (board, Empty, Nil, current.row, current.column);
};

void
black_moves (struct Square **board)
{
  printf ("\nPossible black moves:\n");
  for (int i = 0; i < 8; i++)
    {
      printf ("  %d  ", i + 1);
      for (int j = 0; j < 8; j++)
	{
	  struct Square current_piece = *(*(board + i) + j);
	  if (current_piece.color == Black)
	    {
	      printf ("| %s  ", show_piece_name (current_piece));
	    }
	  else
	    {
	      printf ("| %s  ", " ");
	    };
	}
      printf ("\n");
      for (int z = 0; z < 9; z++)
	{
	  if (z == 0)
	    {
	      printf ("     ");
	    }
	  else
	    {
	      printf ("____ ");
	    }
	};
      printf ("\n");
    }
};

int
move_is_valid (struct Square current_square,
	       struct Position current, struct Position target)
{

  // ONLY PAWN
  if (current_square.color == White)
    {
      switch (current_square.piece)
	{
	case Pawn:
	  if (current.row < target.row &&
	      (target.column + 1 == current.column
	       || target.column - 1 == current.column
	       || target.column == current.column))
	    {
	      return 1;
	    }
	  else
	    {
	      return 0;
	    }

	  break;
	default:
	  return 1;
	}
    }
  else
    {
      switch (current_square.piece)
	{
	case Pawn:
	  if (current.row > target.row &&
	      (target.column + 1 == current.column
	       || target.column - 1 == current.column
	       || target.column == current.column))
	    {
	      return 1;
	    }
	  else
	    {
	      return 0;
	    }

	  break;
	default:
	  return 1;
	}

    }


};

void
mount_board (struct Square **board)
{
  for (int i = 0; i < 8; i++)
    {
      for (int j = 0; j < 8; j++)
	{
	  if (i == 0)
	    {
	      //white pieces
	      switch (j)
		{
		case 0:
		case 7:
		  change_board_state (board, Rook, White, i, j);
		  break;
		case 1:
		case 6:
		  change_board_state (board, Knight, White, i, j);
		  break;
		case 2:
		case 5:
		  change_board_state (board, Bishop, White, i, j);
		  break;
		case 3:
		  change_board_state (board, Queen, White, i, j);
		  break;
		case 4:
		  change_board_state (board, King, White, i, j);
		  break;
		}
	      continue;
	    }
	  if (i == 1)
	    {
	      // white pawns
	      change_board_state (board, Pawn, White, i, j);
	      continue;
	    }

	  if (i == 7)
	    {
	      // black pieces
	      switch (j)
		{
		case 0:
		case 7:
		  change_board_state (board, Rook, Black, i, j);
		  break;
		case 1:
		case 6:
		  change_board_state (board, Knight, Black, i, j);
		  break;
		case 2:
		case 5:
		  change_board_state (board, Bishop, Black, i, j);
		  break;
		case 3:
		  change_board_state (board, Queen, Black, i, j);
		  break;
		case 4:
		  change_board_state (board, King, Black, i, j);
		  break;
		}
	      continue;
	    }
	  if (i == 6)
	    {
	      change_board_state (board, Pawn, Black, i, j);
	      continue;
	      // black pawns
	    }
	  change_board_state (board, Empty, Nil, i, j);

	};
    };
};

void
change_board_state (struct Square **board, enum Pieces piece,
		    enum Colors color, int row, int column)
{
  // same that board[row][column] = piece;
  (*(board + row) + column)->piece = piece;
  (*(board + row) + column)->color = color;
};

void
print_board (struct Square **board)
{
  char columns[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };

  for (int i = 0; i < 9; i++)
    {
      if (i == 0)
	{
	  printf ("     ");
	}
      else
	{
	  printf ("  %c  ", columns[i - 1]);
	}
    };
  printf ("\n");
  for (int i = 0; i < 9; i++)
    {
      if (i == 0)
	{
	  printf ("     ");
	}
      else
	{
	  printf ("____ ");
	}
    };
  printf ("\n");

  for (int i = 0; i < 8; i++)
    {
      printf ("  %d  ", i + 1);
      for (int j = 0; j < 8; j++)
	{
	  struct Square current_piece = *(*(board + i) + j);
	  printf ("| %s  ", show_piece_name (current_piece));
	}
      printf ("\n");
      for (int z = 0; z < 9; z++)
	{
	  if (z == 0)
	    {
	      printf ("     ");
	    }
	  else
	    {
	      printf ("____ ");
	    }
	};
      printf ("\n");
    }
}

char *
show_piece_name (struct Square square)
{
  switch (square.piece)
    {
    case 1:
      return "K";
    case 2:
      return "Q";
    case 3:
      return "B";
    case 4:
      return "K";
    case 5:
      return "R";
    case 6:
      return "P";
    default:
      return " ";
    };
};
