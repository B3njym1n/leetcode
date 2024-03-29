from typing import List

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        """
        >>> nums = [3,6,5,1,8]
        >>> s = Solution()
        >>> s.maxSumDivThree(nums)
        18
        """
        f = [0, -float('inf'), -float('inf')]        
        for num in nums:
            g = f[:]
            for i in range(3):
                g[(i + num % 3) % 3] = max(g[(i + num % 3) %3], f[i] + num)
            f = g

        return f[0]
