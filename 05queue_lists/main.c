

#include <stdio.h>
#include <stdlib.h>
#include"stack.c"


int main() {

  Stack s = create();

  if(empty(&s)) {
    printf("Stack is empty\n");
  }
  push(&s, 40);
  push(&s, 20);
  push(&s, 10);
  push(&s, 4);
  
  if(empty(&s)) {
    printf("Stack is empty\n");
  }

  for(int i = 0; i<4; i++) {
    printf("%d\n", pop(&s));
  }
  
  if(empty(&s)) {
    printf("Stack is empty\n");
  }
}

