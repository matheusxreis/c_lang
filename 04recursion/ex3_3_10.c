// N queens problem
#include<stdio.h>

#define N 4

static int board[N][N];

#define TRUE 1
#define FALSE 0


void drawboard();
int try(int row);
int is_safe();

int main() {



  for(int i = 0; i<N; i++){
    for(int j = 0; j<N; j++){
      board[i][j] = FALSE;
    }
  }
  
  int result = try(0);
  
  drawboard();

  if(result == FALSE) { printf("It's not possible\n"); };

}


int try(int row) {
  int col;
  for(col = 0; col < N; col++){
    board[row][col] = TRUE;
    if(row == 7 && is_safe() == TRUE){
      return TRUE;
    }
    if(row < 7 && is_safe() == TRUE && try(row+1) == TRUE){
      return TRUE;
    }
    board[row][col] = FALSE;
  }
  return FALSE;
}

int is_safe() {

 int row, col;
 int on_attack = -1;
  
 for(row = 0; row < N; row++){


    //on_attack = -1;

    for(col = 0; col < N; col++){
      // verify row
      if(board[row][col] == TRUE){
        on_attack++;
        // verify col
        int r;
        for(r= row+1; r<N; r++){
         if(board[r][col] == TRUE) {
           return FALSE;
          }
        }
        // verify left diag
        int c;
        for(r = row+1, c = col-1; r<N && c>=0; r++, c--){
          if(board[r][c] == TRUE){
            return FALSE;
          }
        }
        // verify right diag
        for(r = row+1, c = col+1; r<N && c<N; r++, c++){
          if(board[r][c] == TRUE){
            return FALSE;
          }
        }
      
      }
    }
    
 };

 return TRUE;
}

void drawboard(){

  for(int row = 0; row < N; row ++){
    for(int col = 0; col < N; col++){
      if(board[row][col]== TRUE) { 
          printf(" Q ");
      }else {
          printf(" . ");
      }
    }
    printf("\n");
  }  
}
