#include<stdio.h>
#include <stdlib.h>
#include"clinked_list.h"

// =========== CIRCULAR LINKED LIST ============ //
//  --> [ 1 ] -> [ 2 ] -> [ 3 ] -> [ 4 ]
// |                                |
// ---------------------------------
//  list = last element
//  list.next = first element

void set_info(infotype* t1, infotype* t2){

  t1->utype = t2->utype;
  
  switch(t2->utype) {
    case INT:
      t1->info.intInfo =t2->info.intInfo;
      break;
    case CHAR:
      t1->info.charInfo = t2->info.charInfo;
      break;
    case LIST:
      t1->info.listInfo = t2->info.listInfo;
      break;
    case STRING:
      t1->info.strInfo = t2->info.strInfo;
      break;
  }
}

/*
 * ([2] -> [1]) and inserting [3]
 * step 1 | [3] -> [1] 
 * step 2 | [2] -> [3]
 * step 3 | list = [3]  = ([2]  -> [3]  -> [1])
 *                         penul   last   first
 * 
 * 1 -> 
 *
 *
 */
void insert(node** l, infotype x) {

  node* n = (node*)malloc(sizeof(node));  
  set_info((infotype*)n, &x);

  if(*l == NULL){
    (*l) = n;
    (*l)->next = n;
    return;
  }

  n->next = (*l)->next; // step1
  (*l)->next = n;       // step2
  (*l) = n;             // step3 
 
}


void push(node** l, infotype x) {

  node* n = (node*)malloc(sizeof(node));  
  set_info((infotype*)n, &x);

  if(*l == NULL){
    (*l) = n;
    (*l)->next = n;
    return;
  }

  n->next = (*l)->next;
  (*l)->next = n;
}

node* pop(node** l) {
  
  if(*l == NULL) {
    printf("Underflow occurs \n");
    exit(1);
  }

  if(*l == (*l)->next) {
    node* n = *l;
    (*l) = NULL;
    return n;
  }
  
  node* n = (*l)->next;
  (*l)->next = n->next;

  return n;
}

node* create() { 
  node* n = (node*)malloc(sizeof(node)); 
  n = NULL;
  return n;
}


///// ============================= print list

void print_list(node** list, node** last){

  int stop = 0;
  if(*list == *last) {
    stop = 1;
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
    print_list(&(*list)->info.listInfo, last);
    printf(" ) ");
  }

  if(stop == 1) {
    return;
  }
  node* rest = (*list)->next;
  print_list(&rest, last);

}
