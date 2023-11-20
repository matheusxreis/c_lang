#include"stack_float.h"
#include <stdio.h>
#include <stdlib.h>


bool empty_f(struct StackF* s){ 
  return s->top<0;
};

eltypef stacktop_f(struct StackF* s){
  if(empty_f(s)){
    printf("Underflow occurs\n");
    exit(0);
  };
  return s->items[s->top];
};

struct StackF create_f() {
  struct StackF s;
  s.top = INITIAL_TOP_VALUE;
  return s;
};

eltypef pop_f(struct StackF* s){
  if(empty_f(s)) {
    printf("Underflow occurs\n");
    exit(0);
  }
  return s->items[s->top--];
};
void push_f(struct StackF* s, eltypef i){
  // We shouldn't worry about overflow because a Stack has not limit
  // but in this implementation, as items in Stack are arrays, 
  // we must worry about.
  if(s->top >= STACKSIZE - 1) {
    printf("Overflow occurs\n");
    exit(0);
  };
  s->items[++(s->top)] = i;
};

void popandtest_f(struct StackF* s, eltypef* i, bool* underflow){

  if(empty_f(s)){
    *(underflow) = true;
    return;
  };
  *(underflow) = false;
  *i = s->items[s->top--];

};

void pushandtest_f(struct StackF* s, eltypef i, bool* overflow) {

 if(s->top >= STACKSIZE - 1){
    *(overflow) = true;
    return;
 };
 *(overflow) = false;

 s->items[++(s->top)] = i;
};

