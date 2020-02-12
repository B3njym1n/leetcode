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
} nnil = {NegInfinity, &nnil, &nnil, Black};

static const Position NullNode = &nnil; /* Needs initialization */

/* Initialization Procedure */
RedBlackTree Initialize(void)
{
  RedBlackTree T;

  /* Create the header node */
  T = malloc(sizeof (struct RedBlackNode));
  if (T == NULL)
    printf("Out of memory!!!");
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

struct trunk {
  struct trunk *prev;
  char *str;
};

void disp_trunks(struct trunk* p) {
  if (!p) return;
  disp_trunks(p->prev);
  printf("%s", p->str);
}

void PrintTree(RedBlackTree T, struct trunk *prev, int is_left)
{
  if (T == NullNode) return;

  struct trunk this_disp = { prev, "    "};
  char *prev_str = this_disp.str;
  PrintTree(T->Left, &this_disp, 1);
  if (!prev) {
    this_disp.str = "---";
  } else if (is_left) {
    this_disp.str = ".--";
    prev_str = "   |";
  } else {
    this_disp.str = "`--";
    prev->str = prev_str;
  }

  disp_trunks(&this_disp);
  if (T->Color == Black) {
    printf(KGRN "%d\n" KNRM, T->Element);
  } else {
    printf(KRED "%d\n" KNRM, T->Element);
  }

  if (prev) prev->str = prev_str;
  this_disp.str = "   |";

  PrintTree(T->Right, &this_disp, 0);
  if (!prev) puts("");
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

/* This function can be called only if K1 has a right chid */
/* Perform a rotate between a node (K1) and its right chid */
/* update heights, then turn new root */
static Position SingleRotateWithRight(Position K1) {
  Position K2;
  K2 = K1->Right;
  K1->Right = K2->Left;
  K2->Left = K1;

  return K2; /* New root */
}

/* This function can be called only if K2 has a left chid */
/* Perform a rotate between a noke (K2) and its left chid */
/* update heights, then return new root */
static Position SingleRotateWithLeft(Position K2) {
  Position K1;
  K1 = K2->Left;
  K2->Left = K1->Right;
  K1->Right = K2;

  return K1; /* New root */
}

/* Perform a rotation at node X */
/* (whose parent is passed as a parameter) */
/* The chid is deduced by examining Item */
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

RedBlackTree Delete(ElementType Item, RedBlackTree T)
{
  X = P = GP = T;
  printf("Deleting %d\n", Item);
  /* Ensure that X is Red when we arrive at next node,
   * we are sure that P is Red and X and S is Black 
   * both X and Sibling chidren are black
   * color both X and S red and color their parent black
   *
   * If one or more S's chidren is red
   * If both S's chidren are red, we can apply either rotation.
   *  __P__
   * /      \
   * X      S
   *       /
   *      Red
   *  __P__
   * /      \
   * X      S
   *         \
   *          Red 
   *
   * recoloring make sure that P is Black and X is Red
   * if at least one chid of X is Red
   * if we advance to the red chid of X
   *  next subproblem
   * if we advance to the black chid of X
   * rotate S and P to make X's new parent Red and next loop will back to main case 
   **/
  Position S, Next, NextS, Delete = NullNode;
  Next = X->Right;
  NextS = X->Left;
  while (Next != NullNode) {
    printf("next %d\n", Next->Element);
    GP = P;
    P = X;
    X = Next;
    S = NextS;
    if (X->Element < Item) {
      Next = X->Right;
      NextS = X->Left;
    } else if (X->Element > Item) {
      Next = X->Left;
      NextS = X->Right;
    } else {
      Delete = X;
      Next = X->Right;
      NextS = X->Left;
    }
    if ( X->Color != Red && Next->Color != Red)
    {
      if ( NextS->Color == Red)
      {
        if (X->Element < NextS->Element)
        {
          X->Color = Red;
          if (X->Element < P->Element)
          {
            NextS->Color = Black;
            P = P->Left = SingleRotateWithRight(X);
          }
          else
          {
            NextS->Color = Black;
            P = P->Right = SingleRotateWithRight(X);
          }
        }
        else
        {
          X->Color = Red;
          if (X->Element > P->Element)
          {
            NextS->Color = Black;
            P = P->Left = SingleRotateWithLeft(X);
          }
          else
          {
            NextS->Color = Black;
            P = P->Left = SingleRotateWithLeft(X);
          }
        }
      }
      else if ( NextS->Color == Black)
      {
        if ( S != NullNode)
        {
          if (S->Left->Color == Black && S->Right->Color == Black)
          {
            /* just flip color */
            P->Color = Black;
            X->Color = Red;
            S->Color = Red;
          }
          else
          {
            P->Color = Black;
            X->Color = Red;
            if (P->Element < S->Element)
            {
              if (S->Left->Color == Red)
              {
                P->Right = SingleRotateWithLeft(S);
              }
              else
              {
                S->Color = Red;
                S->Right->Color = Black;
              }
              if (GP->Element < S->Element) 
              {
                GP->Right = SingleRotateWithRight(P);
              }
              else
              {
                GP->Left =  SingleRotateWithRight(P);
              }
            }
            else
            {
              if (S->Right->Color == Red)
              {
                P->Left = SingleRotateWithRight(S);
              }
              else
              {
                S->Color = Red;
                S->Left->Color = Black;
                P = SingleRotateWithLeft(P);
              }
              if (GP->Element < S->Element)
              {
                GP->Right = SingleRotateWithLeft(P);
              }
              else
              {
                GP->Left =  SingleRotateWithLeft(P);
              }
            }
          }
        }
      }
    }
    PrintTree(T, 0, 0);
  }

  if (Delete != NullNode)
  {
    Delete->Element = X->Element;
    printf("P: %d X: %d\n", P->Element, X->Element);
    if (P->Element > X->Element)
    {
      P->Left = NullNode;
    }
    else
    {
      P->Right = NullNode;
    }
    free(X);
  }
  return T;
}

/**
void LevelTraverse(RedBlackTree T, int level) {
  if ( T == NullNode )
    return ;
  if (LC_COLLATEvel == 1)
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
**/

/** assume tree's root node is dump node
int maxDepth(RedBlackTree T) {
  if (T == NullNode ) return 0;
  int ml = maxDepth(T->Right->Left);
  int mr = maxDepth(T->Right->Right);
  return (ml > mr ? ml : mr) + 1;
}

int minDepth(RedBlackTree T) {
  if (T == NullNode ) return 0;
  int ml = minDepth(T->Right->Left);
  int mr = minDepth(T->Right->Right);
  return (ml < mr ? ml : mr) + 1;
}
**/
