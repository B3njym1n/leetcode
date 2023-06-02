class Solution:
    def twoSum(self, nums, target):
        
        return None

    def qsort(self, start, end, nums):
        if start < end:
            i, j = start, end
            pivot = nums[i]
            while i < j:
                while i < j and nums[j] > pivot:
                    j -= 1
                nums[i] = nums[j]
                
                while i < j and nums[i] < pivot:
                    i += 1
                nums[j] = nums[i]
                
            nums[i] = pivot

            self.qsort(start, i-1, nums)
            self.qsort(j+1, end, nums)


if __name__ == '__main__':
    s = Solution()
    nums = [19, 1, 8, 29, 24, 4, 13, 7, 25]
    s.qsort(0, len(nums)-1, nums)
    print(nums)
