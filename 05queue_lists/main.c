

#include <stdio.h>
#include <stdlib.h>
#include"linked_list.c"

int main() {

 
  node* list = create();

  infotype x;
  x.info.intInfo = 1;
  x.utype = INT;
  insert(&list, x);

  x.info.intInfo = 1;
  insert(&list, x);
   
  x.info.intInfo = 1;
  insert(&list, x);

  x.info.intInfo = 1;
  insert(&list, x);
 
  x.info.intInfo = 50;
  insert(&list, x);

  x.info.intInfo = 1;
  insert(&list, x);

  x.info.intInfo = 50;
  insert(&list, x);

  x.info.intInfo = 1;
  insert(&list, x);  

  print_list(&list);
  printf("\n");

  infotype elem;
  elem.utype = INT;
  elem.info.intInfo = 50;

  node* list2 = filter(list, elem);

  print_list(&list2);
  printf("\n");

  set(&list2, 1, x);

  print_list(&list2);
  printf("\n");

  x.info.intInfo = 50;

  node* searched = find(list, x);

  print_list(&searched);
  printf("\n");

  x.info.intInfo = 99;

  set(&searched, 0, x);

  print_list(&searched);
  printf("\n");


}
