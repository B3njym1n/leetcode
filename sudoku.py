class Solution:
    def isValidSudoku(self, board):
        # row checking
        r = 0
        while r < 9:
            row = board[r]
            if not self.check(row):
                return False
            r += 1

        # column checking
        c = 0
        while c < 9:
            col = []
            for i in range(9):
                col.append(board[i][c])
            if not self.check(col):
                return False
            c += 1
        # 3x3 checking
        square = 0
        while square < 9:
            block = []
            i = square // 3
            j = square % 3
            for x in range(i*3, i*3+3):
                for y in range(j*3, j*3+3):
                    block.append(board[x][y])

            if not self.check(block):
                return False
            square += 1
        return True

    def check(self, group):
        la = list(filter(lambda x: x != '.', group))
        b = set(la)
        if len(b) < len(la):
            return False
        else:
            return True


if __name__ == '__main__':
    board = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"]
]

    s = Solution()
    if s.isValidSudoku(board):
        print("board is valid soduku")
    else:
        print("borad is not valid soduku")
