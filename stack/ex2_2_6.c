#include"ex_2_2_6.h"
#include <math.h>
#include <stdio.h>


int main(){
  Array arr = create_arr(20);
  int x = 188;
  int y = 94;

  store(&arr, 17, &x);
  store(&arr, 12, &y);
  
  eltype elem = extract(&arr, 17);  
  printf("elem => %d\n", *(int*)elem); //expected: 188
 
  eltype elem2 = extract(&arr, 12);  
  printf("elem => %d\n", *(int*)elem2); //expected: 94
  

  int v[] = {2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};

  for(int i = 0; i<10; i++) {
    store(&arr, i, &v[i]);
  };
  for(int i = 0; i<10; i++){
    eltype elem = extract(&arr, i);
    printf("elem => %d\n", *(int*)elem); //expected: 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024
  };

 return 1;
} 


Array create_arr(int size){

  if(size>STACKSIZE) {
    printf("Operation not allowed, array so much large, stackoverflow risk\n");
    exit(1);
  };
  Array a;
  a.s1 = create();
  a.s2 = create();
  a.size = size;

  int i;
  for(i = 0; i<size ;i++) {
    void* p;
    push(&a.s1, p);
  };
  return a;
}

bool valid(Array* a, int index) {
  return index>=0 && index<a->size;
}
void store(Array* a, int index, eltype element) {
  
  if(!valid(a, index)) {
    printf("Operation not allowed, index must be between %d and %d\n", 0, a->size);
    exit(0);
  }

  for(int i = 0; i<a->size ;i++){
    push(&a->s2, pop(&a->s1));
  };

  for(int i = 0; i<a->size; i++){ 
    if(i == index) {
      push(&a->s1, element);
      pop(&a->s2);
    }else{ 
      push(&a->s1, pop(&a->s2)); 
    };
  }
};

eltype extract(Array* a, int index) {

  if(!valid(a, index)) { 
    printf("Operation not allowed, index must be between %d and %d\n", 0, a->size);
    exit(0);
  };

  for(int i = 0; i< a->size; i++) {
    push(&a->s2, pop(&a->s1));
  };

  eltype elem; 

  for(int i = 0; i < a->size; i++){
    if(i == index) {
     elem = stacktop(&a->s2);
    }
   push(&a->s1, pop(&a->s2));
  };

  return elem;
};




