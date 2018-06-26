class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        一个整数和它本身异或之后得到值是0，0与其他整数异或得到的是这个整数本身
        """
        r = 0
        for i in nums:
            r = r ^ i
        return r

if __name__ == '__main__':
    s = Solution()
    nums = [2,2,1]
    r = s.singleNumber(nums)
    print(r)

