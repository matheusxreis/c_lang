/// Ackerman Function 
#include<stdio.h>

int a(int m, int n);


int main(){

  
  int result = a(2, 2);

  printf("result a(2, 2) => %d\n", a(2, 2)); //expected: 7

  return 1;
}


int a(int m, int n){

  if(m == 0){
    return n + 1;
  }
  if(m != 0 && n == 0){
    return a(m - 1, 1);
  }
  
  return a(m - 1, a(m, n - 1));
}
