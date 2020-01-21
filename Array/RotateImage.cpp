/**
Description:
	You are given an nxn 2D matrix representing an image
	Rotate the image by 90 degree (clockwise)
	Follow up. Could you do this in-place?
**/

#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>> &matrix) {
		const int n = matrix.size();

		//
		for (int i = 0; i < n / 2; i++)
			for (int j = 0; j < n; ++j)
				swap(matrix[i][j], matrix[n - 1 - i][j]);
		// 
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; ++j)
				swap(matrix[i][j], matrix[j][i]);


	}
};

int main()
{
	vector<vector<int>> matrix = {{1, 2}, {3, 4}};
	Solution s;
	s.rotate(matrix);
	for (vector<int> row : matrix) {
		for (int el : row) {
			cout << el << ", ";
		}
		cout << endl;
	}
	return 0;
}
