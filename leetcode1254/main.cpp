#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int dir[4][2] = {{1,0},{0,1},{-1,0},{0,-1}};
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != 0 || (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) ) continue;
                vector<pair<int,int>> cache;
                cache.emplace_back(i, j);
                bool flag = true;
                while (cache.size() > 0) {
                    auto tmp = cache.front();
                    cache.erase(cache.begin());
                    for (int k = 0; k < 4; ++k) {
                        int x = tmp.second + dir[k][0];
                        int y = tmp.first + dir[k][1];
                        if (grid[y][x] == 0) {
                            if (1 <= x && x < cols - 1 && 1 <= y && y < rows - 1) {
                                cache.emplace_back(y, x);
                                grid[y][x] = 2;
                            }
                            else {
                                // cache.clear();
                                flag = false;
                                // break;
                            }
                        }
                    }
                }
                if (flag)
                {
                    ans += 1;
                    #ifdef DEBUG
                    cout << "(" << i << "," << j <<")" << endl;
                    #endif
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> grid {{0,0,1,1,0,1,0,0,1,0},{1,1,0,1,1,0,1,1,1,0},{1,0,1,1,1,0,0,1,1,0},{0,1,1,0,0,0,0,1,0,1},{0,0,0,0,0,0,1,1,1,0},{0,1,0,1,0,1,0,1,1,1},{1,0,1,0,1,1,0,0,0,1},{1,1,1,1,1,1,0,0,0,0},{1,1,1,0,0,1,0,1,0,1},{1,1,1,0,1,1,0,1,1,0}};
    cout << s.closedIsland(grid) << endl;
    return 0;
}