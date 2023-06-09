from typing import List
import math

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        sell = 0
        hold = -math.inf
        prev = 0
        for price in prices:
            temp = sell
            sell = max(sell, hold+price)
            hold = max(hold, prev- price)
            prev = temp
        
        return sell

if __name__ == '__main__':
    prices = [1,2,3,0,2]
    s = Solution()
    print(s.maxProfit(prices))