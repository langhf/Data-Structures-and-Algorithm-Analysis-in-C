#ifndef _DISJSET_H

#define NumSets (10)

typedef int DisjSet[NumSets + 1];
typedef int SetType;
typedef int ElementType;

void Init(DisjSet S);
void SetUnion(DisjSet S, SetType Root1, SetType Root2);
SetType Find(ElementType X, DisjSet S);

#endif