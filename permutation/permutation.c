#include <stdio.h>
#include <stdlib.h>
/* Using Backtracing */
/* Function to find all permutations of a given
 * string[i..size-1]
 * containing all distinct characters */
void permutation(char str[], int i, int size);
void swap(char *a, char *b);
void shift(char str[], int index, int end);

int main() {
  char a[3] = "abc";
  permutation(a, 0, 3);
  
  return 0;
}

void permutation(char str[], int i, int size) {
  // base condition
  if (i == size - 1) {
      printf("%s\n", str);
      return;
  }
  for (int j = i; j < size; j++) {
    swap(str + i, str + j);
    if ( i != j) swap(str + j, str + i+1);
    permutation(str, i+1, size);
    if ( i != j) swap(str + j, str + i+1);
    swap(str + i, str + j);
  }
}

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

void shift(char str[], int index, int end)
{
  char tmp =  *(str + index);
  for (int i = index; i < end; i++)
    {
      *(str+i) = *(str+i+1);
    }
  *(str+end) = tmp;
}
