class Solution:
    def intersection(self, nums1: List[int], nums2: List[int]) -> List[int]:
        return list({*nums1} & {*nums2})