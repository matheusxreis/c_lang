#include<stdio.h>
#include<stdlib.h>
#include"pqueue.h"


PQueue create() {


  PQueue q;
  q.rear = q.front = 0;

  return q;
}

eltype pdequeue(PQueue *pq) {
 
  if(pq->rear == 0) {
    printf("Queue Underflow occurs\n");
    exit(1);
  }
  
  /* find smallest index */
  int index = 0;

  for(int i = 0; i != pq->rear;i++) {
    if(pq->items[index] > pq->items[i]) {
      index = i;
    } 
  }

  eltype x = pq->items[index];

  /* compact queue */
  for(int i = index; i != pq->rear; i++){
    pq->items[i] = pq->items[i+1];
  }

  pq->rear--;

  return x;
}

void penqueue(PQueue *pq, eltype item){

  if(pq->rear == MAXQUEUE) {
    printf("Queue Overflow occurs\n");
    exit(1);
  }

  pq->items[pq->rear++] = item;
}


