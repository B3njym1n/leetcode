#include "rbt.h"
#include <stdio.h>

typedef enum  ColorType {
        Red, Black
} ColorType;

struct RedBlackNode {
  ElementType Element;
  RedBlackTree Left;
  RedBlackTree Right;
  ColorType Color;
};

static Position NullNode = NULL; /* Needs initialization */

/* Initialization Procedure */
RedBlackTree Initialize(void)
{
  RedBlackTree T;
  if (NullNode == NULL) {
    NullNode = malloc(sizeof ( struct RedBlackNode));
    if (NullNode == NULL)
      printf("Out of space!!!");
    NullNode->Left = NullNode->Right = NullNode;
    NullNode->Color = Black;
    NullNode->Element = 12345;
  }

  /* Create the header node */
  T = malloc(sizeof (struct RedBlackNode));
  if (T == NULL)
    printf("Out of space!!!");
  T->Element = NegInfinity;
  T->Left = T->Right = NullNode;
  T->Color = Black;

  return T;
}

/* END */

void Output(ElementType Element)
{
  printf("%d\n", Element);
}

/* Print the tree, watch out for NullNode */
/* and skip header */
static void DoPrint(RedBlackTree T) {
  if (T != NullNode) {
    DoPrint(T->Left);
    Output(T->Element);
    DoPrint(T->Right);
  }
}

void PrintTree(RedBlackTree T)
{
  DoPrint(T->Right);
}

Position Find(ElementType X, RedBlackTree T)
{
  if (T == NullNode)
    return NullNode;

  if (X < T->Element)
    return Find(X, T->Left);
  else if (X > T->Element)
    return Find(X, T->Right);
  else return T;
}

Position FindMin(RedBlackTree T)
{
  if (T == NullNode)
    return NullNode;
  while (T->Left != NullNode)
    T = T->Left;
  return T;
}

Position FindMax(RedBlackTree T)
{
  if (T == NullNode)
    return NullNode;
  while (T->Right != NullNode)
    T = T->Right;
  return T;
}

/* free memory */
static RedBlackTree MakeEmptyRec(RedBlackTree T) {
  if (T != NullNode)
    {
      MakeEmptyRec(T->Left);
      MakeEmptyRec(T->Right);
      free(T);
    }
  return NullNode;
}

RedBlackTree MakeEmpty(RedBlackTree T) {
  T->Right = MakeEmptyRec(T->Right);
  return T;
}

ElementType Retrieve(Position P) {
  return P->Element;
}

static Position X, P, GP, GGP;

/* This function can be called only if K1 has a right child */
/* Perform a rotate between a node (K1) and its right child */
/*   update heights, then turn new root */
static Position SingleRotateWithRight(Position K1) {
  Position K2;
  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left = K1;

  return K2; /* New root */
}

/* This function can be called only if K2 has a left child */
/* Perform a rotate between a noke (K2) and its left child */
/*   update heights, then return new root */
static Position SingleRotateWithLeft(Position K2) {
  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  return K1; /* New root */
}

/* Perform a rotation at node X */
/* (whose parent is passed as a parameter) */
/* The child is deduced by examining Item */
static Position Rotate(ElementType Item, Position Parent) {
  if (Item < Parent->Element)
    return Parent->Left = Item < Parent->Left->Element ?
      SingleRotateWithLeft(Parent->Left) : SingleRotateWithRight(Parent->Left);
  else
    return Parent->Right = Item < Parent->Right->Element ?
      SingleRotateWithLeft(Parent->Right) : SingleRotateWithRight(Parent->Right);
}

static void HandleReorient(ElementType Item, RedBlackTree T) {
  X->Color = Red; /* Do the Color flip */
  X->Left->Color =  Black;
  X->Right->Color =  Black;

  if (P->Color == Red) /* Have to rotate */ {
    GP->Color = Red;
    if ((Item < GP->Element) != (Item < P->Element))
      P = Rotate(Item, GP); /* Start double rotate */
    X = Rotate(Item, GGP);
    X->Color = Black;
  }
  T->Right->Color = Black; /* Mark root Black */
}

RedBlackTree Insert(ElementType Item, RedBlackTree T) {
  X = P = GP = T;
  NullNode->Element = Item;
  printf("Inserting %d\n", Item);
  while ( X->Element != Item) {
    GGP = GP;
    GP = P;
    P = X;
    if (Item < X->Element)
      X = X->Left;
    else
      X = X->Right;
    if (X->Left->Color == Red && X->Right->Color == Red)
      HandleReorient(Item, T);
  }

  if (X != NullNode)
    return NullNode; /* Duplicate */

  X = malloc(sizeof (struct RedBlackNode));
  X->Element = Item;
  X->Left = X->Right = NullNode;

  if (Item < P->Element)
    P->Left = X;
  else
    P->Right = X;
  HandleReorient(Item, T); /* Color it red; maybe rotate */

  return T;
}

RedBlackTree
Remove(ElementType Item, RedBlackTree T) {
  printf("Remove is unimplemented\n");
  if (Item)
    return T;
  return T;
}

void LevelTraverse(RedBlackTree T, int level) {
  if ( T == NullNode )
    return ;
  if (level == 1)
    {
      printf("%d ", T->Element);
    }
  else if (level > 1)
    {
      LevelTraverse(T->Left, level - 1);
      LevelTraverse(T->Right, level - 1);
    }
}

void preorderTraverse(RedBlackTree T) {
  if (T == NullNode )
    return ;
  preorderTraverse(T->Left);
  printf("%d ", T->Element);
  preorderTraverse(T->Right);
}
