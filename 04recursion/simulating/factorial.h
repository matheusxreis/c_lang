#define MAXSTACK 50
#define FALSE 0
#define TRUE 1

struct Stack {
  int top;
  int items[MAXSTACK];
};

void push(struct Stack *stack, int param);
void popandtest(struct Stack *stack, int *param, int *underflow);

void create(struct Stack *stack);


int factorial(int n);
