
#include <stdio.h>
#define ELTYPE
typedef int eltype;
#include "queue.c"




int main() {


  Queue q;
  q.rear = q.front = MAXQUEUE -1;
  

  int x, und;
  enqueue(&q, 55);
  enqueue(&q, 66);
  enqueue(&q, 77);
  enqueue(&q, 88);

  printf("dequeue => %d\n", dequeue(&q));
  deqandtest(&q, &x, &und);
  printf("deqandtest => %d\n", x);
  //printf("dequeue => %d\n", dequeue(&q));
  deqandtest(&q, &x, &und);
  printf("deqandtest => %d\n", x);
  /* underflow
  printf("dequeue => %d\n", dequeue(&q));
  
  deqandtest(&q, &x, &und);
  if(und == TRUE){
    printf("Underflow by deqandtest\n");
  }
  */

  int emp = empty(&q);
  if(emp == TRUE){
    printf("Queue is empty\n");
  }


}
