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


