#include"queue.h"
#include<stdio.h>
#include<stdlib.h>

void enqueue(Queue *pq, eltype item){

  if(pq->rear == MAXQUEUE-1) {
    pq->rear = 0;
  }else {
    pq->rear++;
  }

  if(pq->rear == pq->front) {
    /* There is always 1 position to overflow control,
     * So, if MAXQUEUE is 100, only 99 items can be inserted
     * if MAXQUEUE is 2 (two items);
     * rear, front = 2(MAXQUEUE) - 1 = 1
     * /first insert/
     * rear = 0;
     * pq[0] = item;
     * /second insert/
     * rear++ = 1
     * rear == front 
     * OVERFLOW
     */
    printf("Queue overflow occurs\n");
    exit(1);
  }

  pq->items[pq->rear] = item;
}

eltype dequeue(Queue *pq) {

  if(pq->front == pq->rear) {
    printf("Queue underflow occurs\n");
    exit(1);
  }
  
  if(pq->front == MAXQUEUE - 1){
    pq->front = 0;
  }else {
    pq->front++;
  }

  return pq->items[pq->front];

}

void deqandtest(Queue *pq, eltype *item, int *underflow){
  
  if(pq->front == pq->rear){
    *underflow = TRUE;
    return;
  }
  *underflow = FALSE;
  
  if(pq->front == MAXQUEUE - 1){
    pq->front = 0;
  }else {
    pq->front++;
  }

  *item = pq->items[pq->front];

}

int empty(Queue *pq) {
  return (pq->rear == pq->front) ? TRUE : FALSE;
}
  
