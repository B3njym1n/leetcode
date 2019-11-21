#include "rbt.h"
#include <stdio.h>

#define N 8

int main() {
  RedBlackTree T;
  Position P;
  int i;
  int j = 0;

  T = Initialize();
  T = MakeEmpty(T);

  for (i = 0; i < N; i++, j = (j + 7) % N)
    T = Insert(j, T);

  printf("Insertion complete\n");

  for (i = 1; i < N; i++) {
    if (( P = Find(i, T)) == NULL || Retrieve(P) != i)
      printf("Error at %d\n", i);
  }

  preorderTraverse(T);
  printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)), Retrieve(FindMax(T)));

  return 0;
}
