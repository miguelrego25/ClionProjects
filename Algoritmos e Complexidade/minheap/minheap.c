
#include <stdlib.h>

#include "minheap.h"



void initHeap (Heap *h, int size) {
    //initHeap_sol (h, size);
    h->values = calloc(size,sizeOF)
}



void bubbleUp (Elem h[], int i) {

    while(i!=0 && a[i]  a[PARENT(I)]){
        swap(a,i,PARENT(i));
        i = PARENT(i);
    }

}

int  insertHeap (Heap *h, Elem x) {
//    return insertHeap_sol (h, x);

    if(h -> used == h -> size){
        h->values = realloc(h->values,2*(h->size)*sizeof(Elem));
        h->size *= 2;
    }
    h->values[h->used ] = x;
    (h->used)++;
    bubbleUp_sol(h->values, h->used-1)
    return 1;
}



void bubbleDown (Elem h[], int N) {
// ...
}



int  extractMin (Heap *h, Elem *x) {
    return extractMin_sol (h, x);
}



int minHeapOK (Heap h) {

    // ...

}