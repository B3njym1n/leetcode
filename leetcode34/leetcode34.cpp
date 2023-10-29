#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret;
        int first = bSearch(target, nums, true);
        int last = bSearch(target, nums, false);
        ret.push_back(first);
        ret.push_back(last);
        return  ret;
    }

  int bSearch(int target, vector<int>& nums, bool first)
  {
    int left = 0;
    int right = nums.size();
    int ret = -1;
    while (left < right)
      {
        int mid = (left + right) >> 1;
        if (target < nums[mid])
          {
            right = mid;
          }
        else if (target > nums[mid])
          {
            left = mid + 1; 
          }
        else
          {
            ret = mid;
            if (first)
              {
                right = mid;
              }
            else
              {
                left = mid+1;
              }
          }
      }
    return ret; 
  }
};

int main()
{
    vector<int> l = {5,7,7,8,8,10};
    // vector<int> l = {1};
    Solution s;
    vector<int> ret = s.searchRange(l, 8);
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}
