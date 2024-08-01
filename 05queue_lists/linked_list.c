#include<stdio.h>
#include"linked_list.h"



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

node* create() { 
  node* n = (node*)malloc(sizeof(node)); 
  n = NULL;
  return n;
}

/// (1, 2, null)
/// *null
/// *n = 2
/// *n.next = null
/// return (2, null)
/// *n = 1
/// *n.next = (2, null)
///  (1, 2, null)

node* copy(node* list) {

  if(list == NULL){
    return NULL; 
  }
  node* n = (node*)malloc(sizeof(node));
  *n = *list;
  n->next = copy(tail(list));
  return n;
}

void info(node element, infotype *x) {
  set_info(x, (infotype*)&element);
}

node next(node element) {
  return *element.next;
}

node first(node *list) {
  if(list == NULL){
    printf("The list is empty (first method)");
  }
  return *list;
}

void head(node *list, infotype *x) {
  
  if(list == NULL) {
    printf("The list is empty (head method)\n");
    return;
  }

  set_info(x, (infotype*)list);
}

node* tail(node* list){
  if(list == NULL) {
    printf("The list is empty (tail method)\n");
    return NULL;
  }
  return (list->next);
}

int nodetype(node element) {
  return element.utype;
}


void push(node** list, infotype x) { 
  
  node* n = (node*)malloc(sizeof(node)); 
  set_info((infotype*)n, &x);
  
  if(!n) {
    printf("ops");
  }
  n->next = *list;

  *list = n;
}
/*
 *  (10, 20, 30, 40)
 *  set(list, 4, 's')
 *   set((20, 30, 40), 3, 's');
 *    set((30, 40), 2, 's');
 *     set((40), 1, 's')
 *      
 *
 */
void set(node** list, int index, infotype info) {
   if(list == NULL) {
    printf("Index out of bounds (set)\n");
    exit(1);
  }
   if(index==0) {
    set_info((infotype*)*list, &info);
    return;
  }
  node* rest = tail(*list);
  if(rest == NULL) {
    printf("Index out of bounds (set)\n");
    exit(1);
  }
  set(&rest, index - 1,info); 
}

node* addon(node* list, infotype x) { 

  node* n = (node*)malloc(sizeof(node));
  set_info((infotype*)n, &x);
  n->next = list;
  return n;
}

