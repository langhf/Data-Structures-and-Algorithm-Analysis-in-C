#include "BinQueue.h"
#include <stdio.h>
#include <stdlib.h>

#define Capacity (20)

BinTree CombineTrees(BinTree T1, BinTree T2){
    if(T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
}

BinQueue Merge(BinQueue H1, BinQueue H2){
    BinTree T1, T2, Carry = NULL;
    int i, j;
    if(H1->CurrentSize + H2->CurrentSize > Capacity)
        return NULL;

    H1->CurrentSize += H2->CurrentSize;
    for(i=0,j=0; j<= H1->CurrentSize;i++, j*=2){
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        switch(!!T1 + 2*!!T2 + 4 * !!Carry){
            case 0: /* No Trees */
            case 1: /* Only H1 */
            case 2: /* Only H2 */
                H1->TheTrees[i] = T2;
                H2->TheTrees[i] = NULL;
                break;
            case 4: /* Only Carry */
                H1->TheTrees[i] = Carry;
                Carry = NULL;
                break;
            case 3: /* H1 and H2 */
                Carry = CombineTrees(T1, T2);
                H1->TheTrees[i] = H2->TheTrees[i] = NULL;
                break;
            case 5: /* H1 and Carry */
                Carry = CombineTrees(T1, Carry);
                H1->TheTrees[i] = NULL;
                break;
            case 6: /* H2 and Carry */
                Carry = CombineTrees(T2, Carry);
                H2->TheTrees[i] = NULL;
                break;
            case 7: /* H1, H2 and Carry */
                H1->TheTrees[i] = Carry;
                Carry = CombineTrees(T1, T2);
                H2->TheTrees[i] = NULL;
                break;
        }
    }
    return H1;
}


ElementType DeleteMin(BinQueue H){
    int i, j;
    int MinTree;
    BinQueue DeletedQueue;
    Position DeletedTree, OldRoot;
    ElementType MinItem;

    if(IsEmpty(H)){
        return 1;
    }

    
}