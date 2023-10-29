#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
  int minSubarray(vector<int>& nums, int p)
  {
    int len = nums.size();
    int x = 0;
    for (int i = 0; i < len; i++)
      {
	int num = nums[i];
	x = (x + num) % p;
      }
    if (x==0)
      {
	return 0;
      }
    unordered_map<int, int> index;
    int y = 0, res = nums.size();
    for (int i = 0; i < len; i++)
      {
	index[y] = i;
	y = (y + nums[i])%p;
	if (index.count((y-x+p)%p) >0)
	  {
	    res = min(res, i - index[(y - x + p)%p]+1);
	  }
      }
    return res == nums.size() ? - 1 : res;
  }
};

int main()
{
  Solution s;
  vector<int> nums = {3,1,4,2};
  int output = s.minSubarray(nums, 6);
  cout << output << endl;
  return 0;
}
