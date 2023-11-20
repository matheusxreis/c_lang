#include"postfix.h"
#include"stack_char.c"
#include<ctype.h>

/*
 * '(' -> Não tem precedência sobre ninguém e ninguém tem sobre ele; quando comparado nunca desempilhará a stack;
 *  ')' -> Todos tem precedência sobre ele; sempre desempilhará a stack;
 */

int main() {


  char* infix = "1+2+3+4+5";
  char* post;
  postfix(infix, post);
  printf("Postfix => %s\n", post);

};

void postfix(char* infix, char* postr) {

  bool underflow;
  char topsymb;
  struct Stack stack;
  stack = create();

  //reading string // that's is like (base + 0 * esize = base + 0 = first address of array) 
  while(*infix) {
      if(isdigit(*infix)) {
        *(postr++) = *infix;
      }else {
        popandtest(&stack, &topsymb, &underflow);

        while(!underflow && prdc(topsymb, *infix)) {
            *(postr++) = topsymb;
            popandtest(&stack, &topsymb, &underflow);
        };

        if(!underflow) {
          push(&stack, topsymb);
        };
        if(underflow || *infix != ')') {
          push(&stack, *infix);
        } else {
          topsymb = pop(&stack);
        };
      };
      infix++;
    };
       while(!empty(&stack)) {
          *(postr++) = pop(&stack);
       }
       *postr = '\0';
       return;
};


int prdc_order(char symb) {
  switch(symb) {
    case '+': case '-': return 1;
    case '*': case '/': return 2;
    case '^': return 3;
    default: return 0;
  }
};

bool prdc(char topsymb, char symb){
  /*
   * *>+ (2>1) TRUE
   * +>* (1>2) FALSE
   */
  if(symb == '(' || topsymb == '(') {
    return false;
  };
  if(symb == ')') {
    return true;
  }
  if(topsymb == ')'){
    printf("Operation undefined");
    exit(1);
  }
  return prdc_order(topsymb) > prdc_order(symb);
};
