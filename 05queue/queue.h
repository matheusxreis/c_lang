
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


/* A Queue is a FIFO (first in first out) data structure. 
 * A item is always inserted in a queue at back,
 * and removed at front.
 * */
typedef struct {
  eltype items[MAXQUEUE];
  int front, rear;
} Queue;


/* Remove the item in front of queue and return it*/
eltype dequeue(Queue *pq);

/* Insert item in back at queue */
void enqueue(Queue *pq, eltype item);

/* Returns TRUE if queue is empty and FALSE otherwise */
int empty(Queue *pq);

/*  Remove the item in front of queue and save it in *item
 *  In case of queue is empty *underflow is set TRUE, otherwise it is set FALSE
 *  */
void deqandtest(Queue *pq, eltype *item, int *underflow);


