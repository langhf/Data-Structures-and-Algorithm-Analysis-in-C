#ifndef _TREE_H

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position FindMin(ElementType X, SearchTree T);
Position FindMax(ElementType X, SearchTree T);
SearchTree Insert(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);  // 取回

#endif

/* Place in the implementation file */
struct TreeNode{
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};