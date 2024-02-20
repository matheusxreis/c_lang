#include<stdio.h>

int max_element(int* arr, int size);
int min_element(int* arr, int size);
int sum(int* arr, int size);
int product(int* arr, int size);
int average(int* arr, int size, int i);


int main() {

  int arr[] = { 6, 18, 99,2, 76,1, 87, 309, 23, 14, 88, 14};
  int arr2[] = {32, 1, 6, 9, 9, 88};
  // int r =  max_element(arr, sizeof(arr)/sizeof(arr[0]));
  // int r = min_element(arr, sizeof(arr)/sizeof(arr[0]));
  // int r = sum(arr, sizeof(arr)/sizeof(arr[0]));
  // int r = product(arr2, sizeof(arr2)/sizeof(arr2[0]));
    int r = average(arr2, sizeof(arr2)/sizeof(arr2[0]), 0);
  
  printf("result => %d\n",r);

  return 0;
}

int max_element(int* arr, int size){ 
  if(size == 1){
    return arr[0];
  }
  if(arr[0]>arr[1]) {
    arr[1] = arr[0];
  }
  return max_element(++arr, size-1);
}

int min_element(int* arr, int size){
  if(size == 1){
    return arr[0];
  }
  if(arr[0]<arr[1]) {
    arr[1] = arr[0];
  }
  return min_element(++arr, size-1);
}

int sum(int *arr, int size) {
  if(size == 1) {
    return arr[0];
  }
  arr[1] += arr[0];
  return sum(++arr, size-1);
}

int product(int *arr, int size) {
  if(size == 1) {
    return arr[0];
  }
  arr[1] *= arr[0];
  return product(++arr, size-1);
}

int average(int *arr, int size, int i) {
  if(size == 1) {
    return arr[i];
  }
  if(i==0) {
    return (arr[i] + average(arr, size-1, i+1))/size;
  }
  return arr[i] + average(arr, size-1, i+1);
}
