#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  string convert(string s, int numRows)
  {
    if (numRows < 2 || numRows >= s.size())
      {
        return s;
      }
    vector<string> grid(numRows, "");
    string ret = "";
    int h = 0;
    // like wave have period up and down
    int period = numRows*2 - 2;
    for (int i = 0; i < s.size();i++)
      {
        grid[h] += s[i];
        if (i % period < numRows - 1)
          {
            h++;
          }
        else
          {
            h--;
          }
      }

    for (string row :grid)
      {
        ret += row;
      }
    return ret;
  }
};

int main()
{
  string s = "PAYPALISHIRING";
  int numRows = 3;
  Solution solution;
  cout << solution.convert(s, numRows) << endl;
  return 0;
}
