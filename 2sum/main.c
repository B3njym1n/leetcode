#include <stdio.h>
#include <stdlib.h>

typedef struct __hinfo {
  int idx;
  int val;
} HINFO;
typedef struct __hash_table {
  int size;
  int mod;
  HINFO **arr;
} HASH;

int hash(HASH *obj, int key)
{
  int r = key % obj->size;
  return r < 0 ? r + obj->size: r;
}

HASH *hash_create(int size)
{
  HASH *obj = malloc(sizeof(HASH));
  obj->size = size;
  obj->arr = malloc(sizeof(HINFO)*(size));
  for (int x = 0; x < size; ++x) {
    HINFO *info = malloc(sizeof(HINFO));
    obj->arr[x] = info;
    info->idx = -1;
  }
  return obj;
}

void 
hash_add(HASH *ht, int key, int idx)
{
  int index = hash(ht, key);
  while (ht->arr[index]->idx != -1) {
    ++index;
    index %= ht->size;
  }
  ht->arr[index]->idx = idx;
  ht->arr[index]->val = key;
}

int
hash_find(HASH *ht, int target)
{
  int index = hash(ht, target);
  while (ht->arr[index]->idx != -1) {
    if (ht->arr[index]->val == target)
      return ht->arr[index]->idx;

    ++index;
    index %= ht->size;
  }
  return -1;
}

void
hash_release(HASH *ht)
{
  for (int i = 0; i < ht->size; ++i) {
    free(ht->arr[i]);
  }
  free(ht->arr);
  free(ht);
}

int *
two_sum(int *sums, int sumSize, int target, int *returnSize)
{
  int *indices = NULL;
  *returnSize = 0;
  HASH *ht = hash_create(sumSize);
  for (int i = 0; i < sumSize; ++i) {
    int complemnts = target - sums[i];
    int index = hash_find(ht, complemnts);
    if (index >= 0) {
      indices = (int *) malloc(sizeof(int) * 2);
      indices[0] = index;
      indices[1] = i;
      *returnSize = 2;
      break;
    }
    hash_add(ht, sums[i], i);
  }

  hash_release(ht);
  return indices;
}

int 
main(int c, char **v)
{
  int nums[] = {2, 7, 5, 11};
  int target = 9;
  int *res;
  int *resSize;
  res = two_sum(&nums, 4, target, resSize);
  printf("returned %d %d", res[0], res[1]);
  return 0;
}
