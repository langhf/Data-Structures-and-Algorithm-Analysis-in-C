#include "HashQuad.h"
#include <stdio.h>
#include <stdlib.h>

int Hash(ElementType Key, int TabelSize);

HashTable InitTable(int TabelSize){
    if(TabelSize < MinTableSize)
        return NULL;
    
    HashTable H;
    H = malloc(sizeof(struct HashTbl));
    if(H == NULL)
        return NULL;
    H->TableSize = TabelSize;
    H->TheCells = malloc(sizeof(struct HashEntry)*H->TableSize);
    if(H->TheCells == NULL)
        return NULL;

    for(int i=0; i<H->TableSize; i++){
        H->TheCells[i].Info = Empty;
    }

    return H;
}

Position Find(ElementType Key, HashTable H){
    Position CurrentPos;
    int CollisionNum;

    CollisionNum = 0;
    CurrentPos = Hash(Key, H->TableSize);
    while(H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key){
        CurrentPos += 2 * ++CollisionNum -1;
        if(CurrentPos >=H->TableSize)
            CurrentPos -= H->TableSize;
    }
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H){
    Position P;
    P = Find(Key,H);
    if(H->TheCells[P].Info != Legitimate){  /* 存在则不删除 */
        H->TheCells[P].Info = Legitimate;
        H->TheCells[P].Element = Key;
    }
}

HashTable Rehash(HashTable H){
    int OldSize;
    Cell *OldCells;

    OldCells = H->TheCells;
    OldSize = H->TableSize;

    H = InitTable(2*OldSize);

    for(int i=0; i<OldSize; i++){
        if(OldCells[i].Info == Legitimate){
            Insert(OldCells[i].Element, H);
        }
    }
    free(OldCells);
    return H;
}