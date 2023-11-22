#include"eval.h"
#include"stack_float.c"
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include"postfix.c"


float eval(char* postfix) {

  struct StackF stack = create_f();

  float number1, number2, value;
  bool underflow1, underflow2;

  while(*postfix) {

    if(isdigit(*postfix)){
   
      float number = (*postfix-'0');
   
      while(isdigit(*(++postfix))){
        number = (int)number*10 + (float)(*postfix)-'0'; // 1*10 + 1 = 11;   
      };

      push_f(&stack, number);
      
      (--postfix);

    }else if(*postfix != ' ') {

      popandtest_f(&stack,&number2, &underflow2);
      popandtest_f(&stack, &number1, &underflow1);

      if(!underflow1 && !underflow2){
        value = oper(*postfix, number1, number2);
        push_f(&stack, value);
      }else if(underflow1 && !underflow2) {
        value = number2;
        push_f(&stack, value);
      };
      
    };
    postfix++;
  };
  return pop_f(&stack);
};


float oper(char op, float number1, float number2) {
 // printf("%.1f %c %.1f\n", number1, op, number2);
  switch(op) {
    case '+': return number1+number2;
    case '-': return number1-number2;
    case '*': return number1*number2;
    case '/': return number1/number2;
    case '^': return pow(number1, number2);
    default: printf("Operation undefined"); exit(1);
  }
}
