#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  // too slow
  int maxHelper(int x, int y, vector<vector<int>>& grid)
  {
    if (x == 0 && y == 0)
      {
        return grid[y][x];
      }
    else
      {
        int max = 0;
        if (x > 0)
          {
            int v = maxHelper(x-1,y,grid) + grid[y][x];
            if (v > max) max = v;
          }
        if (y > 0)
          {
            int v = maxHelper(x, y-1, grid) + grid[y][x];
            if (v > max) max = v;
          }
        return max;
      }
  }
  int helper(int w, int h, vector<vector<int>>& grid)
  {
    vector<vector<int>> dp(h, vector<int>(w, 0));
    for (int i = 0; i < h; i++)
      {
        for (int j = 0; j < w; j++)
          {
            if (i > 0)
              {
                dp[i][j] = max(dp[i-1][j], dp[i][j]);
              }
            if (j > 0)
              {
                dp[i][j] = max(dp[i][j-1], dp[i][j]);
              }
            dp[i][j] += grid[i][j];
          }
      }

    return dp[h-1][w-1];
  }
  int maxValue(vector<vector<int>>& grid)
  {
    size_t h = grid.size();
    size_t w = grid[0].size();
    return helper(w, h, grid);
  }
};

int main()
{
  Solution s;
  vector<vector<int>> input = {
    {1,3,1},
    {1,5,1},
    {4,2,1}
    // {1,2,5},
    // {3,2,1}
  };
  int r = s.maxValue(input);
  cout << r << endl;
  return 0;
}
