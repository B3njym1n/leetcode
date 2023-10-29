#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

size_t bs(vector<int>::const_iterator f, vector<int>::const_iterator l, int target)
{
    auto d = distance(f,l);
    vector<int>::const_iterator m = f + (d >> 1) + 1;
    if (*m == target)
    {
        return d;
    }
    else if (*m > target && m > f)
    {
        return bs(f, m, target);
    }
    else if (*m < target && m < l)
    {
        return bs(m + 1, l, target);
    }
    return -1;
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::const_iterator i = nums.cbegin();
        vector<int>::const_iterator mid;
        while (i + 2 < nums.cend())
        {
            if (*(i+2) - *(i+1) > 0 && *(i+1) - *(i) < 0)
            {
                mid = i+1;
                break;
            }
            i++;
        }
        if (*mid == target)
        {
            return distance(nums.cbegin(), mid);
        }
        if (*mid > target)
        {
            return bs(nums.cbegin(), mid, target);
        }
        if (*mid < target)
        {
            return bs(mid + 1, nums.cend(), target);
        }
    }
};

int main()
{
    Solution s;
    vector<int> input {4,5,6,7,0,1,2};
    cout << s.search(input, 3) << endl;
    return 0;
}