

#define STACKSIZE 100
typedef void* eltype;

struct Stack {
   int top;
   eltype items[STACKSIZE];
};
/*
 * Structure with two Stack implemented using a single array,
 * which grown in opposite direction
 */
typedef struct  { struct Stack s[2]; int size; } DoubleStack;

/*
 * Adding a item in stack 1;
 * Overflow only occurs if stack 1 and 2 are full;
 */
void push1(DoubleStack* s, eltype i);
/*
 * Adding a item in stack 2;
 * Overflow only occurs if stack 1 and 2 are full;
 */
void push2(DoubleStack* s, eltype i);

/**
 * Retrieving a item from stack1
 * Underflow only occurs if both stack are empty
 */
eltype pop1(DoubleStack* s);

/**
 * Retrieving a item from stack1
 * Underflow only occurs if both stack are empty
 */
eltype pop2(DoubleStack* s);


DoubleStack create_double_stack(int size);
