class Solution:
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        l = len(digits)
        i = -1
        while i >= -l:
            if digits[i] + 1 > 9:
                digits[i] = 0
                if i == -l:
                    digits.insert(0, 1)
                    break
                i -= 1
            else:
                digits[i] = digits[i] + 1
                break
        return digits

if __name__ == '__main__':
    digits = [9]
    s = Solution()
    r = s.plusOne(digits)
    print(r)
