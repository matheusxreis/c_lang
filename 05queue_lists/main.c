

#include <stdio.h>
#include <stdlib.h>
#include"linked_list.c"


void print_list(node** list){

  if(*list == NULL) {
    return;
  }

  int type = (*list)->utype;

  if(type == INT) {
    printf("list => %d\n", (*list)->info.intInfo);
  }else if (type == STRING) {
    printf("list => %s\n", (*list)->info.strInfo);
  }else if (type == CHAR){
     printf("list => %c\n", (*list)->info.charInfo);
  }else {
    printf("(\n");
    print_list(&(*list)->info.listInfo);
    printf(")\n");
  }

  node* rest = tail(*list);
  print_list(&rest);

}

int main() {

  node* list = create();


  infotype x;
  x.info.intInfo = 5;
  x.utype = INT;

  push(&list, x);
  x.info.intInfo = 10;
  push(&list, x);

  x.info.intInfo = 333;
  push(&list, x);
  printf("type => %d\n",nodetype(first(list))); // 1 INT
 
  print_list(&list); // 333 10 5

  infotype result;
  head(list, &result); // 333
  info(*tail((tail(list))), &result); //5
                                      
  printf("x -> %d\n", result.info.intInfo);
  result.info.intInfo = next(first(list)).info.intInfo; //10
  printf("x -> %d\n", result.info.intInfo);
  result.info.intInfo = first(list).info.intInfo;
  printf("x -> %d\n", result.info.intInfo); //333
  printf("x -> %d\n", next(first(tail(list))).info.intInfo); //5

  x.info.strInfo = "Matheus Reis";
  x.utype = STRING;
  push(&list, x);


  x.info.strInfo = "Emilye Motta";
  x.utype = STRING;
  push(&list, x);

  x.info.charInfo = 'D';
  x.utype = CHAR;
  push(&list, x);

  x.info.strInfo = "WOW";
  x.utype = STRING;
  push(&list, x);

  print_list(&list); // "WOW" 'D' "Emilye Motta" "Matheus Reis" 333 10 5//
                  
  printf("type => %d\n",nodetype(first(list))); // 4 STRING
  printf("type => %d\n",nodetype(first(tail(list)))); // 2 CHAR

  node* list2 = create();
  node* list3 = create();


  printf("\n\n=====================================\n\n");
  x.utype = STRING;
  x.info.strInfo = "INSIDE LIST 2";
  push(&list2, x);

  x.info.strInfo = "LIST 3 NOW";
  push(&list3, x);

  x.utype = INT;
  x.info.intInfo = 222;
  push(&list2, x);

  x.utype = LIST;


  x.info.listInfo = list3;
  push(&list2, x);

  x.info.listInfo = list2;

  push(&list, x);
  print_list(&list);



}
