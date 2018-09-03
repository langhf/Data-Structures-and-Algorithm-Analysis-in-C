#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

int IsEmpty(Stack S){
    return S->Next == NULL;
}

void Pop(Stack S){
    PtrToNode FirstCell;
    if(IsEmpty(S)){
        printf("Empty Stack \n");
    }
    else{
        FirstCell = S->Next;
        S->Next = S->Next->Next;
        free(FirstCell);
    }
}

ElementType Top(Stack S){
    if(!IsEmpty(S)){
        return S->Next->Element;
    }
    printf("Empty Stack \n");
    return 0;
}

void MakeEmpty(Stack S){
    if(S==NULL){
        printf("Must use CreateStack fitst\n");
    }
    else{
        while(!IsEmpty(S)){
            Pop(S);
        }
    }
}

Stack CreateStack(void){
    Stack S;
    S = malloc(sizeof(struct Node));
    if(S==NULL)
        printf("Out of space \n");
    S->Next = NULL;
    MakeEmpty(S);
    return S;
}

void Push(ElementType X, Stack S){
    PtrToNode TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if(TmpCell==NULL)
        printf("Out of space \n");
    else{
        TmpCell->Element = X;
        TmpCell->Next = S->Next;
        S->Next = TmpCell;
    }
}

void main(){
    
}