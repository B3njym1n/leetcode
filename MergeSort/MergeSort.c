#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

void merge(int a[], int tmp[], int left, int mid, int right);
void msort(int a[], int tmp[], int left, int right);
void merge_sort(int a[], int tmp[], const int size);
void display(int a[], const int size);

int main()
{
  int a[SIZE];
  int tmp[SIZE];
  int i, j = 1;
  for (i = 0; i < SIZE; i++, j = i + j % 7) {
    a[i] = j;
  }
  display(a, SIZE);

  merge_sort(a, tmp, SIZE);

  display(a, SIZE);
  return 0;
}

void merge_sort(int a[], int tmp[], const int size) {
  msort(a, tmp, 0, size - 1);
}

void msort(int a[], int tmp[], int left, int right) {
  int mid;
  if (right > left)
  {
    mid = (left + right) / 2;
    msort(a, tmp, left, mid);
    msort(a, tmp, mid + 1, right);
    merge(a, tmp, left, mid + 1, right);
  }
}

void merge(int a[], int tmp[], int left, int mid, int right) {
  int i, left_end, count, tmp_pos;
  left_end = mid - 1;
  tmp_pos = left;
  count = right - left + 1;

  while ( ( left <= left_end ) && ( mid <= right) ) {
    if (a[left] <= a[mid])
    {
      tmp[tmp_pos] = a[left];
      tmp_pos += 1;
      left +=1;
    }
    else {
      tmp[tmp_pos] = a[mid];
      tmp_pos += 1;
      mid += 1;
    }
  }

  while (left <= left_end)
  {
    tmp[tmp_pos] = a[left];
    left += 1;
    tmp_pos = tmp_pos + 1;
  }

  while (mid <= right)
  {
    tmp[tmp_pos] = a[mid];
    mid += 1;
    tmp_pos = tmp_pos + 1;
  }

  for (i = 0; i <= count; i++ )
  {
    a[right] = tmp[right];
    right -= 1;
  }
}

void display(int a[], const int size) {
  int i;
  for (i = 0 ; i < size; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
