#ifndef _QUEUE_H

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef int ElementType;

int IsEmpty(Queue Q);
int IsFull(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmpty(Queue Q);
void EnQueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void DeQueue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif

#define MinQueueSize (5)

struct QueueRecord{
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};