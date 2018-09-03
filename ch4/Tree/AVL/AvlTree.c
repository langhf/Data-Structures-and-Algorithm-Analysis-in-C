#include <stdio.h>
#include <stdlib.h>
#include "AvlTree.h"

static int Height(Position P){
    if( P == NULL )
        return -1;

    return P->Height;
}

static Position SingleRotateWithLeft(Position K2){
    Position K1;
    K2->Left = K1->Right;
    K1->Right = K2;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

    return K1;
}

static Position SingleRotateWithRight(Position K2){
    Position K1;
    K1->Right = K2->Left;
    K2->Left = K1;
    K1->Height = Max(Height(K1->Left), Height(K1->Right)) + 1;
    K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;

    return K1;
}

static Position DoubleRotateWithLeft(Position K3){
    K3 = SingleRotateWithRight(K3->Left);
    K3 = SingleRotateWithLeft(K3);
    return K3;
}

static Position DoubleRotateWithRight(Position K3){
    K3 = SingleRotateWithLeft(K3->Right);
    K3 = SingleRotateWithRight(K3);
    return K3;
}

int Max(int left, int right){
    return left > right ? left : right;
}

AvlTree Insert(ElementType X, AvlTree T){
    if(T == NULL){
        T = malloc(sizeof(struct AvlNode));
        if(T == NULL)
            return NULL;
        T->Element = X;
        T->Height = 0;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Element){
        T->Left = Insert(X, T->Left);
        if( Height(T->Left) - Height(T->Right) == 2){
            if(X < T->Left->Element)
                T = SingleRotateWithLeft(T);
            else  
                T = DoubleRotateWithLeft(T);
        }
    }
    else if(X > T->Element){
        T->Right = Insert(X, T->Right);
        if(Height(T->Right) - Height(T->Left) == 2){
            if(X > T->Right->Element)
                T = SingleRotateWithRight(T);
            else
                T = DoubleRotateWithRight(T);
        }
    }

    T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
    return T;
    
}

