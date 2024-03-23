#include"factorial.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("result => %d\n", factorial3(5));
}


int factorial3(int n){
  /* removing stack */
  int x;
  long int y;
  
  for(y=x=1; x<=n; x++){
    y*=x;
  }
  return y;


}
int factorial2(int n){
/* removing gotos */
  struct Stack s;
  int und;
  long int y;
  int x;

  create(&s);
  
  x = n;

  while(x>=1) {
    push(&s, x--);
  }
  popandtest(&s, &x, &und);
  y = 1;
  while(und == FALSE){
    y*=x;
    popandtest(&s, &x, &und);
  }
  return y;

}

int factorial(int n) {
/* simplifying gotos */
  struct Stack s;
  int und;
  long int y;
  int x;

  create(&s);
  
  x = n;

start:
    if(x <= 1) {
      y = 1;
    }else {
      push(&s, x--);
      goto start;
    }

label1:
    popandtest(&s, &x, &und);
    if(und == TRUE){
      return y;
    }
label2:
    y *= x;
    goto label1;

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



