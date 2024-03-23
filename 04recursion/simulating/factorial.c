#include"factorial.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("result => %d\n", factorial(1));
}

int factorial(int n) {

  struct Stack s;
  int und;
  long int result, y;
  int currparam, x;

  create(&s);
  
  currparam = n;

start:
    if(currparam <= 1) {
    result = 1;
cond:
    popandtest(&s, &currparam, &und);
    switch(und) {
      case TRUE: goto label1;
      case FALSE: goto label2;
    }
  }
  /* recursive simulation */
  x = currparam - 1;
  push(&s, currparam);
  currparam = x;
  goto start;

label2:

  y = result;
  result = currparam * y;
  goto cond;

label1:
  return result;
  
}


// Stack impl

void create(struct Stack *stack) {
  stack->top = -1; 
}
void push(struct Stack *stack, int param) {

  if(stack->top == MAXSTACK-1){
    printf("Overflow occurs\n");
    exit(1);
  }
  stack->items[++(stack->top)] = param;
}

void popandtest(struct Stack *stack, int *param, int *underflow) {
  if(stack->top<0) {
    *underflow = TRUE;
    return;
  }
  *underflow = FALSE;
  *param = stack->items[(stack->top)--];
}



