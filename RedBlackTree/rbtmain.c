#include "rbt.h"
#include <stdio.h>

#define MAX 20

int main() {
  RedBlackTree T = Initialize();
  Position P;
  int i;
  int j = 0;

  for (i = 0; i < MAX; i++, j = (j + 7) % MAX)
    T = Insert(j, T);

  printf("Insertion complete\n");
  
  PrintTree(T, 0, 0);

  for (i = 1; i < MAX; i++) {
    if (( P = Find(i, T)) == NULL || Retrieve(P) != i)
      printf("Error at %d\n", i);
  }
  return 0;
}
