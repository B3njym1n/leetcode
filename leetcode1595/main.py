from typing import List
import functools

class Solution:
    def connectTwoGroups(self, cost: List[List[int]]) -> int:
        """
        >>> s = Solution()
        >>> s.connectTwoGroups([[2, 5, 1], [3, 4, 7], [8, 1, 2], [6, 2, 4], [3, 8, 8]])
        10
        """
        size1 = len(cost)
        size2 = len(cost[0])
        dp = [[float('inf')] * (1 << size2) for _ in range(size1 + 1)]
        dp[0][0] = 0
        
        for i in range(size1):
            for s in range(1 << size2):
                for k in range(size2):
                    if s & (1 << k) == 0: continue
                    dp[i+1][s] = min(dp[i+1][s], dp[i+1][s ^ (1<<k)] + cost[i][k])
                    dp[i+1][s] = min(dp[i+1][s], dp[i][s] + cost[i][k])
                    dp[i+1][s] = min(dp[i+1][s], dp[i][s ^ (1 << k)] + cost[i][k])

        return dp[size1][(1 << size2) - 1]