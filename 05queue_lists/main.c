

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
}else if(type == LIST) {
    printf(" ( ");
    print_list(&(*list)->info.listInfo);
    printf(" ) ");
  }

  node* rest = tail(*list);
  print_list(&rest);

}

int main() {

  node* list1 = create();
  infotype x, y, z, m;

  x.info.intInfo = 5;
  x.utype = INT;

  y.info.strInfo = "By Matheus Reis";
  y.utype = STRING;

  z.info.listInfo = create();
  z.utype = LIST;

  m.info.charInfo = 'O';
  m.utype = CHAR;

  node* list2 = createlist(4, &x, &y, &z, &m);
  print_list(&list2);
  printf("\n");

  m.info.charInfo = 'P';
  x.info.intInfo = 44;
  insert(&list1, m);
  insert(&list1, x);

  print_list(&list1);
  printf("\n");

  node* list3 = concat(list2, list1);



  print_list(&list3);
  printf("\n");

  reverse(&list3);

  print_list(&list3);
 
  printf("\n"); 
  remov(&list3, 4);
  print_list(&list3);

  printf("\n");

}

