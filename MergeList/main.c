#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void insert_sort(int *nums, int size) {
    for (int i = 0; i < size - 1; i++) {
        if ( *(nums+i) > *(nums+i+1)) {
           swap((nums+i), (nums+i+1)); 
        }
    }
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i = 0, j = 0;
    while (i < m) {
        if ( *(nums1 + i) > *(nums2)) {
           swap((nums1 + i), (nums2));
        }
        
        insert_sort(nums2, nums2Size);
        
        i++;
    }
    
    while (j < n) {
        *(nums1+j+m) = *(nums2+j);
        j++;
    }
}

int main()
{
    int nums1[6] = {1,2,3,0,0,0};
    int nums2[3] = {2, 5, 6 };
    //int nums3[6] = {6,1,2,3,4,5};
    /**/
    merge(nums1, 6, 3, nums2, 3, 3);
    for (int x = 0; x < 6; x++) {
        printf("%d ", *(nums1+x));
    }
    /**
    insert_sort(nums1, 6);
    for (int x = 0; x < 6; x++) {
        printf("%d ", *(nums1+x));
    }
    **/

    return 0;
}