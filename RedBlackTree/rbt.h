#include <stdlib.h>

#define KRED "\x1B[31m"
#define KGRN "\x1B[32m"
#define KNRM "\x1B[0m"
typedef int ElementType;
#define NegInfinity (-10000)

#ifndef _RedBlack_H
#define _RedBlack_H

struct RedBlackNode;
typedef struct RedBlackNode* RedBlackTree;
typedef struct RedBlackNode* Position;

struct trunk;

RedBlackTree MakeEmpty(RedBlackTree T);
Position Find(ElementType X, RedBlackTree T);
Position FindMin(RedBlackTree T);
Position FindMax(RedBlackTree T);
RedBlackTree Initialize(void);
RedBlackTree Insert(ElementType X, RedBlackTree T);
RedBlackTree delete(ElementType X, RedBlackTree T);
ElementType Retrieve(Position P);
void PrintTree(RedBlackTree T, struct trunk *prev, int is_left);
#endif 
