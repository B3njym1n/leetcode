#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        int l = 0;
        int r = *max_element(begin(arr), end(arr));
        int ans = 0;
        auto sum = [&](int v) {
            int _s = 0;
            for (int e : arr) {
                _s += min(v, e);
            }
            return _s;
        };
        while (l < r)
        {
            int m = l + (r- l) / 2;
            if (sum(m) >= target) r = m;
            else l = m + 1;
        }
        return abs(sum(l) -target) < abs(sum(l-1) - target) ? l : l -1;
    }
};

int main() {
    vector<int> arr {4, 9 ,3};
    int target = 10;
    Solution s;
    assert(s.findBestValue(arr, target) == 3);
    return 0;
}