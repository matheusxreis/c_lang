#include <stdlib.h>
#define ELTYPE
typedef char eltype;

#include"expression_tree.h"



int is_operator(char c){
  return c == '*' || c == '+' || c == '/' || c == '-' || c == '^';
}
// Necessary use a Stack to save the current state from expression
// This Stack is implemented using a binary tree node as a linked list, and the property father is used as next property
//  [ C] -> [ B ] -> [ A ]
//  [ * ] -> [ A ]
//  /   \
//[B]   [C]
//

void push(node_b ** stack, node_b* item) { 

  item->father = *stack;
  *stack = item;
}

node_b* pop(node_b ** stack) {

  node_b* temp = *stack; 
  *stack = (*stack)->father;
  return temp;

}
//


void from_postfix(char* str, node_b** tree) {

  node_b* stack = maketree();

  while(*str) {
 
  node_b* t = (node_b*)malloc(sizeof(node_b));
  setdata(t, *str);

   if(is_operator(*str)) { 
      t->right = pop(&stack);
      t->left = pop(&stack);
    }
   push(&stack, t);
   str++;

  }

  *tree = pop(&stack);
}
