// Find all possible K combinations, in N itens
#include<stdio.h>

int comm(int n, int r);

int main() {
  printf("comm(4, 3) => %d\n", comm(4, 3));
}

int comm(int n, int k) {

 if( k == 0 || k == n){
   return 1;
 };
  
 return comm(n-1, k) + comm(n -1, k - 1);
}
