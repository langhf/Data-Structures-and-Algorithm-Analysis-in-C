#include "HashSep.h"
#include <stdio.h>
#include <stdlib.h>

#define MinTableSize    (10)
#define Error(x)    fprintf(stderr,"%s \n", x)
typedef unsigned int Index;
/* Hash 函数 */
Index Hash(const char *key, int TableSize){
    unsigned int HashVal = 0;
    while(*key != '\0'){
        HashVal = (HashVal << 5) + *key++;
    }
    return HashVal % TableSize;
}

/* 初始化 Hash Table */
HashTable InitTable(int TableSize){
    HashTable H;
    int i;

    if(TableSize < MinTableSize){
        Error("Table size too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if(H == NULL){
        Error("Out of space");
        return NULL;
    }
        

    H->TableSize = TableSize;

    H->TheLists = malloc(sizeof(struct ListNode)*H->TableSize);
    if(H->TheLists == NULL){
        Error("Out of space");
        return NULL;
    }

    for(i=0; i<H->TableSize; i++){
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if(H->TheLists[i] == NULL){
            Error("Out of space");
            return NULL;
        }
        else{
            H->TheLists[i]->Next = NULL;
        }
    }

    return H;

}

Position Find(ElementType Key, HashTable H){
    Position L, P;

    L = H->TheLists[Hash(Key,H->TableSize)];
    P = L->Next;

    while(P != NULL && P->Element)
        P = P->Next;

    return P;    
}

void Insert(ElementType Key, HashTable H){
    Position NewCell, L;

    L = Find(Key, H);
    if(L == NULL){
        NewCell = malloc(sizeof(struct ListNode));
        if(NewCell == NULL)
            Error("Out of space");
            
        L = H->TheLists[Hash(Key, H->TableSize)];
        NewCell->Element = Key;
        NewCell->Next = L->Next;
        L->Next = NewCell;
    }
}
