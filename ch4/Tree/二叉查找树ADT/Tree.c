#include "Tree.h"
#include <stdio.h>
#include <stdlib.h>

// 递归
SearchTree MakeEmpty(SearchTree T){
    if(T != NULL){
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position Find(ElementType X, SearchTree T){
    if(T == NULL)
        return NULL;
    
    if(X < T->Element){
        return Find(X, T->Left);
    }
    else if( X > T->Element){
        return Find(X, T->Right);
    }
    else
        return T;
}

// 递归
Position FindMin(SearchTree T){
    if(T == NULL)
        return NULL;

    if(T->Left == NULL)
        return NULL;

    return FindMin(T->Left);
}

// 非递归
Position FindMax(SearchTree T){
    if( T != NULL ){
        while( T->Right != NULL){
            T = T->Right;
        }
        return T;
    }

    return NULL;
}

SearchTree Insert(ElementType X, SearchTree T){
    if( T == NULL){
        T = malloc(sizeof(struct TreeNode));
        if( T == NULL )
            return NULL;
        else{
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    }
    else{
        if(X < T->Element){
            T->Left = Insert(X, T->Left);
        }
        else if( X > T->Element){
            T->Right = Insert(X, T->Right);
        }
    }

    return T;
}

SearchTree Delete(ElementType X, SearchTree T){
    Position TmpCell; // 删除单元时使用一个中间容器
    if( T == NULL)
        return NULL;

    if( X < T->Element){    // Go left
        Delete(X, T->Left);
    }
    else if( X > T->Element){   // Go right
        Delete(X, T->Right);
    }
    else if ( T->Left && T->Right){   // Two children
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = Delete(T->Element, T->Right);
    }
    else {      // One or zero children
        TmpCell = T;
        if(T->Left == NULL)
            T = T->Right;
        else if(T->Right == NULL)
            T= T->Left;
        free(TmpCell);
    } 

    return T;
}