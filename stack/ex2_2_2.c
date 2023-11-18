

#include <stdio.h>
#include <stdlib.h>

int SIZE = 100;
int op = -1;

void push() {
  if(op>=SIZE-1){
    printf("Overflow =(\n");
    exit(1);
  };
  op++;
};

void pop() {
  if(op<0){
    printf("Underflow =(\n");
    exit(1);
  }
  op--;
};

int main() {

  for(int i = 0; i<101; i++) { push(); } 

  return 1;
}
