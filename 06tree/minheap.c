

#include<stdlib.h>
#include<stdio.h>

/* I've done this while implementing Djisktra Algoritm in graphs sessions,
bcz of this the type of element is a int*,
I suppose receiving an array with 2 elements,
being the 1th the vertex number,
and 2th the distance number
[vertex, distance]
*/

#ifndef MinHeapElement
    typedef int* MinHeapElement;
#endif

typedef struct node {
    MinHeapElement* elements;
    int capacity;
    int size;
} MinHeap;


MinHeap* minheapcreate(int capacity);
void insert(MinHeap* heap, MinHeapElement item);
MinHeapElement delete(MinHeap* heap);
void heapify_up(MinHeap* heap, int index);
void heapify_down(MinHeap* heap, int index);
void swap(int** a, int** b);

void insert(MinHeap* heap, MinHeapElement item) {

    if(heap->size>=heap->capacity) {
        printf("Heap overflow\n");
        exit(0);
    }

    
    heap->elements[heap->size] = item;

    heapify_up(heap, heap->size);
    heap->size+=1;

}

void swap(int** a, int** b) {
    // int temp[2];
    
    int* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify_up(MinHeap* heap, int index) {

       while(index>0){

        int parent = (index-1)/2;

        if(heap->elements[index][1] < heap->elements[parent][1] ){
            //
            swap(&heap->elements[parent], &heap->elements[index]);
            index = parent;
            //
        }else {
            break;
        }
   

    }
};

void heapify_down(MinHeap* heap, int index) {
    
    while(1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < heap->size && heap->elements[left][1] < heap->elements[smallest][1] ) {
            smallest = left;
        }
        if(right < heap->size && heap->elements[right][1] < heap->elements[smallest][1]) {
            smallest = right;
        }

        if(smallest != index) {
            swap(&heap->elements[index], &heap->elements[smallest]);
            index = smallest;
        }else {
            break;
        }
    }


}

MinHeapElement delete(MinHeap* heap) {

    if(heap->size<1) {
        printf("\nHeap underflow\n");
        exit(0);
    }

    int* item = heap->elements[0];
    heap->elements[0] = heap->elements[heap->size-1];

    heapify_down(heap, 0);
    
    heap->size--;

    return item;
}

MinHeap* minheapcreate(int capacity) {
    MinHeap* heap = (MinHeap*)malloc(sizeof(MinHeap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->elements = (int**)malloc(capacity * sizeof(int)*2);
    return heap;
}

