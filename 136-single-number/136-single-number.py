class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        ayu=0
        for i in nums:
            ayu^=i
        return ayu
    