/* 开放定址散列法 */

#ifndef _HASHQUAD_H

typedef unsigned int Index;
typedef Index Position;
typedef int ElementType;

struct HashTbl;
typedef struct HashTbl *HashTable;

#define MinTableSize    (17)

HashTable InitTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
ElementType Retrieve(Position P, HashTable H);
HashTable Rehash(HashTable H);

#endif

enum KindOfEntry { Legitimate, Empty, Deleted };

struct HashEntry{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl{
    int TableSize;
    Cell *TheCells;
};
