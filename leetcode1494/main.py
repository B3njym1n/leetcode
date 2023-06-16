
from typing import List

# out of time
class Solution:
    def minNumberOfSemesters(self, n: int, relations: List[List[int]], k: int) -> int:
        """
        >>> s = Solution()
        >>> n = 5
        >>> relations = [[2,1],[3,1],[4,1],[1,5]]
        >>> k = 2
        >>> s.minNumberOfSemesters(n, relations, k)
        4
        """
        # min number of semesters by i mask
        dp =[n+1] * (1 << n)
        # indegree mask each course i
        preq = [0] * n
        for prev, next in relations:
            preq[next - 1] |= 1 << prev - 1
        
        dp[0] = 0
        for i in range(1 << n):
            # mask course
            if dp[i] == n+1: continue
            mask = 0
            for j in range(n):
                if ((i & (1 << j))==0) and (i & preq[j]) == preq[j]:
                    mask |= 1 << j
            if bin(mask).count('1') <= k:
                dp[i | mask] = min(dp[i | mask], dp[i]+1)
            else:
                s = mask
                while s:
                    if (bin(s).count('1') <= k):
                        dp[i | s] = min(dp[i | s], dp[i]+1)
                    s = (s-1) & mask
            if dp[-1] != n+1:
                return dp[-1]
        return dp[-1]
    

if __name__ == '__main__':
    s = Solution()
    print(s.minNumberOfSemesters(11, [[1,2],[2,3],[3,4],[5,8],[5,9],[5,10],[5,11],[6,8],[6,9],[6,10],[6,11],[7,8],[7,9],[7,10],[7,11]],3))