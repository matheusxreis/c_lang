

#include <stdio.h>
#define ELTYPE
typedef int eltype;
#include "queue.c"



int main() {


  Queue q = create();
  

  int x, und;
  enqueue(&q, 98);
  enqueue(&q, 12);
  enqueue(&q, 140);
  enqueue(&q, 10000);


  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));

  enqueue(&q, 98);
  enqueue(&q, 12);
  enqueue(&q, 140);
  enqueue(&q, 10000);


  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));

  
  enqueue(&q, 98);
  enqueue(&q, 12);
  enqueue(&q, 140);
  enqueue(&q, 10000);


  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));


  enqueue(&q, 98);
  enqueue(&q, 12);
  enqueue(&q, 140);
  enqueue(&q, 10000);


  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));
  printf("dequeue => %d\n", dequeue(&q));


  enqueue(&q, 98);
  enqueue(&q, 12);
  enqueue(&q, 140);
  enqueue(&q, 10000);



  printf("\nrear=>%d front=>%d\n", q.rear, q.front);
  enqueue(&q, -20);

  printf("\nrear=>%d front=>%d\n", q.rear, q.front);
  enqueue(&q, 30);

  printf("dequeue => %d\n", dequeue(&q));
  enqueue(&q, 30);


  printf("\nrear=>%d front=>%d\n", q.rear, q.front);
  //printf("dequeue => %d\n", dequeue(&q));
  //deqandtest(&q, &x, &und);
  //printf("deqandtest => %d\n", x);
  //printf("dequeue => %d\n", dequeue(&q));

 
  //enqueue(&q, 10000);
  //printf("dequeue => %d\n", dequeue(&q));
  //printf("dequeue => %d\n", dequeue(&q));


  //enqueue(&q, 10000);

  //deqandtest(&q, &x, &und);
  //printf("deqandtest => %d\n", x);
  /* underflow
   printf("dequeue => %d\n", dequeue(&q));
  
  deqandtest(&q, &x, &und);
  if(und == TRUE){
    printf("Underflow by deqandtest\n");
  }
  */

  if(empty(&q)) {
    printf("Queue is empty\n");
  }


}
