

#include <stdio.h>
#include <stdlib.h>
#include"queue_w_list.c"

int main() {

  Queue q = create();

  if(empty(&q)) {
    printf("Queue is empty\n");
  }
  enqueue(&q, 40);
  enqueue(&q, 20);
  enqueue(&q, 10);
  enqueue(&q, 4);
  
  if(empty(&q)) {
    printf("Queue is empty\n");
  }

  for(int i = 0; i<4; i++) {
    printf("%d\n", dequeue(&q));
  }
  
  if(empty(&q)) {
    printf("Queue is empty\n");
  }

}
