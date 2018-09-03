typedef struct BinNode *Position;
typedef struct Collection *BinQueue;
typedef struct BinNode *BinTree;

typedef int ElementType;
#define MaxTrees (10)

struct BinNode{
    ElementType Element;
    Position LeftChild;
    Position NextSibling;    
};

struct Collection{
    int CurrentSize;
    BinTree TheTrees[MaxTrees];
};