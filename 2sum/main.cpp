/**
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 * The function twoSum should return indices of the two numbers such that
 * they add up to the target, where index1 must be less than index2.
 * Please note that your returned answers are not zero based.
 * You may assume that each input would have exactly one solution
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 **/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        std::vector<int> result;
        std::unordered_map<int, int> mapping;
        for (int i = 0; i < nums.size(); i++) {
            mapping[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); i++) {
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                result.push_back(i + 1);
                result.push_back(mapping[gap] + 1);
                break;
            }
        }
        return result;
    }
};

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    Solution s;
    auto r = s.twoSum(nums, 9);
    for (auto e : r) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
    return 0;
}