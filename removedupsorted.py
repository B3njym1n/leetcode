class Solution(object):
    def removeDuplicates(self, nums):
        j = 0
        for i in range(len(nums)):
            if nums[i] != nums[j]:
                nums[i], nums[j+1] = nums[j+1], nums[i]
                j = j+1
        return j+1

if __name__ == '__main__':
    s = [1,1,2,2,2,3,3,3,3,4,4,4,4,4,4,5,5,5,5,5,5,5]
    p = Solution()
    print(p.removeDuplicates(s))
