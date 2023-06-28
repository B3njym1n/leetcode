#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(begin(nums), end(nums));
        int ans = 0;
        for (auto v : nums) {
            int length = 1;
            if (s.count(v+1)) continue;
            while (s.count(--v)) ++length;
            ans = max(ans, length);
        }
        return ans;
    }
};

int main()
{
    vector<int> nums {100,4,200,1,3,2};
    Solution s;
    cout << s.longestConsecutive(nums) << endl;
    return 0;
}