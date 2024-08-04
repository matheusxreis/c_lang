

#include <stdio.h>
#include <stdlib.h>
#include"clinked_list.c"

int main() {

 
  node* queue = create();
  node* stack = create();

  infotype x;
  x.info.intInfo = 5;
  x.utype = INT;
  
  insert(&queue, x);
  push(&stack, x);

  x.info.intInfo = 8;
  insert(&queue, x);
  push(&stack, x);

  x.info.intInfo = 12;
  insert(&queue, x);
  push(&stack, x);

  x.info.intInfo = 41;
  insert(&queue, x);
  push(&stack, x);
  
  //pop(&list);
  pop(&queue);
  pop(&queue);

  pop(&queue);
  pop(&queue);

  insert(&queue, x);

  node* n = pop(&queue);
  insert(&queue, x);


  print_list(&queue->next, &queue);
  printf("\n");
  print_list(&stack->next, &stack);
  printf("\n");

}
