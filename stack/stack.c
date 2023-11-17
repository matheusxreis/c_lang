#include"stack.h"
#include <stdio.h>
#include <stdlib.h>

int INITIAL_TOP_VALUE = -1;

int main() {

  
  struct Stack s = create();

  char items[] = "MATHEUS REIS";

  for(int i = 0; items[i] != '\0'; push(&s, &items[i++]));
  eltype i = stacktop(&s);
  printf("Top into stack: %c\n", *(char*)i);
  for(int i = 0; items[i] != '\0'; i++) {
    eltype i = pop(&s);
    printf("%c", *(char*)i);
  };
 // pop(&s); -> underflow;
 // stacktop(&s); -> underflow occurs;
  if(empty(&s)) {
    printf("\nStack is empty =D \n");
  }else {
    printf("\nStack is not empty D= \n");
  }
};


bool empty(struct Stack* s){ 
  return s->top<0;
};

eltype stacktop(struct Stack* s){
  if(empty(s)){
    printf("Underflow occurs\n");
    exit(0);
  };
  return s->items[s->top];
};

struct Stack create() {
  struct Stack s;
  s.top = INITIAL_TOP_VALUE;
  return s;
};

eltype pop(struct Stack* s){
  if(empty(s)) {
    printf("Underflow occurs\n");
    exit(0);
  }
  return s->items[s->top--];
};
void push(struct Stack* s, eltype i){
  s->items[++(s->top)] = i;
};


