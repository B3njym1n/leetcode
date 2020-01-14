
/**
 * find longest ascend seq from tail to head;
 * then reverse it and swap the element ahead
 * of it with smallest element of the it which
 * is greater than the element at the same time
 */
var nextPermutation = function(nums) {
    let length = nums.length;
    if (length < 2) return;
    // find 
    let i = length - 1;
    let j = length - 2;
    while (nums[j] > nums[i])
    {
        i--;
        j--;
    }
    // reverse
    let k = length - 1;
    while ( i < k )
    {
        tmp = nums[k];
        nums[k] = nums[i];
        nums[i] = tmp;
        i++;
        k--;
    }
    i = j + 1;
    if (i == 0) return;
    while (nums[i] <= nums[j] && i < length)
    {
        i++;
    }

    tmp = nums[j];
    nums[j] = nums[i];
    nums[i] = tmp;
}

arr = [1, 5 ,1];
nextPermutation(arr);
console.log(arr);
