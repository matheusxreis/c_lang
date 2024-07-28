

#include <stdio.h>
#define ELTYPE
typedef int eltype;
//#include "queue.c"
#include "pqueue.c"



int main() {


  PQueue q = create();
  

  int x, und;
  penqueue(&q, 98);
  penqueue(&q, 12);
  penqueue(&q, 140);
  penqueue(&q, 10000);
  penqueue(&q, -20);

  //penqueue(&q, 30);

  printf("dequeue => %d\n", pdequeue(&q));
  //deqandtest(&q, &x, &und);
  //printf("deqandtest => %d\n", x);
  printf("dequeue => %d\n", pdequeue(&q));

  printf("dequeue => %d\n", pdequeue(&q));
  printf("dequeue => %d\n", pdequeue(&q));
  printf("dequeue => %d\n", pdequeue(&q));

  printf("dequeue => %d\n", pdequeue(&q));
  //deqandtest(&q, &x, &und);
  //printf("deqandtest => %d\n", x);
  /* underflow
   printf("dequeue => %d\n", dequeue(&q));
  
  deqandtest(&q, &x, &und);
  if(und == TRUE){
    printf("Underflow by deqandtest\n");
  }
  */

  


}
