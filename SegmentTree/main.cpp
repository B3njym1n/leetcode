/* A Segement Tree is a data structure that stores information about array intervals as a tree.
This allows answering range queries over an array efficiently, while still beging flexible enough to allow quick modification of the array */

// sum segement tree from codeforce
/* 
|                             1 : [0, 16)                             |
|            2 : [0, 8)         |               3 : [8, 16)           |
|  4 : [0, 4)   |  5 : [4, 8)   |  6 : [8, 12)    |     7 : [12, 16)  |
|       |       |       |       |       |         |         |         |
| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 | 13 | 14 | 15 |
 */
#include <stdio.h>

const int N = 1e5;
int n;
int t[2 * N];

void build() {
    for (int i = n - 1; i > 0; --i) t[i] = t[i<<1] + t[i<<1 | 1];
}

void modify(int p, int value) {
    for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p^1];
}

int query(int l, int r) {
    int res = 0;
    for (l += n, r+= n; l < r; l >>= 1, r >>= 1) {
        if (l&1) res += t[l++];
        if (r&1) res += t[--r];
    }
    return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", t + n + i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  return 0;
}