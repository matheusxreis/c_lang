

#ifndef ELTYPE
  typedef void* eltype;
#endif

#ifndef TRUE 
  #define TRUE 1
#endif

#ifndef FALSE 
  #define FALSE 0 
#endif

#define MAXQUEUE 5

/*
 * Priority Queue
 *
 * A priority queue is a sorted queue, 
 * where the removed item always going to be
 * made following an order
 *
 * This implementation use a array,
 * which is not the best alternative
 */
#ifndef PQUEUE
typedef struct {
  eltype items[MAXQUEUE];
  int front, rear;
} PQueue;
#endif


/* Remove the item in front of queue and return it*/
eltype pdequeue(PQueue *pq);

/* Insert and sorting an item in back at queue */
void penqueue(PQueue *pq, eltype item);


