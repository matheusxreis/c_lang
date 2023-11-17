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

  bool underflow;
  popandtest(&s, i, &underflow);


  if(underflow) {  printf("\nOccurs underflow =( \n"); }
  else { printf("\nAll is ok, folks! \n"); };
  //pop(&s); //-> underflow;
 // stacktop(&s); -> underflow occurs;
  if(empty(&s)) {
    printf("\nStack is empty =D \n");
  }else {
    printf("\nStack is not empty D= \n");
  };


 bool overflow;

 for(int i = 0; i < 100; i++) { pushandtest(&s, &items[0], &overflow); };

 if(overflow) { printf("\nOccurs overflow =(\n"); }
 else { printf("\nAll is ok, folks!\n"); };

 eltype it = stacktop(&s);
 
 printf("Top into stack: %c\n", *(char*)it); 
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
  // We shouldn't worry about overflow because a Stack has not limit
  // but in this implementation, as items in Stack are arrays, 
  // we must worry about.
  if(s->top >= STACKSIZE - 1) {
    printf("Overflow occurs\n");
    exit(0);
  };
  s->items[++(s->top)] = i;
};

void popandtest(struct Stack* s, eltype i, bool* underflow){

  if(empty(s)){
    *(underflow) = true;
    return;
  };
  *(underflow) = false;
  i = s->items[s->top--];

};

void pushandtest(struct Stack* s, eltype i, bool* overflow) {

 if(s->top >= STACKSIZE - 1){
    *(overflow) = true;
    return;
 };
 *(overflow) = false;

 s->items[++(s->top)] = i;
};

