#include "list.h"
#include <stdio.h>
#include <malloc.h>

int IsEmpty(List L){
    return L->Next == NULL;
}

int IsLast(Position P, List L){
    return P->Next == NULL;
}

Position Find(ElementType X, List L){
    Position p;
    p = L->Next;
    while(p != NULL && p->Element != X){
        p = p->Next;
    }
    return p;
}

Position FindPrevious(ElementType X, List L){
    Position P;
    P = L;
    while(P->Next != NULL && P->Next->Element != X){
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L){
    Position P, TmpCell;
    P = FindPrevious(X,L);
    if(!IsLast(P,L)){
        TmpCell = P->Next;
        P->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void Insert(ElementType X, List L, Position P){
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell == NULL){
        printf("Out of space \n");
    }
    TmpCell->Element = X;
    TmpCell->Next = P->Next;
    P->Next = TmpCell;
}
int main(char* args){
    printf("hello\n");
   
    return 0;
}