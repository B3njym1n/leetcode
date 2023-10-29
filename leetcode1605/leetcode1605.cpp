#include <iostream>
#include <vector>


using namespace std;

class Solution
{
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum)
  {
    int rowSize = rowSum.size();
    int colSize = colSum.size();

    vector<vector<int>> r(rowSize, vector<int>(colSize));
    int y = 0;
    int x = 0;
    while (y < rowSize && x < colSize)
      {
	int v  = min(rowSum[y], colSum[x]);
	r[y][x] = v;
	rowSum[y] -= v;
	colSum[x] -= v;
	if (rowSum[y] == 0)
	  {
	    y += 1;
	  }
	if (colSum[x] == 0)
	  {
	    x += 1;
	  }
      }
	    
      
    return r;
  }
};

int main()
{
  Solution solution;
  vector<int> rowSum = {3,8};
  vector<int> colSum = {4,7};
  auto r = solution.restoreMatrix(rowSum, colSum);
  for (vector<int> row : r)
    {
      for(auto c : row)
	{
	  cout << c << ",";
	}
      cout << endl;
    }
  return 0;
}
