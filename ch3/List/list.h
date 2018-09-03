#ifndef _LIST_H
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef int ElementType;

int IsEmpty(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Delete(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
#endif

struct Node
{
    ElementType Element;
    Position Next;
};