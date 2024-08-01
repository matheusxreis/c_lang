

#include <stdio.h>
#include <stdlib.h>
#include"linked_list.c"


void print_list(node** list){

  if(*list == NULL) {
    return;
  }

  int type = (*list)->utype;

  if(type == INT) {
    printf(" %d ", (*list)->info.intInfo);
  }else if (type == STRING) {
    printf(" %s ", (*list)->info.strInfo);
  }else if (type == CHAR){
     printf(" %c ", (*list)->info.charInfo);
  }else {
    printf(" ( ");
    print_list(&(*list)->info.listInfo);
    printf(" ) ");
  }

  node* rest = tail(*list);
  print_list(&rest);

}

int main() {

  node* list1 = create();
  infotype x;

  x.info.intInfo = 5;
  x.utype = INT;
  push(&list1, x);

  x.info.intInfo = 16;
  push(&list1, x);
 
  x.info.intInfo = 60;
  push(&list1, x);

  x.info.intInfo = 300;
  push(&list1, x);

  // list 1 -> (300, 60, 16, 5)

  node* list2 = copy(tail(list1));
  x.info.intInfo = 13;
  node* list3 = addon(list2, x);

  //list2 -> (60, 16, 5);
 // list3 -> (13, 60, 16, 5)
  printf("List 1 ->\n");
  print_list(&list1);

  printf("\nList 2 ->\n");
  print_list(&list2);

  x.info.intInfo = 149;
  set(&list1, 3, x);

  printf("\nList 1 (dps) ->\n");
  print_list(&list1);


  printf("\nList 2 (dps) ->\n");
  print_list(&list2);


  printf("\nList 3 ->\n");
  print_list(&list3);

  x.info.intInfo = 1997;

  set(&list2, 0 ,x);

  printf("\nList 3 (dps) ->\n");
  print_list(&list3);




  // list3 -> (13, 60, 1997, 16, 5)

  printf("\n");

}
