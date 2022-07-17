class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        nr=Counter(nums1)
        result=[]
        for n in nums2:
            if nr[n]>0:
                result.append(n)
                nr[n]-=1
        return result