#include "cbinaryheap.h"
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define MinPQsize (10)
#define MinData (-32767)
#define FatalError(M) fprintf(stderr, "Fatal Error %s:%d: " M "\n", __FILE__, __LINE__)

struct HeapStruct {
  int Capacity;
  int Size;
  ElementType *Elements;
};

PriorityQueue Initialize(int MaxElements) {
  PriorityQueue H;

  if (MaxElements < MinPQsize)
    FatalError("Priority queue size is too small");
  H = malloc(sizeof ( struct HeapStruct));
  if (H == NULL)
    FatalError("Out of space!!!");
  /* Allocate the array plus one extra for sentinel */
  H->Elements = malloc((MaxElements + 1) * sizeof ( ElementType));
  if (H->Elements == NULL)
    FatalError("Out of space!!!");
  H->Capacity = MaxElements;
  H->Size = 0;
  H->Elements[ 0 ] = MinData;
 
  return H;
}

void MakeEmpty(PriorityQueue H) {
  H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H) {
  int i;

  if (isFull(H)) {
    FatalError("Priority queue is full");
    return;
  }

  for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
    H->Elements[i] = H->Elements[i / 2];
  H->Elements[i] = X;
}

ElementType DeleteMin(PriorityQueue H) {
  int i, Child;
  ElementType MinElement, LastElement;

  if (isEmpty(H))
    FatalError("Priority queue is empty");

  MinElement = H->Elements[1];
  LastElement = H->Elements[H->Size--];

  for (i = 1; i * 2 <= H->Size; i = Child) {
    /* Find smaller child */
    Child = i * 2;
    if (Child != H->Size && H->Elements[ Child + 1] < H->Elements[Child])
      Child++;

    /* Percolate one level */
    if (LastElement > H->Elements[ Child ])
      H->Elements[ i ] = H->Elements[ Child ];
    else
      break;
  }

    H->Elements[ i ] = LastElement;
    return MinElement;
}

ElementType FindMin(PriorityQueue H) {
  if (!isEmpty(H))
    return H->Elements[ 1 ];
  FatalError("Priority queue is empty");
  return H->Elements[ 0 ];
}

int isEmpty(PriorityQueue H) {
  return H->Size == 0;
}

int isFull(PriorityQueue H) {
  return H->Size == H->Capacity;
}

void Destroy(PriorityQueue H) {
  free(H->Elements);
  free(H);
}
