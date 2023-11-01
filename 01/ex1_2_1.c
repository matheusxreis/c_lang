// mediana
#include<stdio.h>
#include<assert.h>


int mediana(int arr[], int size);
int moda(int arr[], int size);

int main() {


  int odd[] = {2, 2, 3, 7, 8, 9, 10};
  int even[] = {1, 4, 4, 5, 6, 7, 7, 7};
  
  int list[] = {0, 1, 2, 3, 4, 12, 16, 19, 22, 27};
  int list2[] = {9, 12, 37, 1, 2, 8, 10, 12, 9};

  int length = sizeof(odd)/sizeof(odd[0]);
  int result = mediana(odd, length);

  int mod = moda(odd, sizeof(odd)/sizeof(odd[0]));
  int mod2 = moda(even, sizeof(even)/sizeof(even[0]));
  int mod3 = moda(list, sizeof(list)/sizeof(list[0]));
  int mediana2 = mediana(list, sizeof(list)/sizeof(list[0]));

  assert(result == 7);
  assert(mediana(even, sizeof(even)/sizeof(even[0])) == 5);
  assert(mod == 2);
  assert(mod3 == -1);
  assert(mediana2 == 8);
  assert(mod2 == 7);
  assert(mediana(list2, sizeof(list2)/sizeof(list2[0])) == 2);
  assert(moda(list2, sizeof(list2)/sizeof(list2[0])) == -1);
  
  return 1;
}



int mediana(int arr[], int size) {


  if (size%2!=0) {
    
    return arr[size/2];

  } else {
    int m1 = arr[size/2];
    int m2 = arr[(size/2)- 1];
    return (m1 + m2)/2;
  };

  return 0;

}

int moda(int arr[], int size) {

  int max = 0;

  for(int i = 0; i<size-1; i++) {
    if(arr[i]>max){
      max = arr[i];
    };
  };

  int countArray[max+1];

  for(int i = 0; i<=max+1; countArray[i++] = 0);
  for(int i = 0; i<=size-1; countArray[arr[i++]]+= 1);

  int j = -1;
  int bigger = countArray[0];

  for(int i = 0; i<max+1;i++){
    if(countArray[i] == bigger) {
      j = -1;
      continue;
    }
    if(countArray[i] > bigger){
     bigger = countArray[i];
     j = i;
    }
  }

  return j;
}
