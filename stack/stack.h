// stack ADT
#include<stdbool.h>

#define STACKSIZE 100

extern int INITIAL_TOP_VALUE;

typedef void* eltype;

/*
 * Stack representation using struct and array;
 * The problem this way represent a stack is that its size is limited by array size;
 * In the concept of the Stack, its has not limit;
 * The Stack has a limit may generate a stack overflow, which in this case, can be avoid 
 * (not in all cases and not forever) by incrementing the STACKSIZE const.
 */
struct Stack{
  int top;              /* Holds current stack top */
  eltype items[STACKSIZE]; /* Holds all stack items */
};

/* 
 * push()
 * Add eltype item into top from stack
 * stackoverflow can occurs here
 */
extern void push(struct Stack* s, eltype item);

/*
 * pop()
 * Return the last item that have been added into stack 
 * underflow can occurs here
 */
extern eltype pop(struct Stack* s);
/*
 * stacktop()
 * Returns last item that have been added into stack
 * underflow can occurs here
 */
extern eltype stacktop(struct Stack* s);

/*
 * Returns TRUE if stack is empty and FALSE if not
 */
extern bool empty(struct Stack* s);

/*
 * Init a Stack
 */
extern struct Stack create();
