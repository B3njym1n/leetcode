from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = []
        nums.sort()
        for i in range(len(nums)):
            if i != 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            k = len(nums) - 1
            for j in range(i+1, len(nums)):
                if j != i + 1 and nums[j] == nums[j - 1]:
                    continue
                while k > j and nums[k] + nums[j] > target:
                    k -= 1
                if k <= j:
                    break
                if nums[j] + nums[k] == target:
                    res.append([nums[i], nums[j], nums[k]])
                    
        return res

    def twoSum(self, nums: List[int], k) -> List[List[int]]:
        res = []
        d = dict([(e, i) for i, e in enumerate(nums)])
        for i, e in enumerate(nums):
            if d.get(k - e):
                if i != d.get(k -e):
                    tmp = [nums[i], nums[d.get(k-e)]]
                    res.append(tmp)

        return res
