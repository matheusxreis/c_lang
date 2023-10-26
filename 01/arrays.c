//
#include<stdio.h>
#include<stdlib.h>




int* create(int size) {
  int* arr = malloc(size * sizeof(int));
  return arr;
};
int insert(int *arr, int i, int value) {
  *(arr+i) = value;
  return 1;
};
int get(int *arr, int i) {
  return *(arr+i);
};

int main() {

  int* arr = create(5);
  insert(arr, 0, 100);
  insert(arr, 1, 200);
  insert(arr, 2, 300);
  
  printf("the value is 1: %d, 2: %d, 3: %d", get(arr, 0), get(arr, 1), get(arr, 2));

  return 1;
};

void arrays() { 
  // strings arrays
  char *pointers[] = {"Matheus Reis", "oi", "Eai, beleza???", "Diálogo", "Amém", "test"}; // right way, without memory wastage
  char names[][10] = {"Matheus", "Emilye"}; // wrong way, memory wastage;
  
  // dinamic size array
  char *sized;
  sized = malloc(5*sizeof(char *)); // -> heap
  
  int n1 = 10;
  int n2 = 20;
  int n3 = 30;
  int n4 = 40;

  int *p_integers[] = {&n1, &n2, &n3, &n4};

  for(int i = 0; i <= 5; i++) {
    sized[i] = '1';
    printf("%s ", pointers[i]);
  }
  
  for(int i = 0; i <= 5; i++) {
    printf("%c", sized[i]);
  }

  for (int i = 0; i <= sizeof(p_integers)/sizeof(&p_integers[0])-1; i++){
    // printing a pointers array works like that
    // *n[1] = (base + 1 * esize) -> *(pointer in 1 position) = value;  
    printf("%c ", (*pointers[i])); //
    printf("%d ", (*p_integers[i]));
  };
  
  free(sized);
};

