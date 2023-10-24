//
#include<stdio.h>
#include<stdlib.h>

int main() {

  // strings arrays
  char *pointers[] = {"Matheus Reis", "oi", "Eai, beleza???", "Diálogo", "Amém", "test"}; // right way, without memory wastage
  char names[][10] = {"Matheus", "Emilye"}; // wrong way, memory wastage;
  
  // dinamic size array
  char *sized;
  sized = malloc(5*sizeof(char *)); // -> heap


  for(int i = 0; i <= 5; i++) {
    sized[i] = '1';
    printf("%s ", pointers[i]);
  }
  for(int i = 0; i <= 5; i++) {
    printf("%c", sized[i]);
  }
  
  free(sized);
};




