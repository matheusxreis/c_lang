#include"stack.c"

/*
 * Suppose that a language has not a Array type, only Stack
 * this would be a Array type implementation using only a Stack language struct
 * Not care how the Stack's implementation is done in language (but if the lang has not
 * a array type, its Stack's implementation probably is not using a Array)
 */
typedef struct
{
  struct Stack s1;
  struct Stack s2;
  int size;
} Array;

/*
 * Extract the element from index position, from Array collection
 */
extern eltype extract (Array * a, int index);	// return arr[i] 

/**
 * Insert an element in Array's index position 
 */
extern void store (Array * a, int index, eltype element);	// arr[i] = element 

/*
 * Define a array, passing a size to it
 */
extern Array create_arr (int size);

/*
 * Returns if a index is valid or not;
 */
extern bool valid (Array * a, int index);
