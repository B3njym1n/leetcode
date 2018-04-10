class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modity nums in-place instread
        """
        r = k % len(nums)
        self.revert(nums, 0, len(nums)-r-1)
        self.revert(nums, len(nums)-r, len(nums)-1)
        self.revert(nums, 0, len(nums) - 1)
        return nums

    def revert(self, arr, m, n):
        i = m
        j = n
        while i < j:
            arr[i], arr[j] = arr[j], arr[i]
            i += 1
            j -= 1


if __name__ == '__main__':
    a = [1,2,3,4,5,6]
    s = Solution()
    print(s.rotate(a,3))
