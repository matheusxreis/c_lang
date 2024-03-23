#define MAXSTACK 50

struct dataarea {

  int param; 
  int x;
  long int y;
  short int retaddr;

};

struct Stack {
  int top;
  struct dataarea item[MAXSTACK];
};

void push(struct Stack *stack, struct dataarea *data);

void popsub(struct Stack *stack, struct dataarea *data);

void create(struct Stack *stack);


int factorial(int n);
