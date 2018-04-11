class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        l = len(digits)
        i = -1
        while i > -l:
            if digits[i] + 1 > 9:
                digits[i] = 0
                i -= 1
            else:
                digits[i] = digits[i] + 1
                break

        if i == -l and digits[i] + 1 > 9:
            digits[i] = 0
            digits.insert(0,1)
        else:
            digits[i] = digits[i] + 1

if __name__ == '__main__':
    digits = [0]
    s = Solution()
    s.plusOne(digits)
    print(digits)
