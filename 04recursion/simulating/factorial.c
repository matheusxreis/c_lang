#include"factorial.h"
#include<stdio.h>
#include<stdlib.h>

int main() {
  printf("result => %d\n", factorial(5));
}

int factorial(int n) {

  struct Stack s;
  struct dataarea currentarea;
  short i;  /* to save return address */
  long int result; /* result from call */

  create(&s);

  currentarea.param = 0;
  currentarea.x = 0;
  currentarea.y = 0;
  currentarea.retaddr = 0;

  /* pushing artificial data for case n is 0 */
  push(&s, &currentarea);

  /* define initial param and return address */
  currentarea.param = n;
  currentarea.retaddr = 1;

start:
  if(currentarea.param == 1) {
    result = 1;
    i = currentarea.retaddr;
    popsub(&s, &currentarea);
cond:
    switch(i) {
      case 1: goto label1;
      case 2: goto label2;
    }
  }
  /* recursive simulation */
  currentarea.x = currentarea.param - 1;
  push(&s, &currentarea);
  currentarea.param = currentarea.x;
  currentarea.retaddr = 2; 
  goto start;

label2:

  currentarea.y = result;
  result = currentarea.param * currentarea.y;
  i = currentarea.retaddr;
  popsub(&s, &currentarea);

  goto cond;

label1:
  return result;
  
}


// Stack impl

void create(struct Stack *stack) {
  stack->top = -1; 
}
void push(struct Stack *stack, struct dataarea *data) {

  if(stack->top == MAXSTACK-1){
    printf("Overflow occurs\n");
    exit(1);
  }
  stack->item[++(stack->top)] = *data;
}

void popsub(struct Stack *stack, struct dataarea *data) {
  
  if(stack->top < 0){
    printf("Underflow occurs\n");
    exit(1);
  }
  *data = stack->item[(stack->top)--];
}


