#include "algebraic_expression.h"
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int main() {

      char str[MAXSTRINGSIZE]; // malloc(MAXSTRINGSIZE);
      int length, currentPos;
    
      readstr(str, &length);
      
      currentPos = 0;

      if(expr(str, length, &currentPos) == TRUE && currentPos >= length){
        printf("%s => valid", str);
      }else {
        printf("%s => invalid", str);
      }

    return 1;
}

char getsymb(char* str, int length, int* currentPos){
  
  char c;

  if(*currentPos < length) {
    c = str[*currentPos];
  }else {
    c = ' ';
    
    (*currentPos)++;
  }
  return c;

}

void readstr(char* str, int* length) {

      fgets(str, MAXSTRINGSIZE, stdin);
      
      int count = 0;
      while(*str !='\0') {
        count++;
        str++;
      }
      //count;
      *length = count - 1; //removing /r
};

int expr(char* str, int length,int* currentPos){

  if(term(str, length, currentPos) == FALSE){
    return FALSE; //nao começa com um termo 
  }
  if(getsymb(str, length, currentPos) != '+'){

    (*currentPos)--;
    return TRUE; // termo isolado
  }

  return (term(str, length, currentPos)); // termo seguido de +, seguido de termo

};

int term(char* str, int length,int* currentPos){

  if(factor(str, length, currentPos) == FALSE){
    return FALSE;
  }
  
  if(getsymb(str, length, currentPos) != '*'){
    (*currentPos)--;
    return TRUE; // fator isolado
  }
  return (factor(str, length, currentPos)); // fator seguido de *, seguido de fator
}

int factor(char* str, int length, int* currentPos){
  
  int c;

  if((c = getsymb(str, length, currentPos)) != '('){
    return isalpha(c);
  }
  return (expr(str, length, currentPos) && getsymb(str, length, currentPos) == ')');
}
