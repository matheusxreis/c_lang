

#include <stdio.h>
#include <stdlib.h>
#include"pqueue_w_list.c"

int main() {

  PQueue q = create();

  penqueue(&q, 21);
  penqueue(&q, -1);
  penqueue(&q, 40);
  penqueue(&q, 20);
  penqueue(&q, 277);
  penqueue(&q, 10);
  penqueue(&q, 4);
  penqueue(&q, 21);
  penqueue(&q, 1000);
  penqueue(&q, 0);


  for(int i = 0; i<10; i++) {
    printf("%d\n", pdequeue(&q));
  }
  

}
