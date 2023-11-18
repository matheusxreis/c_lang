#include "stack.c"


void routine_a(struct Stack* s, void* i) {
  pop(s);
  *(char*)i = *(char*)(pop(s));
};

void routine_b(struct Stack* s1, struct Stack* s2, void* i){
  push(s2, pop(s1));
  *(char*)(i) = *(char*)pop(s1);
  push(s2, i);
  push(s1, pop(s2));
  push(s1, pop(s2));
};

void routine_c(struct Stack* s1, void* i, int n) {

  for(int index = 0; index<n-1; index++){
    pop(s1);
  };
  *(char*)(i) = *(char*)pop(s1);

};

void routine_d(struct Stack* s1, struct Stack* s2, void* i, int n) {
  for(int index = 0; index<n-1; index++){
    push(s2, pop(s1));
  };
  *(char*)(i) = *(char*)pop(s1);
  push(s2, i);
 for(int index = 0; index<n; index++){
    push(s1, pop(s2));
  };
};

void routine_e(struct Stack* s1, void* i) {

  while(!empty(s1)) {
    *(char*)(i) = *(char*)pop(s1);
  };

};

void routine_f(struct Stack* s1, struct Stack* s2, void* i) {
  while(!empty(s1)) {
     push(s2, pop(s1));
  };

  *(char*)(i) = *(char*)stacktop(s2);

  while(!empty(s2)) {
    push(s1, pop(s2));
  };
};

void routine_g(struct Stack* s1, struct Stack* s2, void* i) {

  while(!empty(s1)){
    push(s2, pop(s1));
  };
  for(int index = 0; index<2; index++) {
    pop(s2);
  };
  *(char*)(i) = *(char*)pop(s2);
};



int main() {

  struct Stack s1 = create();
  struct Stack s2 = create();
  char i;
  char top;
  char items[] = "EmilyeMottaTx";

  printf("aaaa stack ai %d\n", s1.top);
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));

  /* routine A */
  routine_a(&s1, &i); // expected: T;
  top = *(char*)stacktop(&s1); // expected: a;
  printf("\nRoutine A => item: %c, top: %c\n",i, top);

  s1 = create();
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));


  /* routine B */
  routine_b(&s1, &s2, &i); // expected: T;
  top = *(char*)stacktop(&s1); // expected: x;                               
  printf("\nRoutine B => item: %c, top: %c\n",i, top);

  s1 = create();
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));


  /* routine C */
  routine_c(&s1, &i, 4); // expected: t;
  top = *(char*)stacktop(&s1); // expected: t;                               
  printf("\nRoutine C => item: %c, top: %c\n",i, top);

  s1 = create();
  s2 = create();

  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));


  /* routine D */
  routine_d(&s1, &s2, &i, 4); // expected: t;
  top = *(char*)stacktop(&s1); // expected: x;                               
  printf("\nRoutine D => item: %c, top: %c\n",i, top);

  s1 = create();
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));

  /**/


  /* routine E */
  routine_e(&s1, &i); // expected: E;
  //top = *(char*)stacktop(&s1); // expected: underflow;                               
  printf("\nRoutine E => item: %c, top: underflow\n",i);

  s1 = create();
  s2 = create();
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));
  /**/

  /* routine F */
  routine_f(&s1, &s2, &i); // expected: E;
  top = *(char*)stacktop(&s1); // expected: x;                               
  printf("\nRoutine F => item: %c, top: %c\n",i, top);

  s1 = create();
  for(int index = 0; items[index] != '\0'; push(&s1, &items[index++]));

  /**/

  /* routine G */
  routine_g(&s1, &s2, &i); // expected: i
  printf("\nRoutine G => item: %c\n", i);
  /**/
};
