class Solution:
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        һ�����������������֮��õ�ֵ��0��0�������������õ����������������
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

