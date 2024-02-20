// write a iterative algoritm to evalute
// a * b using addtion
#include<stdio.h>

int multiply(int a, int b);

int main(){

  int x = multiply(6, 9);
  int y = multiply(7, 4);
  int z = multiply(55, 82);

  printf("x: %d, y:%d, z:%d", x, y, z);
  
  return 0;
}


int multiply(int a, int b){
    
  int x = a;
  for(int i = 1; i<b; i++){
    x+=a;
  }
  return x;

}
