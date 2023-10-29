#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        vector<int>::const_iterator a = height.cbegin();
        vector<int>::const_iterator b = height.cend();
        b--;
        while (a < b)
        {
            int area = min(*a, *b)*(b - a);
            if (area > max) max = area;
            if (*a < *b)
            {
                a++;
            }
            else
            {
                b--;
            }
        }
        return max;
    }
};

int main()
{
    vector<int> Input = {1,8,6,2,5,4,8,3,7};
    Solution s;
    cout << s.maxArea(Input) << endl;
}