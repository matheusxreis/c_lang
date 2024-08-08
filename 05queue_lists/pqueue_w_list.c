// PRIORITY QUEUE USING LIST
#include<stdio.h>
#define PQUEUE
#define ELTYPE
#define IS_LESS_THAN <
#define IS_BIGGER_THAN >

typedef int eltype;

typedef struct nodetype
{
  eltype value;
  struct nodetype *next;
} node;

typedef struct
{
  node *front;
} PQueue;

#include "pqueue.h"
#include<stdlib.h>


PQueue
create ()
{
  PQueue pq;
  pq.front = NULL;
  return pq;
}

/* Remove the item in front of queue and return it*/
eltype
pdequeue (PQueue * pq)
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

void
sort (node * prev, node * current, node * item)
{

  if (current == NULL)
    {
      // case the item be the last
      prev->next = item;
      return;
    }

  if (current->value IS_BIGGER_THAN item->value && prev == NULL)
    {
      // case the item be the first
      item->next = current;
      return;

    }

  if (current->value IS_BIGGER_THAN item->value)
    {
      prev->next = item;
      item->next = current;
      return;
    }
  return sort (current, current->next, item);
}

/* Insert and sorting an item in back at queue */
void
penqueue (PQueue * pq, eltype item)
{

  node *n = (node *) malloc (sizeof (node));
  n->value = item;
  n->next = NULL;

  if (pq->front == NULL)
    {
      pq->front = n;
      return;
    }


  sort (NULL, pq->front, n);

  if (n->next == pq->front)
    {
      pq->front = n;
    }

}

int
empty (PQueue * pq)
{
  return pq->front == NULL;
}
