// 1.1.7

#include<stdio.h>
#include<assert.h>

int binary_to_ternary(int binary[], int size, int result[]);
int read_binary(int binary[], int size);
int read_ternary(int ternary[], int size);
int mpow(int base, int exp);
int convert_to_ternary(int number, int result[32]); 
int ternary_to_binary(int ternary[], int size, int binary[]); 
int convert_to_binary(int number, int result[32]); 

int main() {

  int binary[] = { 1, 0, 1, 1, 0 }; // 22
  int ternary[32] = {};
  int ternary2[] = { 2, 1, 1};
  int binary2[] = {}; 

  binary_to_ternary(binary, (sizeof(binary)/sizeof(binary[0])), ternary);
  ternary_to_binary(ternary2, (sizeof(ternary2)/sizeof(ternary2[0])),binary2);

  printf("\nternary\n");

  for(int i = 0; i<= 32; i++) {
    printf("%d", ternary[i]);
  };

  printf("\nbinary\n");

  for(int i = 0; i <= 32; i++) {
    printf("%d", binary2[i]);
  };

  return 1;
}


int ternary_to_binary(int ternary[], int size, int binary[]) {
  int number = read_ternary(ternary, size);
  if (number <= 0) { return 0; };
  convert_to_binary(number, binary);
  return 1;
};

int binary_to_ternary(int binary[], int size, int ternary[]){
  int number = read_binary(binary, size);
  if(number <= 0) { return 0; };
  convert_to_ternary(number, ternary);
  return 1;
};


int convert_to_ternary(int number, int result[32]) {

  if(number<=0) {return 0;}

  int n = number;
  int i = 32;
  
  while(n>0) {
   result[i] = n%3;
    n = n/3;
    i--;
  }
  while(i>=0) {
    result[i] = 0;
    i--;
  }
  return 1;
}


int convert_to_binary(int number, int result[32]) {

  if(number<=0) {return 0;}

  int n = number;
  int i = 32;

  
  while(n>0) {

   if(n%2!=0){    
      
     result[i] = 1;
    
    }else {
    
      result[i] = 0;
    
    }
   n = n/2;
   i--;
  }

  while(i>=0) {
      
    result[i] = 0;
    i--;
  }

  return 1;
}

int read_binary(int binary[], int size){
  int sum = 0; //soma
  int exp = 0; //expoente

  for(int i = size-1; i >= 0; i--) {
    if(binary[i] == 1 ){
      sum += mpow(2, exp);
    }
    exp++;
  };

  return sum;
};

int read_ternary(int ternary[], int size) {

  int sum = 0;
  int exp = 0;

  for(int i = size-1; i>=0; i--) {
   if(ternary[i]!=0){
     printf("olha o num %d", sum);
     sum += (mpow(3, exp)) * ternary[i];
   }
   exp++;
  };

  return sum;
};

int mpow(int base, int exp) {
  
  int value = 1;
  
  for(int i = 1; i<=exp; i++) {
    value = value*base;
  }

  return value;
};


