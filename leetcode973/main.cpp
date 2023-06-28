#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        nth_element(begin(points), begin(points) + k - 1, end(points), [](const vector<int>& p1, const vector<int>& p2) {
            return p1[0] * p1[0] + p1[1] * p1[1] < p2[0] * p2[0] + p2[1]*p2[1];
        });
        
        return {begin(points), begin(points) + k};
    }
};

int main()
{
    // vector<vector<int>> points {{1,3},{-2,-2}};
    // int k = 1;
    vector<vector<int>> points {{3,3},{5,-1},{-2,4}};
    int k = 2;
    Solution s;
    auto ans = s.kClosest(points, k);
    for (auto p : ans) {
        cout << p[0] << ',' << p[1] << '\n';
    }
    return 0;
}