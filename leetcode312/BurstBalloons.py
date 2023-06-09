import functools
from typing import List


class Solution:
    def maxCoins(self, nums: List[int]) -> int:
        """Return the maximum coins you can collect by bursting the balloons wisely.
        >>> s = Solution()
        >>> s.maxCoins([3,1,5,8])
        167
        """
        A = [1] + nums + [1]
        
        @functools.lru_cache(None)
        def dp(i:int, j:int)->int:
            if i > j:
                return 0
            return max(dp(i, k-1) + dp(k+1,j) + A[i-1]*A[k]*A[j+1] for k in range(i, j+1))
        
        return dp(1, len(nums))
    
if __name__ == '__main__':
    import doctest
    doctest.testmod()