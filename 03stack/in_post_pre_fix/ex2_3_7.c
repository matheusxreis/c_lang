#include"ex2_3_7.h"
#include <stdio.h>

#ifndef MAIN_EXIST
#define MAIN_EXIST

#include"postfix.c"

int main(){

      char* a = malloc(100);
      char* r = malloc(100);

      while(fgets(a, 100, stdin)){
          
           prefix(a, r);
           printf("result from infix: %s\nprefix: %s\npostfix:",a, r);
      }

      free(a);
      free(r);
      return 0;
};
#endif


void prefix(char* infix, char* poststr) {
  char* reverseInfix = malloc(sizeof(infix));
  char* reversePostfix = malloc(sizeof(infix));
  reverse(infix, reverseInfix);
  postfix(reverseInfix, reversePostfix);
  printf("reverseInfix=>%s\nreversePostix=>%s\n", reverseInfix, reversePostfix);
  reverse(reversePostfix, poststr);
};


void reverse(char* str, char* poststr) {

  
  struct Stack s1 = create();

  while(*str){
    push(&s1, *str);
    str++;
  };

  while(!empty(&s1)) {
      
    char value= pop(&s1);

    if(value == '(') {
      value = ')';
    }else if(value==')') {
      value ='(';
    };

    (*poststr++) =  value;
  };
}

