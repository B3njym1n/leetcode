#! /usr/bin/env python3


from typing import List

import bisect

class Solution:
    def maximumTastiness(self, price: List[int], k: int) -> int:
        price.sort()

        def keyF(m: int) -> bool:
            basket = 0
            prevPrice = -m
            for p in price:
                if p >= prevPrice + m:
                    prevPrice = p
                    basket += 1
            return basket < k

        l = bisect.bisect_left(range(max(price) - min(price)+1), True, key = lambda m: keyF(m))
        return l - 1
    

if __name__ == '__main__':
    s = Solution()
    price = [13,5,1,8,21,2]
    k = 3
    print(s.maximumTastiness(price, k))