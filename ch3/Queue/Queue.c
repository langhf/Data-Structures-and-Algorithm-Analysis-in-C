#include "Queue.h"

int IsEmpty(Queue Q){
    return Q->Size == 0;
}

void MakeEmpty(Queue Q){
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

