#include"ex2_2_4.h"
#include <stdio.h>
#include <stdlib.h>

void create(Stack s) {
  s[TOP_INDEX] = 0;
};
void push(Stack s, eltype i){
  if(s[TOP_INDEX] >= STACKSIZE - 1){
    printf("Overflow occurs =( \n");
    exit(1);
  }    
  s[++(s[TOP_INDEX])] = i;
};
eltype pop(Stack s) {
  if(empty(s)) {
    printf("Underflow occurs =( \n");
    exit(1);
  }
  return s[(s[TOP_INDEX])--];
};
bool empty(Stack s) {
 return s[TOP_INDEX]==0;
};
eltype stacktop(Stack s) {
  return s[s[TOP_INDEX]];
};

void popandtest(Stack s, eltype* i, bool* underflow) {
  if(empty(s)){
    *underflow = true;
    return;
  }
  *i = s[(s[TOP_INDEX]--)]; // i could only call pop(s) 
};

void pushandtest(Stack s, eltype* i, bool* overflow) {
  if(s[TOP_INDEX] >= STACKSIZE - 1){
    *overflow = true;
    return;
  }
  s[++(s[TOP_INDEX])] = *i; // i could only call push();
};


