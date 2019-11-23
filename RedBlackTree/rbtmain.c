#include "rbt.h"
#include <stdio.h>

#define N 800

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

  int max = maxDepth(T);
  int min = minDepth(T);
  printf("Max Depth is %d", max);
  printf("Min Depth is %d", min);
  printf("\n");
  preorderTraverse(T);
  for (int i = 1; i <= max+4; i++) {
    LevelTraverse(T, i);
    printf("\n");
  }
  // printf("Min is %d, Max is %d\n", Retrieve(FindMin(T)), Retrieve(FindMax(T)));

  return 0;
}
