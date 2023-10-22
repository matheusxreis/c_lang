// 1.1.5
// the same is easily applicable with strings

#include<stdio.h>
#include<assert.h>

int mpow(int base, int exp);
int read_binary(int binary[], int size);
int convert_to_binary(int number, int binary[32]);

int add_binary(int b1[], int b2[], int size1, int size2, int result[]);
int sub_binary(int b1[], int b2[], int size1, int size2, int result[]);
int mult_binary(int b1[], int b2[], int size1, int size2, int result[]);

int main() {

  int binary1[] = {1, 0, 1, 0}; //10
  int binary2[] = {1, 0, 0, 0, 0}; //16
  int binary4[] = {0, 1, 0, 1}; //5
  int binary5[] = {1, 0, 1, 1}; //11
  int binary4_copy[] = {0, 1, 0, 1}; //5
  int binary6[] = {0, 0, 0, 0, 0, 0}; //0;



  int size1 = sizeof(binary1)/sizeof(binary1[0]);
  int size2 = sizeof(binary2)/sizeof(binary2[0]);
  int size4 = sizeof(binary4)/sizeof(binary4[0]);
  int size5 = sizeof(binary5)/sizeof(binary5[0]);
  int size6 = sizeof(binary6)/sizeof(binary6[0]);

  // mpow
  assert(mpow(2, 3) == 8);
  assert(mpow(2, 8) == 256);
  assert(mpow(2, 0) == 1);
  assert(mpow(2, 1) == 2);

  // read_binary
  assert(read_binary(binary1, size1) == 10);
  assert(read_binary(binary2, size2) == 16);
  assert(read_binary(binary4, size4) == 5);
  assert(read_binary(binary5, size5) == 11);
  assert(read_binary(binary6, size6) == 0);

  
  int binary_test[32] = {};
  
  // add_binary
  assert(add_binary(
         binary1,
         binary2,
         size1,
         size2,
         binary_test
        ) == 26);
  
  assert(add_binary( 
        binary4,
        binary1,
        size4,
        size1, 
        binary_test
        ) == 15);

  assert(add_binary( 
        binary4,
        binary2,
        size4,
        size2, 
        binary_test
        ) == 21);

  assert(add_binary(
        binary4,
        binary4_copy,
        size4, 
        size4, 
        binary_test
        ) == 10);

  // sub_binary  
  assert(sub_binary(
         binary2,
         binary1,
         size2,
         size1,
         binary_test
        ) == 6);
  
  assert(sub_binary( 
        binary2,
        binary4,
        size2,
        size4, 
        binary_test
        ) == read_binary(binary5, size5));

  assert(sub_binary(
        binary4,
        binary4_copy,
        size4, 
        size4, 
        binary_test
        ) == 0);


  // mult_binary
  
 assert(mult_binary(
         binary2,
         binary1,
         size2,
         size1,
         binary_test
        ) == 160);
  
  assert(mult_binary( 
        binary2,
        binary4,
        size2,
        size4, 
        binary_test
        ) == 80);

  assert(mult_binary(
        binary4,
        binary4_copy,
        size4, 
        size4, 
        binary_test
        ) == 25);

  // case of negative result  

  assert(sub_binary(
        binary1,
        binary2, 
        size1, 
        size2, 
        binary_test
        ) == 0);

  return 0;
};


int mult_binary(
    int b1[], 
    int b2[], 
    int size1, 
    int size2,
    int b3[]
    ) {

  int number1 = read_binary(b1, size1);
  int number2 = read_binary(b2, size2);

  int result = number1 * number2;
  
  if(convert_to_binary(result, b3) == 0) { return 0; }


  return result;
}

int sub_binary(
    int b1[], 
    int b2[], 
    int size1, 
    int size2,
    int b3[]
    ) {

  int number1 = read_binary(b1, size1);
  int number2 = read_binary(b2, size2);

  int result = number1 - number2;

  if(convert_to_binary(result, b3)==0) { return 0;} 
  
  return result;
}

int add_binary(
    int b1[], 
    int b2[], 
    int size1, 
    int size2,
    int b3[]
    ) {

  int number1 = read_binary(b1, size1);
  int number2 = read_binary(b2, size2);

  int result = number1 + number2;
  
  if(convert_to_binary(result, b3) == 0) { return 0; };

  return result;
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
}

int mpow(int base, int exp) {
  
  int value = 1;
  
  for(int i = 1; i<=exp; i++) {
    value = value*base;
  }

  return value;
};

