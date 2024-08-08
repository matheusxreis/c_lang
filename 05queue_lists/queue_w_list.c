#include<stdio.h>
#include<stdlib.h>
#define QUEUE
#define ELTYPE


typedef int eltype;

typedef struct nodetype
{
  eltype value;
  struct nodetype *next;
} node;


typedef struct
{
  node *front;
  node *rear;
} Queue;

#include"queue.h"



Queue
create ()
{

  Queue q;
  q.rear = NULL;
  q.front = NULL;
  return q;

}

void
enqueue (Queue * pq, eltype item)
{

  node *n = (node *) malloc (sizeof (node));
  n->value = item;
  n->next = NULL;

  if (pq->front == NULL)
    {
      pq->front = n;
      pq->rear = n;
      return;
    }

  pq->rear->next = n;
  pq->rear = n;
}

eltype
dequeue (Queue * pq)
{

  if (pq->front == NULL)
    {
      printf ("Queue Underflow occurs\n");
      exit (1);
    }

  eltype item = pq->front->value;
  pq->front = pq->front->next;

  return item;
}

int
empty (Queue * pq)
{
  return (pq->front == NULL || pq->rear == NULL);
}
