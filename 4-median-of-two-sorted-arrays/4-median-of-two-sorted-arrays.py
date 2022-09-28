class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        merged_array = sorted(nums1+nums2)
        mid = int(len(merged_array)/2)
        if len(merged_array)%2==0:
            return (merged_array[mid] + merged_array[mid-1])/2
        else:
            return merged_array[mid]