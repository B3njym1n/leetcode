#include <stdio.h>

int main(int argc, char *argv[])
{
  int arr[] = {2, 7, 11, 15};
  int numsSize = 4;
  int target = 9;
  twoSum(&arr, numsSize, target);
  return 0;
}

int twoSum(int* nums, int numsSize, int target)
{
  int i = 0;
  for(;i < numsSize-1; i++)
    {
      int j = i + 1;
      for(;j < nums; j++)
	{
	  if ((nums[i] + nums[j]) == target)
	    {
	      printf("%d, %d", i, j);
	    }
	  j++;
	}
      i++;
    }
}
