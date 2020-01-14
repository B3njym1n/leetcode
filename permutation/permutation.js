/**
 * Given a collection of distinct integers, return all possible permutations
 */
var swap = function(nums, m, n)
{
    tmp = nums[m];
    nums[m] = nums[n];
    nums[n] = tmp;
}

var permutation = function(nums, i, len, results)
{
    if (i == len )
    {// end
        let res = [...nums];
        results.push(res);
        return ;
    }
    for (let j = i; j < len; j++)
    {
        swap(nums, i, j);
        if (i != j) swap(nums, i+1, j);
        permutation(nums, i + 1, len, results);
        if (i != j) swap(nums, i+1, j);
        swap(nums, i, j);
    }
}

var permute = function(nums)
{
    let len = nums.length;
    let results = [];
    permutation(nums, 0, len, results);
    return results;
}

arr = [1,2,3];
console.log(permute(arr));
