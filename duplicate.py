# -*- coding: utf-8 -*-

class Solution(object):
    def containDuplicate(self, nums):
        """
        : type nums: List[int]
        : rtype bool
        """
        flag = False
        i = 0
        # too slow
        # while i < len(nums):
        #     if nums[0:i+1].count(nums[i]) > 1:
        #         flag = True
        #         break
        #     i += 1
        t = set()
        while i < len(nums) - 1:
            t.add(nums[i])
            i += 1
            if nums[i] in t:
                flag = True
                break

        return flag

if __name__ == '__main__':
    s = Solution()
    nums = [1, 2, 2, 4, 5]
    r = s.containDuplicate(nums)
    print(r)
