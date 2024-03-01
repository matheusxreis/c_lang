// maximo divisor comum 
#include<stdio.h>

int mdc_iterative(int x, int y);
int mdc(int x, int y);


int main() {

  printf("mdc from 20, 24, recursive => %d and iterative => %d\n", mdc(20, 24), mdc_iterative(20, 24));

  return 1;
}

int mdc(int x, int y){

  if(y <= x && x % y == 0){
    return y;
  };

  if(x < y){
    return mdc(y, x);
  }else {
    return mdc(y, x % y);
  }

}

int mdc_iterative(int x, int y){

  int n1 = x;
  int n2 = y;

  while(n1 % n2 != 0) {
    printf("loop\n");
    if(n1<n2){
      int x = n1;
      n1 = n2;
      n2 = x;
    }else {
      int x = n1;
      n1 = n2;
      n2 = x % n2;
    }
  };

  return n2;
}
