class Solution:
  def intersect(self, nums1, nums2):
    if(len(nums1) > len(nums2)):
      return list(filter(lambda x:x in nums2, nums1))
    else:
      return list(filter(lambda x:x in nums1, nums2))

def str2int(nums):
  for s in nums:
    return int(s)

if __name__ == '__main__':
  solution = Solution()
  nums1 = input('nums1: ')
  nums2 = input('nums2: ')
  nums1 = nums1.split(',')
  nums1 = list(map(str2int, nums1))
  nums2 = nums2.split(',')
  nums2 = list(map(str2int, nums2))
  print(nums1)
  print(nums2)

  result = solution.intersect(nums1, nums2)
  print(result)
