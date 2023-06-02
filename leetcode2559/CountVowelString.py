#! /usr/bin/env python3

from itertools import accumulate
from typing import List


class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = {'a','e','i','o','u'}
        f = lambda s: 1 if s[0] in vowels and s[len(s)-1] in vowels else 0
        preSum = [f(x) for x in words]
        for i in range(1, len(preSum)):
            preSum[i] = preSum[i-1] + preSum[i]
        
        ans = []
        for i in range(len(queries)):
            l = queries[i][0]-1
            r = queries[i][1]
            ans.append(preSum[r] - (preSum[l] if l > - 1 else 0))
        return ans
    
class Solution2:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        s = list(accumulate((w[0] in "aeiou" and w[-1] in "aeiou" for w in words), initial=0))
        return [s[r + 1] - s[l] for l, r in queries]

if __name__ == '__main__':
    s = Solution()
    print(s.vowelStrings(["aba","bcb","ece","aa","e"], [[0,2],[1,4],[1,1]]))