from typing import List


# bruteforce
# class Solution:
#     def maxArea(self, height: List[int]) -> int:
#         n =len(height)
#         return  max([(y-x) * min(height[y], height[x])  for x in range(0, n -1) for y in range(x, n)])


class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        return self.recur(height, 0, n-1)

    def recur(self, height: List[int], l, r) -> int:
        if (r - l) == 1: return min(height[l], height[r])
        area = (r - l) * min(height[l], height[r])
        maxBefore = self.recur(height, l, r - 1) if height[l] > height[r] else self.recur(height, l + 1, r)
        return max(area, maxBefore)
