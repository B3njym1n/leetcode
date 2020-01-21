#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void heap_sort(int a[], int len);
void display(int a[], const int size);
void fixDown(int a[], int index, int len);

int main() {
  int a[SIZE] = {8, 5, 2, 3, 1, 6, 9, 4, 0, 7};

  display(a, SIZE);

  heap_sort(a, SIZE);

  display(a, SIZE);
  return 0;
}

void fixDown(int a[], int parent, int len) {
  int child ;
  while (parent*2 <= len) {
    child = parent * 2;
    if ( child < len && (a[child-1] <= a[child])) {
      child++;
    }
    if (a[parent - 1] <= a[child - 1]) {
      int tmp = a[parent - 1];
      a[parent - 1] = a[child - 1];
      a[child - 1] = tmp;
    } else {
      break;
    }
    parent = child;
  }
}

void heap_sort(int a[], int len)
{
  for (int parent = len / 2; parent >= 1; parent--)
  {
   fixDown(a, parent, len);
  }
  display(a, SIZE);
  /* turn heap to sorted array */
  while (len > 1) {
    int tmp = a[0];
    a[0] = a[len - 1];
    a[len - 1] = tmp;
    fixDown(a, 1, --len );
  }
}

void display(int a[],const int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);
 
    printf("\n");
}
