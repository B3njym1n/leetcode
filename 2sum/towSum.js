/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    possible = nums.filter( x => x < target);
    for ( let i = nums.length - 1; i > 0; i--) {
        for (let j = i - 1; j >= 0; j--) {
            if( nums[i] + nums[j] == target) {
                return [j, i];
            }
        }
    }
};
