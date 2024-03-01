#include<stdio.h>


int func(int n) {

  int r = 0;

  for(int i = 0; i<=n; i++){
    r+=(n-i);
  }

  return r;
}

int func_recursive(int n){
  if(n == 0){
    return 0;
  }
  return n + func_recursive(n-1);
}

int main(){


  printf("recursive with 6, 2, 12, 0, 1 => %d %d %d %d %d\n", func_recursive(6), func_recursive(2), func_recursive(12), func_recursive(0), func_recursive(1));
  printf("iterative with 6, 2, 12, 0, 1 => %d %d %d %d %d\n", func(6), func(2), func(12), func(0), func(1));


}
