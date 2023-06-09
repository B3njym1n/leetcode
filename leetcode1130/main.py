from typing import List

class Solution:
    def mctFromLeafValues(self, arr: List[int]) -> int:
        ans = 0
        while len(arr) > 1:
            i = arr.index(min(arr))
            ans += min(arr[i-1: i] + arr[i+1: i+2]) * arr.pop(i)
        
        return ans

if __name__ == '__main__':
    s = Solution()
    arr = [6,2,4,1]
    ans = s.mctFromLeafValues(arr)
    print(ans)