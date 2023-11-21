
#include <stdio.h>
#include <stdlib.h>


struct realtype {
  int left;
  int right;
};

struct realtype create(int left, int right){
  struct realtype real;
  real.left = left;
  real.right = right;
  return real;
};

void show(struct realtype *real){
  printf("%d.%d\n", real->left, real->right);
};

int mpow(int base, int exp) {
  
  int value = 1;
  
  for(int i = 1; i<=exp; i++) {
    value = value*base;
  }

  return value;
};

int concat(
  struct realtype* r1 
    ){    
    unsigned pow = 10;
    while(r1->right >= pow) {
      pow*=10;
    };
    return r1->left * pow + r1->right;
    
};
int length(int number) {
  int value = number;
  int l = 1;
  while(value>9) {
    value/=10;
    l++;
  }
  return l;
};

void format(
    struct realtype* real,
    int left,
    int right
    ){

    if(right< 0) {   
      real->right = right*(-1);
    }else {
      real->right = right;
    };

    if(left==0 && (right>0||(right*-1)>0)) {
      real->left = -left;
    }else {
     real->left = left;
    }
};

void multiply(
    struct realtype* r1,
    struct realtype* r2,
    struct realtype* r3
    ){

    int number1 = concat(r1); //without points
    int number2 = concat(r2); //without points

    unsigned decimal_place = length(r1->right) + length(r2->right); // amount decimal places

    int result = (number1 * number2);
    
    r3->left = result/(mpow(10,decimal_place));
    r3->right = result%(mpow(10, decimal_place));
    };

void subtract(
    struct realtype* r1,
    struct realtype* r2,
    struct realtype* r3
    ){

    int number1 = concat(r1); //without points
    int number2 = concat(r2); //without points
   
    int len1 = length(r1->right);
    int len2 = length(r2->right);
    
    unsigned decimal_place;

    if(len1 == len2) {
      decimal_place = len1;
    }else if(len1>len2) {
      decimal_place = len1;
      number2 *= mpow(10, len1-len2);
    }else {
      decimal_place = len2;
        number1 *= mpow(10, len2-len1);
    };
    
    int result = (number1 - number2);

    int left = result/mpow(10, decimal_place); 
    int right = result%mpow(10, decimal_place); 

    format(r3, left, right);
     
};


void add(
    struct realtype* r1,
    struct realtype* r2,
    struct realtype* r3
    ){

    int number1 = concat(r1); //without points
    int number2 = concat(r2); //without points
   
    int len1 = length(r1->right);
    int len2 = length(r2->right);
    
    unsigned decimal_place;

    if(len1 == len2) {
      decimal_place = len1;
    }else if(len1>len2) {
      decimal_place = len1;
      number2 *= mpow(10, len1-len2);
    }else {
      decimal_place = len2;
        number1 *= mpow(10, len2-len1);
    };
    
    int result = (number1 + number2);

    int left = result/mpow(10, decimal_place); 
    int right = result%mpow(10, decimal_place);  
  
    format(r3, left, right);
};

int main() {

  while(1) {

    int n1, n2, n3, n4;
    printf("\nChoose the first decimal number.\n(7.xxx)\n");
    scanf("%d", &n1);
    printf("\nNow, choose the decimal place from %d.xxx:\n", n1);
    scanf("%d", &n2);

    printf("\nNow, the same for the second number:\n");
    scanf("%d", &n3);
    printf("\nDecimal place:\n");
    scanf("%d", &n4);


    struct realtype real1 = create(n1, n2);
    struct realtype real2 = create(n3, n4);
    struct realtype result;
    multiply(&real1, &real2, &result);
    printf("\n=====result=====\n");
    printf("%d.%d * %d.%d is => %d.%d\n", n1, n2, n3, n4, result.left, result.right);
    add(&real1, &real2, &result);
    printf("%d.%d + %d.%d is => %d.%d\n", n1, n2, n3, n4, result.left, result.right); 
    subtract(&real1, &real2, &result);
    printf("%d.%d - %d.%d is => %d.%d\n", n1, n2, n3, n4, result.left, result.right);
    scanf("%d");
    system("clear"); 
  }

  return 1;
}
