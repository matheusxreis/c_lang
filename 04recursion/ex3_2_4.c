#include<stdio.h>

int gfib(int f0, int f1, int n);


int main() {

  printf("result => %d\n", gfib(0, 1, 13)); // expected: 233
  printf("result => %d\n", gfib(3, 3, 3)); // expected: 9                                       
  printf("result => %d\n", gfib(5, 7, 4)); // expected: 31
  printf("result => %d\n", gfib(8, 19, 4)); // expected: 73           
  printf("result => %d\n", gfib(12, 12, 9)); // expected: 660

  return 1;
}

int gfib(int a, int b, int n) {


  if(n == 0) {
    return a;
  }
  if(n == 1) {
    return b;
  }

  return (gfib(a, b, n-1)) + (gfib(a, b, n-2));
}


