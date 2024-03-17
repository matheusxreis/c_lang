#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"prefix_to_postfix.h"
#include<stdlib.h>






int main(){
      char* a = malloc(100);
      char* r = malloc(100);
      
        
      while(fgets(a, 100, stdin)){
          a[strcspn(a, "\r\n")] = '\0';
          convert(a, r);
          printf("result from prefix: %s, postfix: %s \n",a, r);
      }
      free(a);
      free(r);
  }




void convert(char* prefix, char* postfix) {
  
  char opnd1[MAXLENGTH], opnd2[MAXLENGTH];
  char post1[MAXLENGTH], post2[MAXLENGTH];
  char op[2];
  char temp[MAXLENGTH];
  int length;
  int i, j, m, n;

 if((length = strlen(prefix))==1){
   if(isalpha(prefix[0])){
     /* prefix is only 1 letter */
     postfix[0] = prefix[0];
     postfix[1] = '\0';
     return;
   }
   printf("\n String prefix invalid 1 \n");
   exit(1);
 }
 /* more than 1 characters */
  op[0] = prefix[0];
  op[1] = '\0';

  /* finding first and second operands */
  substring(temp, prefix, 1, length-1); // getting substring
  m = find(temp);
  substring(temp, prefix, m+1, length-m-1);
  n = find(temp);

  if(is_operator(op[0]) == 0 || m == 0 || n == 0 || (m+n+1) != length){
    printf("\n String prefix invalid 2\n");
    exit(1);
  }

  substring(opnd1, prefix, 1, m);
  substring(opnd2, prefix, m+1, n);

  convert(opnd1, post1);
  convert(opnd2, post2);

  strcat(post1, post2);
  strcat(post1, op);
  
  substring(postfix, post1, 0, length);
}

int find(char* str){


  char temp[MAXLENGTH];
  int length;
  int i, j, m, n;

  if((length = strlen(str)) == 0){
    return 0;
  }
  if(isalpha(str[0]) != 0){
    /* first char is an operand, return it */
    return 1;
  }
  if(strlen(str) < 2){
    /* it is necessary at least two operand and one operator*/
    return 0;
  }
  substring(temp, str, 1, length-1);
  m = find(temp);

  if(m == 0 || strlen(str) == m){
    /* no prefix operand valid or no second operand */
    return 0;
  }
  substring(temp, str, m+1, length-m-1);
  n = find(temp);

  if(n == 0){
    // no second operand
    return 0;
  }
  return (m+n+1);
}

int is_operator(char op){

  if(op == '+' 
      || op == '-'
      || op == '/'
      || op == '*'
      || op == '^'){
    return 1;
  }
  return 0;
}


void substring(char* target, char* source, int from, int amount){
  memcpy(target, &source[from], amount);
  target[amount] = '\0';
}
