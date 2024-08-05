#include "clinked_list.c"
#include <stdio.h>


/*  THE JOSEPHUS PROBLEM
 *  N = number of people to be executed
 *  k = Indicates the k-1 people are skipped
 *     O  O
 *   O     O 
 *  O   X   0
 *  0      0
 *    O  O 
 */




#define N 14
#define k 2



void josephus(node** circle, int start) {

  if(*circle == (*circle)->next){
    return;
  }

  if(start % k == 0) {
    // print here to see order which people die
    pop(circle);
  } else {
    *circle = (*circle)->next;
  }

  josephus(circle, start+1);  

};

int main() {

  
  infotype x;
  x.utype = INT;

  node* circle = create();

  for(int i = 0; i<N; i++){
    x.info.intInfo = i+1;
    insert(&circle, x);
  }

  printf("before:\n");
  print_list(&circle->next, &circle);
  printf("\nafter:\n");

  josephus(&circle, 1);
  print_list(&circle->next, &circle);
  printf("\n");
};




