
#include<stdbool.h>

#define STACKSIZE 100
#define TOP_INDEX 0

typedef int eltype;

typedef eltype Stack[STACKSIZE];

extern eltype pop (Stack s);
extern void push (Stack s, eltype i);
extern eltype stacktop (Stack s);
extern bool empty (Stack s);
extern void create (Stack s);
extern void popandtest (Stack s, eltype * i, bool *underflow);
extern void pushandtest (Stack s, eltype * i, bool *overflow);
