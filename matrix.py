class Solution:
    """Documentation for Solution
    :type matrix: List[List[int]]
    :rtype: void Do not return anythin, modify matrix in-place instead
    """
    
    def rotate(self, matrix):
        n = len(matrix)
        round = n//2
        for i in range(round):
            for j in range(i, n - 1 - i):
                temp = matrix[i][j]
                # move values from left to top
                matrix[i][j] = matrix[n-1-j][i]
                # move values from bottom to left
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j]
                # move values from right to bottom
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i]
                # assign temp to right
                matrix[j][n-1-i] = temp


if __name__ == '__main__':
    s = Solution()
    m = [
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
]
    print("original matrix: ")
    for r in m:
        print(r)
    s.rotate(m)
    print("rotated matrix: ")
    for r in m:
        print(r)
