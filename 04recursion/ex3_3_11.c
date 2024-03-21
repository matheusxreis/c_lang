//// 

#include<stdio.h>


#define N 10
#define TRUE 1
#define FALSE 2

enum MOVES {
  DOWN,
  RIGHT,
  UP, 
  LEFT
};

void drawmaze();

int move(enum MOVES m, int r, int c);
char read_move(enum MOVES m);



static int maze[N][N] =  {
    {0, 1, 1, 0, 1, 0, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 0, 0, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 1, 0, 1, 0},
    {1, 1, 0, 0, 0, 0, 1, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 1, 0, 1},
    {1, 1, 0, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 0, 0, 0, 0, 0, 1, 0, 1}, 
    {1, 1, 1, 0, 1, 1, 0, 0, 0, 0},
    {1, 1, 0, 0, 0, 0, 0, 1, 1, 0}
};


int try(int row, int col);

int main() {


    if(try(0, 0)) {
      drawmaze();
    };

  
  return 1;
}



int try(int row, int col) {
  
  
  enum MOVES m = DOWN;
  
  if(maze[row][col] == 1) {
    return FALSE;
  }

  for(int i = 0; i<4; i++) {
    m = i;
    
    if(row == N-1 && col == N-1) {

      printf("move: %c\n", read_move(m));
      return TRUE;
    }
    if(move(m, row, col) == TRUE) {
      printf("move: %c\n", read_move(m));
      return TRUE;
    }
  }

  return FALSE;

}


int move(enum MOVES m, int r, int c) {

  int row = r; 
  int col = c;


  printf("move => %c, from [%d][%d]\n", read_move(m), r, c);
  switch(m) {
    case DOWN:
      if(row+1>N-1) {
        return FALSE;
      }
      row+=1;
    case UP:
      if(row-1<0) {
        return FALSE;
      }
      row-=1;
    case LEFT:
      if (row-1<0){
        return FALSE;
      }
      col -=1;
    case RIGHT:
      if (row+1>N-1){
        return FALSE;
      }
      col +=1;
  }
  return try(row, col);
}

char read_move(enum MOVES m) {
  switch(m){
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
void drawmaze(){

  for(int row = 0; row < N; row ++){
    for(int col = 0; col < N; col++){
      if(maze[row][col] == 1) { 
          printf(" . ");
      }else {
          printf(" x ");
      }
    }
    printf("\n");
  }  
}

int is_good(int row, int col) {
    return row == FALSE && col == FALSE;
}

