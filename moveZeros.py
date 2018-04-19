class Solution:
    def moveZeros(self, nums):
        i = 0
        l = len(nums)
        while i < l - 1:
            if nums[i] == 0:
                j = i + 1
                while j < l:
                    if nums[j] != 0:
                        nums[i] = nums[j]
                        nums[j] = 0
                        break
                    else:
                        j += 1
                i += 1
            else:
                i += 1

if __name__ == '__main__':
    solver = Solution()
    nums = [0, 1, 0, 3, 12]
    solver.moveZeros(nums)
    print(nums)
    

