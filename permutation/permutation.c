#include <stdio.h>
#include <stdlib.h>
/* Using Backtracing */
/* Function to find all permutations of a given
 * string[i..size-1]
 * containing all distinct characters */
void permutation(char str[], int i, int size);
void swap(char *a, char *b);

int main() {
  char a[5] = "abcde";
  permutation(a, 0, 5);
  
  return 0;
}

void permutation(char str[], int i, int size) {
  // base condition
  if (i == size - 1) {
    printf("%s\n", str);
    return ;
  }

  for (int j = i; j < size; j++) {
    swap(str+i, str+j);
    permutation(str, i+1, size);
    swap(str+i, str+j);
  }
}

void swap(char *a, char *b) {
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

