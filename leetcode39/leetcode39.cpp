#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
  void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx)
  {
    if (idx == candidate.size())
      {
        return;
      }
    if (target = 0)
      {
        ans.emplace_back(combine);
      }

    dfs(candidates, target, ans, idx+1);
    if (target - candidates[idx]>0)
      {
        combine.emplace_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], ans, combine, idx);
        combine.pop_back();
      }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target)
  {
    vector<vector<int>> res;
    vector<int> combine;
    dfs(candidates, target, res, combine, 0);
    return res;
  }
};

int main()
{
  Solution s;
  vector<int> candidates = {2,3,6,7};
  
  return 0;
}
