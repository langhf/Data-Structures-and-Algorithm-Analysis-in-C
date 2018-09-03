/*
分离链接散列表的类型声明
*/
#ifndef _HASHSEP_H

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef char* ElementType;

HashTable InitTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P);

#endif

struct ListNode{
    ElementType Element;
    Position Next;
};

typedef Position List;
struct HashTbl{
    int TableSize;
    List *TheLists;
};