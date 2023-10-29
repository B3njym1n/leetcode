#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
	int maximalNetworkRank(int n, vector<vector<int>>& roads)
	{
		vector<int> degree(n, 0);
		vector<vector<bool>> connected(n, vector<bool>(n, false));
		for (vector<int> road : roads)
		{
			connected[road[0]][road[1]] = true;
			connected[road[1]][road[0]] = true;
			degree[road[0]] += 1;
			degree[road[1]] += 1;
		}
		int maxRank = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				int rank = degree[i] + degree[j] - (connected[i][j] ? 1 : 0);
				maxRank = max(maxRank, rank);
			}
		}
		return maxRank;
	}
};

int main()
{
	vector<vector<int>> roads = { {0,1}, {0,3}, {1,2}, {1,3}, {2,3}, {2,4} };
	int n = 5;
	Solution solution;
	cout << solution.maximalNetworkRank(n, roads);
	return 0;
}