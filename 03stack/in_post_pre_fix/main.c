#include"eval.c"
#include<stdio.h>
#include <stdlib.h>
#include <string.h>


int main(){

      char* a = malloc(100);
      char* r = malloc(100);

      while(fgets(a, 100, stdin)){
          
          a[strcspn(a, "\r\n")] = '\0';
          postfix(a, r);

          int result = eval(r);
          printf("result from infix: %s, postfix: %s => %d\n",a, r, result);
      }

      free(a);
      free(r);
      return 0;
};
