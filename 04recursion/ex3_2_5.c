#include<stdio.h>


/* (2)    (3)        (4)
 * 00 --> 000 ----> 0000
 *   `--> 001   `-> 0001
 *          `------------> 0010
 *       
 * 01 --> 010 -----> 0100
 *           `-----> 0101
 * 10 --> 100 -----> 1000
 *         `-------> 1001
 *
 *  - --> 101 ------> 1010
 *
 * suposse bi -> 3
 * string ending with 0 generate double strings for bi, and ending with 1 generate the same number
 * bi = (2 * num strings ending with 0 in bi-1) + (num string ending with 1 in bi-1)
 *
 * == strings ending with 0 in b-1 = same that b-2
 * == for that, strings ending with 1 in b-1 -> b-1  b-2
 *
 * for that, is equal:
 * 
 * bi = (2 * num strings ending with 0 in bi-2) + ( (bi-1) - (bi-2) )
 *
 *
 * https://math.stackexchange.com/questions/2515784/proving-the-number-of-n-length-binary-strings-with-no-consecutive-1s-b-n
 */
int calc(n){
 
  if(n==0) {
    return 0;
  }
  if(n<=2){
    /*
     * calc(1) 0 or 1
     * calc(2) => 00 or 01 or 10
     */
    return n+1;   
  };
  
  /*
  * bi = 3
  * (2*(bi(1) -> 2) -> 4) + ((bi(2) -> 3 + bi(1) -> 2)->1) = 5
  * or
  * bi(2) -> 3 + bi(1) -> 2
  */
   //return (2*calc(n-2)) + (calc(n-1) - (calc(n-2)));
  //
  return calc(n-1)+calc(n-2);
}

int main() {
  printf("calc 1 => %d\n", calc(1));
  printf("calc 2 => %d\n", calc(2));
  printf("calc 3 => %d\n", calc(3));
  printf("calc 4 => %d\n", calc(4));
  printf("calc 5 => %d\n", calc(5));
  printf("calc 6 => %d\n", calc(6));
  printf("calc 7 => %d\n", calc(7));
  printf("calc 8 => %d\n", calc(8));
  printf("calc 9 => %d\n", calc(9));
  printf("calc 10 => %d\n", calc(10));
}
