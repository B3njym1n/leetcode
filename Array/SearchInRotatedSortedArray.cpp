/**
Suppose a sorted array is rotated at some pivot unknown to you beforehand.
(i.e, 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
You are given a target value to search. If found in the array return its index
Otherwise return -1.
You may assume no duplicate exists in the array.
**/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int search(vector<int> &nums, int target) {
		int first = 0, last = nums.size();
		while(first != last) {
			const int mid = first + (last - first) / 2;
			if (nums[mid] == target) return mid;
			if (nums[first] < nums[mid]) {
				if (nums[first] <= target && target < nums[mid]) {
					last = mid;
				} else {
					first = mid + 1;
				}
			} else {
				if (nums[mid] < target && target <= nums[last-1]) {
					first = mid + 1;
				} else {
					last = mid;
				}
			}
		}
		return -1;
	}
};

int main() {
	vector<int> v = { 4, 5, 6, 7, 0, 1, 2 };
	Solution s;
	cout << s.search(v, 6) << endl;
	return 0;	
}
