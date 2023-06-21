from collections import deque
from typing import List


class Solution:
    def flipChess(self, chessboard: List[str]) -> int:
        m = len(chessboard)
        n = len(chessboard[0])
        dir = [[1,0],[1,1],[0,1],[-1,1],[-1,0],[-1,-1],[0,-1],[1,-1]]

        def check(i,j):
            tChessBoard = [list(row) for row in chessboard]
            sum = 0
            q = deque([(i, j)])
            while q:
                i, j = q.popleft()
                for k in range(8):
                    d = dir[k]
                    next_i, next_j = i + d[0], j + d[1]
                    while 0 <= next_i and next_i < m and 0 <= next_j and next_j < n and tChessBoard[next_i][next_j] == 'O':
                        next_i, next_j = next_i + d[0], next_j + d[1]
                    if 0 <= next_i and next_i < m and 0 <= next_j and next_j < n and tChessBoard[next_i][next_j] == 'X':
                        next_i -= d[0]
                        next_j -= d[1]
                        sum += max(abs(next_i - i), abs(next_j -j))
                        while next_i != i or next_j != j:
                            tChessBoard[next_i][next_j] = 'X'
                            q.append((next_i, next_j))
                            next_i -= d[0]
                            next_j -= d[1]
            return sum

        ans = [check(i, j) for i in range(m) for j in range(n) if chessboard[i][j] == '.' ]
        return max(ans) 
    
if __name__ == '__main__':
    s = Solution()
    # chessboard = ["....X.","....X.","XOOO..","......","......"]
    chessboard = [".X.",".O.","XO."]
    # chessboard = [".......",".......",".......","X......",".O.....","..O....","....OOX"]
    print(s.flipChess(chessboard))