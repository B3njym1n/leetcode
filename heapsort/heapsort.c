#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef int (*compare_func)(int, int);
int compare(int a, int b);
void heap_sort(int a[], compare_func func_pointer, int len);
void display(int a[], const int size);

int main() {
  int a[SIZE] = {8, 5, 2, 3, 1, 6, 9, 4, 0, 7};

#ifdef _DEBUG
  display(a, SIZE);
#endif
  heap_sort(a, compare, SIZE);

#ifdef _DEBUG
  display(a, SIZE);
#endif
  return 0;
}

int compare(int a, int b) {
  if (a > b)
    return 1;
  else if (a < b)
    return -1;
  else
    return 0;
}

void heap_sort(int a[], compare_func func_pointer, int len)
{
  int half;
  int parents;
  if (len < 2)
    return;
  half = len >> 1;
  for (parents = half; parents >= 1; --parents)
  {
    int tmp;
    int level = 0;
    int child;

    child = parents;
    /* bottom-up downheap */

    /* leaf-search for largest child path */
    while (child <= half)
    {
      ++level;
      child += child;
      if ((child < len) && ((*func_pointer)(a[child], a[child - 1]) > 0))
        child++;
    }
    
    /* bottom-up-search for rotation point */
    tmp = a[parents - 1];
    for (;;)
    {
      if (parents == child)
        break;
      if ((*func_pointer)(tmp, a[child - 1]) <= 0)
        break;
      child >>= 1;
      --level;
    }

    for (; level > 0; --level) {
      a[(child >> level) - 1] = a[(child >> (level - 1)) - 1];
    }
    a[child - 1] = tmp;
  }

  --len;
  do {
    int tmp;
    int level = 0;
    int child;

		/* move max element to back of array */
		tmp = a[len];
		a[len] = a[0];
		a[0] = tmp;
		
		child = parents = 1;
		half = len >> 1;

		/* bottm-up downheap */
		/* leaf-search for largest child path */
		while (child <= half) {
			++level;
			child += child;
			if ((child < len) && ((*func_pointer)(a[child], a[child-1])>0))
				++child;
		}
		/* bottom-up-search for rotation point */
		 for (;;)
    {
      if (parents == child)
        break;
      if ((*func_pointer)(tmp, a[child - 1]) <= 0)
        break;
      child >>= 1;
      --level;
    }

		for (; level > 0; --level) {
			a[(child >> level) - 1] = a[(child>> (level-1)) - 1];
		}
		a[child - 1] = tmp;
  }
	while (--len >= 1);
}

void display(int a[],const int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ",a[i]);
 
    printf("\n");
}
