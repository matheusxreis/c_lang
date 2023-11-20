#include"eval.h"
#include"stack_float.c"
#include <ctype.h>
#include <math.h>
#include"postfix.c"

int main() {

  char* prefix = "3+(7*9)/(9+1)^3";
  char* post;

  postfix(prefix, post);
  float result = eval(post);

  printf("Result => %f\n", result);
  return 0;
}

float eval(char* postfix) {

  struct StackF stack = create_f();

  float number1, number2, value;
  bool underflow1, underflow2;

  while(*postfix) {

    if(isdigit(*postfix)){
    
      push_f(&stack, (float)(*postfix-'0'));
    
    }else {
      
      popandtest_f(&stack,&number2, &underflow2);
      popandtest_f(&stack, &number1, &underflow1);

      if(!underflow1 && !underflow2){
        value = oper(*postfix, number1, number2);
        push_f(&stack, value);
      }else if(!underflow1 && underflow2) {
        value = number1;
        push_f(&stack, value);
      };
      
    };
    postfix++;
  };
  return pop_f(&stack);
};


float oper(char op, float number1, float number2) {
  printf("%.1f %c %.1f\n", number1, op, number2);
  switch(op) {
    case '+': return number1+number2;
    case '-': return number1-number2;
    case '*': return number1*number2;
    case '/': return number1/number2;
    case '^': return pow(number1, number2);
    default: printf("Operation undefined"); exit(1);
  }
}
