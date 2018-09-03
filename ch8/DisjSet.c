#include "DisjSet.h"

void Init(DisjSet S)
{
    int i;
    for(i=NumSets; i>0; i--)
        S[i] = 0;
}

/* Assumes Root1 and Root2 are roots */
/* union is a C keyword, so this routine is named SetUnion */
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root2] = Root1;
}

SetType Find(ElementType X, DisjSet S)
{
    if(S[X] <= 0)
        return 0;
    else
        return Find(S[X], S);
}

/* Assume Root1 and Root2 are roots */
/* union is a C keyword, so this routine is named SetUnion */
/* 根据树的高度来合并 */
void SetUnionh(DisjSet S, SetType Root1, SetType Root2)
{
    if(S[Root2] < S[Root1]) /* Root2 更深 */
        S[Root1] = Root2;
    else
    {
        if(S[Root1] = S[Root2])
            S[Root1]--;
        S[Root2] = Root1;
    }
}

/* 使用路径压缩的 Find 函数 */
SetType Find2(ElementType X, DisjSet S)
{
    if(S[X] <= 0)
        return X;
    else    
        return S[X] = Find(S[X], S);
}