#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

// bottom up merge sort

void merge_sort_bu(int target[], int aux[], int size);
void _merge(int target[], int aux[], int left, int mid ,int right);
void swap(int* p1, int* p2);
void display(int a[], const int size);

int main() {
  int aux[SIZE];
  int target[SIZE] = { 2, 0, 9, 1, 3, 8, 4, 5, 7, 6};
  display(target, SIZE);
  merge_sort_bu(target, aux, SIZE);
  return 0;
}

void merge_sort_bu(int target[], int aux[], int size)
{
  int scale;
  for (scale = 1; scale < size; scale*=2)
  {
    for (int i = 0; i < size - 1; i += 2*scale)
    {
      int left = i; 
      int right= ((i + 2*scale - 1) > size - 1) ? size - 1 : (i + 2*scale - 1);
      printf("left %d, right %d\n", left ,right);
      _merge(target, aux, left, left+scale - 1, right); 
      display(target, SIZE);
    }
  }
}

void _merge(int target[], int aux[], int left, int mid ,int right)
{
  if (left < right)
  {
    int k = mid + 1;
    int j = left;
    int i ;
    for (i = left; i <= right; i++) {
      if (j <= mid) {
        if (target[j] < target[k] || k > right) {
          aux[i] = target[j];
          j++;
        } else {
          aux[i] = target[k];
          k++;
        }
      } else {
        aux[i] = target[k];
        k++;
      }
    }

    for (i = left; i <= right; i++) 
    {
      target[i] = aux[i];
    }
  }

}

void swap(int* p1, int* p2) {
  int tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void display(int a[], const int size) {
  int i;
  for (i = 0 ; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
