#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findKthLargest2(vector<int>& nums, int k) {
        size_t N = nums.size();
        if (N < 2) return nums[0];
        heaplify(nums, N);
        unsigned int end = N - 1;
        for (unsigned int i = 0; i < k; ++i) {
            swap(nums[0], nums[end]);
            end--;
            percolate(nums, 0, end);
        }
        return nums[N - k];
    }
    void heaplify(vector<int>& nums, size_t count) {
        int start = (count - 2) / 2;
        for (; start >= 0; start--) {
            percolate(nums, start, count - 1);
        }
    }
    // MaxHeap
    void percolate(vector<int>& nums, size_t root, size_t end) {
        for (; root* 2 + 1 <= end; ) {
            size_t child = root * 2 + 1;
            if (child + 1 <= end && nums[child] < nums[child+1])
                child = child+1;
            if (nums[root] < nums[child]) {
                swap(nums[root], nums[child]);
                root = child;
            } else {
                return;
            }
        }
    }
        
    int findKthLargest3(vector<int>& nums, int k) {
        nth_element(begin(nums), begin(nums) + k - 1, end(nums), greater<int>());
        return nums[k-1];
    }
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pq(begin(nums), end(nums));
        int ans;
        for (int i = 0; i < k; ++i) {
            ans = pq.top();pq.pop();
        }
        return ans;
    }
};


int main()
{
    /* vector<int> nums = {3,2,1,5,6,4};
    int k = 2; */
    vector<int> nums = {2,1};
    int k = 2;
    Solution s;
    cout << s.findKthLargest2(nums, k) << '\n';
    return 0;
}