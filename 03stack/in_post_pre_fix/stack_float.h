// stack ADT
#include<stdbool.h>

#define STACKSIZE 100
#define INITIAL_TOP_VALUE -1

typedef float eltypef;

/*
 * Stack representation using struct and array;
 * The problem this way represent a stack is that its size is limited by array size;
 * In the concept of the Stack, its has not limit;
 * The Stack has a limit may generate a stack overflow, which in this case, can be avoid 
 * (not in all cases and not forever) by incrementing the STACKSIZE const.
 */
struct StackF
{
  int top;			/* Holds current stack top */
  eltypef items[STACKSIZE];	/* Holds all stack items */
};

/* 
 * push()
 * Add eltype item into top from stack
 * stackoverflow can occurs here
 */
extern void push_f (struct StackF *s, eltypef item);

/*
 * pop()
 * Return the last item that have been added into stack 
 * underflow can occurs here
 */
extern eltypef pop_f (struct StackF *s);
/*
 * stacktop()
 * Returns last item that have been added into stack
 * underflow can occurs here and generally, it implies end of program
 */
extern eltypef stacktop_f (struct StackF *s);

/*
 * Returns TRUE if stack is empty and FALSE if not
 */
extern bool empty_f (struct StackF *s);

/*
 * Init a Stack
 */
extern struct StackF create_f ();


/*
 * popandtest()
 * Stores last item in eltype i parameters, and remove it from stack
 * Underflow can occurs here, but it dont implies on the end of program
 */
extern void popandtest_f (struct StackF *s, eltypef * i, bool *underflow);

/*
 * pushandtest()
 * Add eltype i into stack, and in case of overflow it doesn't implies end of program;
 */
extern void pushandtest_f (struct StackF *s, eltypef i, bool *overflow);
