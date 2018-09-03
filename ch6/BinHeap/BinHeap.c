#include "BinHeap.h"
#include <stdlib.h>

#define MinPQSize   (100)
PriorityQueue Initialize(int MaxElements){
    if(MaxElements < MinPQSize)
        return NULL;

    PriorityQueue H;
    H = malloc(sizeof(struct HeapStruct));
    if(H == NULL)
        return NULL;

    H->Elements = malloc(sizeof(ElementType)*MaxElements+1);
    if(H->Elements == NULL){
        free(H);
        return NULL;
    } 

    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = MinData;
    return H;
}

int IsFull(PriorityQueue H){
    if(H->Capacity == H->Size)
        return 1;
    
    return 0;
}

void Insert(ElementType X, PriorityQueue H){
    if(IsFull(H))
        return ;
    int i;
    for(i=++H->Size; H->Elements[i/2] > X; i /= 2)
        H->Elements[i] = H->Elements[i/2];
    H->Elements[i] = X;

}

int IsEmpty(PriorityQueue H){
    if(H->Elements[1] != 0)
        return 0;
    
    return 1;
}
ElementType DeleteMin(PriorityQueue H){
    ElementType MinElement, LastElememt;
    int child, i;

    if(IsEmpty(H))
        return H->Elements[0];

    MinElement = H->Elements[1];
    LastElememt = H->Elements[H->Size--];

    for(i=1; i*2 <= H->Size; i = child){
        child = i * 2;
        if(child != H->Size && H->Elements[child+1] < H->Elements[child])
            child++;

        if(LastElememt > H->Elements[child])
            H->Elements[i] = H->Elements[child];
        else 
            break;
    }

    H->Elements[i] = LastElememt;
    return MinElement;
}