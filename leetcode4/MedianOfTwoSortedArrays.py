from typing import List


class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        """ Return the median of two sorted arrays
        >>> s = Solution()
        >>> s.findMedianSortedArrays([1,2], [3,4])
        2.5
        >>> s.findMedianSortedArrays([1,3], [2])
        2
        >>> s.findMedianSortedArrays([100000],[100001])
        100000.5
        """
        median = 0.0
        lowerlimit = -10**7
        upperlimit = 10**7
        if len(nums1) > len(nums2):
            return self.findMedianSortedArrays(nums2, nums1)
        total_size = len(nums1) + len(nums2)
        smaller_half = total_size // 2
        low = 0
        high = len(nums1)
        
        while low <= high:
            d1 = (low + high) // 2
            d2 = smaller_half - d1
            biggestLeft1 = nums1[d1-1] if d1 > 0 else lowerlimit
            smallestRight1 = nums1[d1] if d1 < len(nums1) else upperlimit
            biggestLeft2 = nums2[d2-1] if d2 > 0 else lowerlimit
            smallestRight2 = nums2[d2] if d2 < len(nums2) else upperlimit
            if biggestLeft1 > smallestRight2:
                high = high -1
            elif biggestLeft2 > smallestRight1:
                low = low + 1
            else:
                if total_size % 2 == 0:
                    median = (max(biggestLeft1, biggestLeft2) + min(smallestRight1, smallestRight2)) / 2
                else:
                    median = min(smallestRight1, smallestRight2)
                break
            
        return median
    
if __name__ == '__main__':
    # s = Solution()
    import doctest
    doctest.testmod()